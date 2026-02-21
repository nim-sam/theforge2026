#include <Controller.h>
Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);

  controller.configureL298N(9, 7, 6, 10, 5, 4); //ENA, IN1, IN2, ENB, IN3, IN4
  controller.setMotorMinPWM(90);
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


