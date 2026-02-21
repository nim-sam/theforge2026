#include <Controller.h>

// ports:
// nav motors: ENA-A0, IN1-2, IN2-3 ; motor2: ENB-A1, IN3-4, IN4-5
// shoot motor: ENA-A2, IN1-6, IN2-7

Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);

  controller.configureL298N(A0, 2, 3, A1, 4, 5); //ENA, IN1, IN2, ENB, IN3, IN4
  controller.setMotorMinPWM(120);
  controller.setFailsafeTimeoutMs(1000);

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


