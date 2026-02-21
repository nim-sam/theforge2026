#include <Controller.h>
#include <Servo.h>

// ports:
// nav motors: ENA-A0, IN1-2, IN2-3 ; motor2: ENB-A1, IN3-4, IN4-5
// shoot motor: ENA-A2, IN1-6, IN2-7
int shootMotor1 = 6;
int shootMotor2 = 7;

Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);

  //nav motor configs
  controller.configureL298N(A0, 2, 3, A1, 4, 5); //ENA, IN1, IN2, ENB, IN3, IN4
  controller.setMotorMinPWM(120);
  controller.setFailsafeTimeoutMs(1000);

  //shoot motor configs
  pinMode(shootMotor1, OUTPUT);
  pinMode(shootMotor2, OUTPUT);
  pinMode(A2, OUTPUT);

  //buttons
  controller.registerButton("SHOOT", shoot);
  controller.registerButton("ANGLE INCREASE", angleUp);
  controller.registerButton("ANGLE DECREASE", angleDown);

  controller.beginAP(true);
}

void loop() {
  controller.update();
}

//button functions
void shoot() {
  // add shoot function here
  analogWrite(A2, 100); //speed
  digitalWrite(6, HIGH); // spin motors
  digitalWrite(7, LOW);
  delay(3000);

  Serial.println("shoot button pressed");

}

void angleUp() {
  //add adjust angle function here
  Serial.println("angle increased");
}

void angleDown() {
  //add adjust angle function here
  Serial.println("angle decreased");
}
