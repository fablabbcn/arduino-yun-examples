void sensorLogic() {
  getPredAverLightA();
  getPredAverLightB();


}

void sensorLogicZoneA() {
  float getPredAverLightA();
}


void sensorLogicA() {
  float light = getPredAverLightA();
  if (light < 50) {
    closeAll();
  } else if (light >= 50 && light < 60) {
    // do something middle range
  } else if (light >= 60) {
    openAll();
  }
}




