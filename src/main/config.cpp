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

bool Config::hasAction(String a_strPressedKey)
{
  if (!objConfigJSON.hasOwnProperty("actions"))
  {
    Serial.println("Config JSON does not contain actions");
    return false;
  }

  JSONVar actions = objConfigJSON["actions"];

  for (int i = 0; i < actions.length(); i++) 
  {
    Serial.println(actions[i]["key_bind"]);
    if(a_strPressedKey == (const char *) actions[i]["key_bind"])
    {
      Serial.println("Found!!");
      return true;
    }
  }
  
  return false;
}

bool Config::getKeys(const char a_strActionName[])
{
  
  return true;
}
