float getPredAverTemp() {
  float temp = getTemp(getAverage(tempSensorPin, 10, 10));
  Serial.print("Temp ");
  Serial.print(temp);
  Serial.println(" *C");
  return temp;
}

float getPredAverLightA() {
  float light = getLight(getAverage(lightASensorPin, 10, 100),75,920);
  Serial.print("Light A ");
  Serial.print(light);
  Serial.println(" %");
  return light;
}

float getPredAverLightB() {
  float light = getLight(getAverage(lightBSensorPin, 10, 100),99,950);
  Serial.print("Light B ");
  Serial.print(light);
  Serial.println(" %");
  return light;
}

float getTemp(int rawADC) {
  return (5.0 * rawADC * 100.0) / 1024;
}

float getLight(int rawADC, int minADC, int maxADC ) {
  return constrain(map(rawADC, minADC, maxADC, 0, 100),0, 100);
}

int getAverage(int sensorPin, int avgNum, int del) {
  int i = 0;
  long sum = 0;
  unsigned int value = 0;
  unsigned int result = 0;

  for (i = 0 ; i < avgNum ; i++)
  {
    value = analogRead(sensorPin);
    sum = sum + value;
    delayMicroseconds(del);
  }
  result = sum / avgNum;
  return (result);


}


