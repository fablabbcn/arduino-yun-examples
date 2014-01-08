float voltatgeSource = 5.0;

void writeVoltatge(int outPin, float voltatgeOutput) {

  int value = (voltatgeOutput/voltatgeSource)*255 ;

//  Serial.print(outPin);
//  Serial.print(" ");
//  Serial.print(voltatgeOutput);
//  Serial.print(" ");
//  Serial.print(voltatgeSource);
//  Serial.print(" ");
//  Serial.println(value);
  
  analogWrite(outPin, value);
  
}

void writeLedOn(int outPin) {
  digitalWrite(outPin, HIGH);
}

void writeLedOff(int outPin) {
  digitalWrite(outPin, LOW);
}


void setupAllPins() {
  setupNitPins();
  setupLedPins();
}

void setupNitPins() {
  for (int nitID = 0; nitID <= totalNit; nitID++) {
    pinMode(nitPins[nitID][0], OUTPUT);
    pinMode(nitPins[nitID][1], OUTPUT);
  }
}

void setupLedPins() {
  for (int ledID = 0; ledID <= totalNit; ledID++) {
    pinMode(ledPins[ledID][0], OUTPUT);
    pinMode(ledPins[ledID][1], OUTPUT);
  }
}
