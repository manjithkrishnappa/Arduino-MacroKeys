#include "config.h"
#include <Arduino.h>
#include "keyconfigs.h"
 
void Config::begin( void )
{
  Serial.println( "Called Config::begin" );
  //deserialize config
  deserializeJSON();
}

void Config::deserializeJSON()
{  
  String jsonData = CONFIG;
  // Deserialize the JSON document
  JSONVar objConfigJSON = JSON.parse(jsonData);

  // JSON.typeof(jsonVar) can be used to get the type of the variable
  if (JSON.typeof(objConfigJSON) == "undefined") {
    Serial.println("Parsing input failed!");
    return;
  }

  if (!objConfigJSON.hasOwnProperty("actions"))
  {
    Serial.println("Config JSON does not contain actions");
    return;
  }
  JSONVar m_actions = objConfigJSON["actions"];
  Serial.println(m_actions);

  m_nActions = m_actions.length();

  m_arrActions = new Action*[m_nActions];
  for (int i = 0; i < m_actions.length(); i++) 
  {
    String keyBinds = JSON.stringify(m_actions[i]["keys"]);
    m_arrActions[i] = new Action(JSON.stringify(m_actions[i]["key_bind"]), keyBinds);
  }

  for (int i = 0; i < m_nActions; i++) 
  {
    m_arrActions[i]->PrintValues();
  }
  
}

String Config::getKeys(String a_strPressedKey)
{
  for (int i = 0; i < m_nActions; i++) 
  {
    String strKeys =  m_arrActions[i]->GetKeys(a_strPressedKey);
    if(strKeys != "NULL")
      return strKeys;
  }

  Serial.print("Could not find keys for action associated with: ");
  Serial.println(a_strPressedKey);
  return "NULL";
}
