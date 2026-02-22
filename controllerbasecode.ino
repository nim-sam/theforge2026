#include <Controller.h>
#include <Servo.h>

Servo tilt; // to tilt the wheel
Servo laserPointer; // for laser pointer

// ports:
// nav motors: LEFT: ENA-A0, IN1-2, IN2-3 ; RIGHT: motor2: ENB-A1, IN3-4, IN4-5
// shoot motor: ENA-A2, IN1-6, IN2-7

// motors
int shootMotor1 = 6;
int shootMotor2 = 7;
bool isShooting = false;
bool isUp = false;
bool isDown = false;

// tilt variables
int tiltPin = 3;
int tiltAngle = 95; // arbitrarily set 15 degrees

Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);

  //nav motor configs
  controller.configureL298N(9, 2, 8, 10, 4, 5); //(LEFT) ENA, IN1, IN2, (RIGHT) ENB, IN3, IN4
  controller.setMotorMinPWM(110);
  controller.setFailsafeTimeoutMs(200);

  //shoot motor configs
  pinMode(shootMotor1, OUTPUT);
  pinMode(shootMotor2, OUTPUT);
  pinMode(11, OUTPUT); // which pin is this?

  //buttons
  controller.registerButton("SHOOT", shoot);
  controller.registerButton("ANGLE INCREASE", angleUp);
  controller.registerButton("ANGLE DECREASE", angleDown);

  // tilt servo motor config
  pinMode(A0, OUTPUT);
  
  // Attach the servo object to the pin
  tilt.attach(tiltPin); 
  tilt.write(tiltAngle); // Set initial position
  
  controller.beginAP(false);
}

void loop() {
  controller.update();
}

//button functions
void shoot() {
  Serial.println("shoot button pressed");

  // add shoot function here
  analogWrite(11, 255); //speed
  digitalWrite(shootMotor1, HIGH); // spin motors
  digitalWrite(shootMotor2, LOW);
  
  delay(500); // can be unoptimal
  
  digitalWrite(shootMotor1, LOW); // stop motors
  digitalWrite(shootMotor2, LOW);
}

void angleUp() {
  // add adjust angle function here
  tilt.write(tiltAngle);
  Serial.println("angle increased");
}

void angleDown() {
  //add adjust angle function here
  tilt.write(-tiltAngle);
  Serial.println("angle decreased");
}

//immediately stops robot after letting go of throttle
void onDrive(int8_t left, int8_t right) {
  if (left == 0 && right == 0) {
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW);
    
    analogWrite(9, 255);
    analogWrite(10, 255);
  }
}