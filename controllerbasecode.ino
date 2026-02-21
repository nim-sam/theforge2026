#include <Controller.h>
Controller controller("LeBronClanks", "lebron1234");

void setup() {
  Serial.begin(115200);
  controller.beginAP(true);
}

void loop() {
  controller.update();
}
