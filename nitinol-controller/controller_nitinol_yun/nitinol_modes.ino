boolean manual = true;
boolean  lightsensor = false;

void setManualMode() {
  manual = true;
  lightsensor = false;
}

void setLightMode() {
  manual = false;
  lightsensor = true;
}

void runModes() {
  if (lightsensor == true)   sensorLogicA();
}

