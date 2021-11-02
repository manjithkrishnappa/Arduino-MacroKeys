#include "config.h"
#include <Arduino.h>
#include "Secrets.h"
 
void Config::begin( void )
{
  Serial.println( "Called Config::begin" );
  Action::Begin();
  //deserialize config
  //deserializeJSON();
  PopulateActions();
}


void Config::PopulateActions()
{
  m_nActions = 11;
  m_arrActions = new Action*[m_nActions];


  char keyBind;
  int nCommands;
  String* arrKeys;

  keyBind = 's';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "slack";
  m_arrActions[0] = new Action(keyBind, ACTION_TYPE::LAUNCH_APPLICATION, nCommands, arrKeys);

  keyBind = 'S';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "steam";
  m_arrActions[1] = new Action(keyBind, ACTION_TYPE::LAUNCH_APPLICATION, nCommands, arrKeys);

  keyBind = 't';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "teams";
  m_arrActions[2] = new Action(keyBind, ACTION_TYPE::LAUNCH_APPLICATION, nCommands, arrKeys);

  keyBind = 'p';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = SECRET;
  m_arrActions[3] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  keyBind = 'P';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = SECRET1;
  m_arrActions[4] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  keyBind = '1';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "git status";
  m_arrActions[5] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  keyBind = '2';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "git fetch";
  m_arrActions[6] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  keyBind = '3';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "git pull";
  m_arrActions[7] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  keyBind = '4';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "git add -u";
  m_arrActions[8] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  keyBind = '5';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "git commit -m ";
  m_arrActions[9] = new Action(keyBind, ACTION_TYPE::TYPE_STRING, nCommands, arrKeys);

  keyBind = '6';
  nCommands = 1;
  arrKeys= new String[nCommands];
  arrKeys[0] = "git push";
  m_arrActions[10] = new Action(keyBind, ACTION_TYPE::TERMINAL_COMMAND, nCommands, arrKeys);

  
}

void Config::deserializeJSON()
{  
//  String jsonData = CONFIG;
//  // Deserialize the JSON document
//  JSONVar objConfigJSON = JSON.parse(jsonData);
//
//  // JSON.typeof(jsonVar) can be used to get the type of the variable
//  if (JSON.typeof(objConfigJSON) == "undefined") {
//    Serial.println("Parsing input failed!");
//    return;
//  }
//
//  if (!objConfigJSON.hasOwnProperty("actions"))
//  {
//    Serial.println("Config JSON does not contain actions");
//    return;
//  }
//  JSONVar m_actions = objConfigJSON["actions"];
//  Serial.println(m_actions);
//
//  m_nActions = m_actions.length();
//
//  m_arrActions = new Action*[m_nActions];
//  for (int i = 0; i < m_actions.length(); i++) 
//  {
//    String keyBinds = JSON.stringify(m_actions[i]["keys"]);
//    m_arrActions[i] = new Action((const char *) m_actions[i]["key_bind"], keyBinds);
//  }
//
//  for (int i = 0; i < m_nActions; i++) 
//  {
//    m_arrActions[i]->PrintValues();
//  }
  
}

String Config::getKeys(char a_strPressedKey)
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

bool Config::PerformAction(char a_strPressedKey)
{
  for (int i = 0; i < m_nActions; i++) 
  {
    if(m_arrActions[i]->PerformAction(a_strPressedKey))
      return true;
  }
  return false;
}
