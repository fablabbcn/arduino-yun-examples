void nitAPI() {
  YunClient client = server.accept(); //check new clients

  if (client) {
    String command = client.readStringUntil('/');  //read the incoming data
    if (command == "skin") {
      Serial.println(command);
      msg = client.readStringUntil('/');             // read the incoming data
      Serial.println(msg);
      int skinID = msg.toInt();
      msg = client.readStringUntil('/');             // read the incoming data
      int skinValue = msg.toInt();
      if (skinValue > 255 / 2) {
        openNitGlobal(skinID);
      } else {
        closeNitGlobal(skinID);
      }
    }
    if (command == "mode") {
      Serial.println(command);
      msg = client.readStringUntil('/');             // read the incoming data
      Serial.println(msg);
      int modeID = msg.toInt();
      if (modeID == 0) {
        setManualMode();
      } else {
        setLightMode();
      }
    }
    client.stop();
  }
}



