
/*

  _   _ ___ _____ ___ _   _  ___  _                          
 | \ | |_ _|_   _|_ _| \ | |/ _ \| |                         
 |  \| || |  | |  | ||  \| | | | | |                         
 | |\  || |  | |  | || |\  | |_| | |___                      
 |_|_\_|___| |_| |___|_| \_|\___/|_____|   _     _____ ____  
  / ___/ _ \| \ | |_   _|  _ \ / _ \| |   | |   | ____|  _ \ 
 | |  | | | |  \| | | | | |_) | | | | |   | |   |  _| | |_) |
 | |__| |_| | |\  | | | |  _ <| |_| | |___| |___| |___|  _ < 
  \____\___/|_| \_|_|_| |_|_\_\\___/|_____|_____|_____|_| \_\
 / ___|| |      / \ \   / / ____|                            
 \___ \| |     / _ \ \ / /|  _|                              
  ___) | |___ / ___ \ V / | |___                             
 |____/|_____/_/   \_\_/  |_____|                            
                                     
 
 Developed for the DIGITAL SKIN project from Marisa Charusilawong @ IAAC OTF - FAB LAB BARCELONA '13 http://www.iaacblog.com/openthesis/

 THIS CODE IS JUST A BETA VERSION
 
 * ARDUINO UNO 
 
 * The nitinol controller manages and array of Mosfets to control nitinol wires. 
 
 * The slave is networked over I2C with the master Arduino Yun.
 
 * The LED's outputs on each module are just for feedback purposes.

*/

#include <Wire.h>

#define totalNit 3
#define slaveID 4

#define lightASensorPin A0
#define lightBSensorPin A1

#define tempSensorPin A2

int nitPins[totalNit][2] = {{3, 9}, {5, 10}, {6, 11}};
int ledPins[totalNit][2] = {{2, 8}, {4, 12}, {7, 13}};


float voltatgeOpen = 1.0;
float voltatgeClose = 0;

void setup() {
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  setupAllPins();
}

void loop() {
//  openAll();
//  delay(1000);
//
//  closeAll();
//  delay(1000);
//
//  openNit(3);
  //  delay(1000);
  //  closeNit(1);
  //  delay(1000);
}

void receiveEvent(int howMany)
{
  int nitID;
  char cmdID;
  while (1 < Wire.available()) // loop through all but the last
  {
    cmdID = Wire.read(); // receive byte as a character
  }
  nitID = Wire.read();    // receive byte as an integer

  Serial.print(cmdID);
  Serial.println(nitID);

  switch (cmdID) {
    case 'O':
      openNit(globalTolocalID(nitID));
      break;
    case 'C':
      closeNit(globalTolocalID(nitID));
      break;
  }

}

int globalTolocalID(int nitIDGLobal) {
  return nitIDGLobal - totalNit;
}
