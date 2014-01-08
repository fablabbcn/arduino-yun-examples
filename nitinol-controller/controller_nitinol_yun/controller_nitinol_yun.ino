/*

  _   _ ___ _____ ___ _   _  ___  _                          
 | \ | |_ _|_   _|_ _| \ | |/ _ \| |                         
 |  \| || |  | |  | ||  \| | | | | |                         
 | |\  || |  | |  | || |\  | |_| | |___                      
 |_|_\_|___| |_| |___|_| \_|\___/|_____|   _     _____ ____  
  / ___/ _ \| \ | |_   _|  _ \ / _ \| |   | |   | ____|  _ \ 
 | |  | | | |  \| | | | | |_) | | | | |   | |   |  _| | |_) |
 | |__| |_| | |\  | | | |  _ <| |_| | |___| |___| |___|  _ < 
  \____\___/|_| \_|_|_|_|_| \_\\___/|_____|_____|_____|_| \_\
 |  \/  |  / \  / ___|_   _| ____|  _ \                      
 | |\/| | / _ \ \___ \ | | |  _| | |_) |                     
 | |  | |/ ___ \ ___) || | | |___|  _ <                      
 |_|  |_/_/   \_\____/ |_| |_____|_| \_\    
 

  Developed for the DIGITAL SKIN project from Marisa Charusilawong @ IAAC OTF - FAB LAB BARCELONA '13 http://www.iaacblog.com/openthesis/

 THIS CODE IS JUST A BETA VERSION
 
 * ARDUINO YUN
 
 * The nitinol controller manages and array of Mosfets to control nitinol wires. 
 
 * The controller exposes a basic REST API to control the wires and define the different modes of the system. 
 
 * A simple webpage can be used to talk to it from the API http://jsfiddle.net/pral2a/t227C/

 * The master controller can be networked over I2C with other Arduino to extend the number of wires to control.
 
 * The LED's outputs on each module are just for feedback purposes.

*/

// YUN
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <Wire.h>

YunServer server;
String msg;

#define totalNitGlobal 6
#define totalNitLocal 3

#define slaveID 4

#define lightASensorPin A0
#define lightBSensorPin A1

#define tempSensorPin A2

int nitPins[totalNitLocal][2] = {{13, 9}, {5, 10}, {6, 11}};
int ledPins[totalNitLocal][2] = {{A4, 8}, {4, 12}, {7, A5}};


float voltatgeOpen = 1.0;
float voltatgeClose = 0;


void setup() {
  setupAllPins();
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
  //  demo();
//  demo2();
}

void loop() {
  nitAPI();
  runModes();
}

void demo() {
  for (int nitID = 0; nitID < totalNitGlobal; nitID++) {
    openNit(nitID);
    delay(400);
  }
  for (int nitID = 0; nitID < totalNitGlobal; nitID++) {
    closeNit(nitID);
    delay(400);

  }
}

void demo2() {
  closeAll();
  delay(600);
  openAll();
  delay(600);
}
