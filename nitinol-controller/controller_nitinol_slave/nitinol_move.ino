void openNitGlobal(int nitID) {
  if (nitID >= totalNit) {
    openNitSlave(nitID);
  } else {
    openNit(nitID);
  }
}

void openNitSlave(int nitID) {
  Serial.print("Open Slave ");
  Serial.println(nitID);
  Wire.beginTransmission(slaveID); // transmit to device
  Wire.write(nitID);              // sends one byte  
  //Wire.write('/n');              // sends one byte  
  Wire.endTransmission();    // stop transmitting
}


void openNit(int nitID) {
  Serial.print("Open ");
  Serial.println(nitID);
  writeVoltatge(nitPins[nitID][0], voltatgeOpen);
  writeVoltatge(nitPins[nitID][1], voltatgeClose);
  writeLedOn(ledPins[nitID][0]);
  writeLedOff(ledPins[nitID][1]);
}


void closeNit(int nitID) {
  Serial.print("Close ");
  Serial.println(nitID);
  writeVoltatge(nitPins[nitID][0], voltatgeClose);
  writeVoltatge(nitPins[nitID][1], voltatgeOpen);
  writeLedOff(ledPins[nitID][0]);
  writeLedOn(ledPins[nitID][1]);
}

void openAll() {
  Serial.println("Start Open ALL");
  for (int nitID = 0; nitID <= totalNit; nitID++) {
    openNit(nitID);
  }
  Serial.println("Done Open ALL");
}

void closeAll() {
  Serial.println("Start Close ALL");
  for (int nitID = 0; nitID <= totalNit; nitID++) {
    closeNit(nitID);
  }
  Serial.println("Done Close ALL");
}

