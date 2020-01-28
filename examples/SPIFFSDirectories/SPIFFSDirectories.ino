/* SPIFFSDirectories.ino
 * 
 * This sketch demonstrates how to use directories (as much
 * as supported by SPIFFS).
 * 
 * Alexander Entinger
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_MKRMEM.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

Arduino_SPIFFS filesystem;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);

  unsigned long const start = millis();
  for(unsigned long now = millis(); !Serial && ((now - start) < 5000); now = millis()) { };
  
  flash.begin();

  Serial.println("Mounting ...");
  int res = filesystem.mount();
  if(res != SPIFFS_OK && res != SPIFFS_ERR_NOT_A_FS) {
    Serial.println("mount() failed with error code "); Serial.println(res); return;
  }

  Directory dir = filesystem.opendir("/");
  DirEntry entry;
  while(dir.readdir(entry)) {
    if     (entry.isFile())      Serial.print("F ");
    else if(entry.isDirectory()) Serial.print("D ");
    Serial.print(entry.name());
    Serial.println();    
  }
  
  Serial.println("Unmounting ...");
  filesystem.unmount();
}

void loop()
{ 

}