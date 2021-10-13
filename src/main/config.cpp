#include "config.h"
#include "Arduino.h"
#include "keyconfigs.h"
 
void Config::begin( void ){
  Serial.println( "Called MyClass::begin" );
  //deserialize config
  deserializeJSON();
}

void Config::deserializeJSON()
{
  char strJSON[]= CONFIG;
  
  // Deserialize the JSON document
  objConfigJSON = JSON.parse(strJSON);

  // JSON.typeof(jsonVar) can be used to get the type of the variable
  if (JSON.typeof(objConfigJSON) == "undefined") {
    Serial.println("Parsing input failed!");
    return;
  }
}

const char* Config::getStringValue(const char a_strKey[])
{
  if (objConfigJSON.hasOwnProperty(a_strKey))
  {
    Serial.println(objConfigJSON[a_strKey]); 
    return( (const char*) objConfigJSON[a_strKey] );
  }
  return "null";
  
}
