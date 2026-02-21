// const int threshold = 40;
// const int sensorPin = A0;

// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
  
//   long sum = 0;
//   int numSamples = 50;

//   for (int i=0; i < numSamples; i++) {
//     sum += analogRead(sensorPin);
//   }
  
//   float averageVal = (float)sum/numSamples;
//   Serial.print("smooth value:");
//   Serial.println(averageVal);

//   if (averageVal < 25) { //white threshold
//     Serial.println("WHITE");
//   }
//   else if (averageVal < 27) { //green threshold
//     Serial.println("GREEN");
//   }
//   else {
//     Serial.println("OTHER");
//   }

//   delay(100);

// }