void openNitGlobal(int nitID) {
  Serial.print("Nit Router ");
  Serial.print(nitID);
  if (nitID >= totalNitLocal) {
    openNitSlave(nitID);
    Serial.println(" Slave");
  } else {
    openNit(nitID);
    Serial.println( "Local");

  }
}

void closeNitGlobal(int nitID) {
  Serial.print("Nit Router ");
  Serial.print(nitID);
  if (nitID >= totalNitLocal) {
    closeNitSlave(nitID);
    Serial.println(" Slave");
  } else {
    closeNit(nitID);
    Serial.println(" Local");

  }
}


void closeNitSlave(int nitID) {
  Serial.println("Close Slave");
  Serial.println("O");              // sends one byte
  Serial.println(nitID);
  Wire.beginTransmission(slaveID); // transmit to device
  Wire.write('C');              // sends one byte
  Wire.write(nitID);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}


void openNitSlave(int nitID) {
  Serial.println("Open Slave");
  Serial.println("O");              // sends one byte
  Serial.println(nitID);
  Wire.beginTransmission(slaveID); // transmit to device
  Wire.write('O');              // sends one byte
  Wire.write(nitID);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}


void openNit(int nitID) {
  Serial.print("Open");
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
  for (int nitID = 0; nitID < totalNitGlobal; nitID++) {
    openNitGlobal(nitID);
  }
  Serial.println("Done Open ALL");
}

void closeAll() {
  Serial.println("Start Close ALL");
  for (int nitID = 0; nitID < totalNitGlobal; nitID++) {
    closeNitGlobal(nitID);
  }
  Serial.println("Done Close ALL");
}

void openAllLocal() {
  Serial.println("Start Open ALL");
  for (int nitID = 0; nitID < totalNitLocal; nitID++) {
    openNit(nitID);
  }
  Serial.println("Done Open ALL");
}

void closeAllLocal() {
  Serial.println("Start Close ALL");
  for (int nitID = 0; nitID < totalNitLocal; nitID++) {
    closeNit(nitID);
  }
  Serial.println("Done Close ALL");
}
