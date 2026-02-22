#include <Controller.h>
#include <Servo.h>

// ports:
// nav motors: LEFT: ENA-A0, IN1-2, IN2-3 ; RIGHT: motor2: ENB-A1, IN3-4, IN4-5
// shoot motor: ENA-A2, IN1-6, IN2-7

int shootMotor1 = 6;
int shootMotor2 = 7;
bool isShooting = false;
bool isUp = false;
bool isDown = false;

Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);

  //nav motor configs
  controller.configureL298N(9, 2, 3, 10, 4, 5); //(LEFT) ENA, IN1, IN2, (RIGHT) ENB, IN3, IN4
  controller.setMotorMinPWM(80);
  controller.setFailsafeTimeoutMs(200);

  //shoot motor configs
  pinMode(shootMotor1, OUTPUT);
  pinMode(shootMotor2, OUTPUT);
  pinMode(11, OUTPUT);

  //buttons
  controller.registerButton("SHOOT", shoot);
  controller.registerButton("ANGLE INCREASE", angleUp);
  controller.registerButton("ANGLE DECREASE", angleDown);

  controller.beginAP(false);
}

void loop() {
  controller.registerDriveCallback(onDrive);
  controller.update();
}

//button functions
void shoot() {
  isShooting = !isShooting;

  // add shoot function here
  if (isShooting) {
    analogWrite(11, 255); //speed
    digitalWrite(6, HIGH); // spin motors
    digitalWrite(7, LOW);
  } else {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    analogWrite(11, 0);
  }
}

void angleUp() {
  isUp = !isUp;
  if (isUp) {
    //do something
  } else {
    //turn motor off
  }
}

void angleDown() {
  isDown = !isDown;
    if (isDown) {
    //do something
    } else {
      //turn motor off
    }
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
  } else {
    controller.update();
  }
}