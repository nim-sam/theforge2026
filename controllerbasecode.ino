#include <Controller.h>
#include <Servo.h>

Servo tilt; // to tilt the system
Servo laserPointer; // for laser pointer

// ports:
// nav motors: LEFT: ENA-A0, IN1-2, IN2-3 ; RIGHT: motor2: ENB-A1, IN3-4, IN4-5
// shoot motor: ENA-A2, IN1-6, IN2-7

int shootMotor1 = 6;
int shootMotor2 = 7;
int tilt = A0;

Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);

  //nav motor configs
  controller.configureL298N(9, 2, 3, 10, 4, 5); //(LEFT) ENA, IN1, IN2, (RIGHT) ENB, IN3, IN4
  controller.setMotorMinPWM(40);
  controller.setFailsafeTimeoutMs(100);

  //shoot motor configs
  pinMode(shootMotor1, OUTPUT);
  pinMode(shootMotor2, OUTPUT);
  pinMode(11, OUTPUT);

  //buttons
  controller.registerButton("SHOOT", shoot);
  controller.registerButton("ANGLE INCREASE", angleUp);
  controller.registerButton("ANGLE DECREASE", angleDown);

  controller.beginAP(true);

  // tilt servo motor
  pinMode(A0, OUTPUT);
}

void loop() {
  controller.update();
}

//button functions
void shoot() {

  Serial.println("shoot button pressed");

  // add shoot function here
  analogWrite(11, 255); //speed
  digitalWrite(6, HIGH); // spin motors
  digitalWrite(7, LOW);
  delay(500);
  digitalWrite(6, LOW); // stop motors
  digitalWrite(7, LOW);
  

}

void angleUp() {
  //add adjust angle function here
  Serial.println("angle increased");
}

void angleDown() {
  //add adjust angle function here
  Serial.println("angle decreased");
}

void onDrive(int8_t left, int8_t right) {
  Serial.print("left: ");
  Serial.print(left);
  Serial.print("right: ");
  Serial.print(right);
}
