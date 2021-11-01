#include "Action.h"
//#include <Arduino.h>
#include <Keyboard.h>

void Action::PrintValues()
{
   Serial.println("*******");
   Serial.print(m_charKeyBind);
   Serial.print("    :    ");
   Serial.print(m_arrKeys[1]);
   Serial.println("*******");
}

String Action::GetKeys(char a_strPressedKey)
{
  Serial.println("*******");
  Serial.print(m_charKeyBind);
  Serial.print(a_strPressedKey);
  Serial.println("*******");
  if(m_charKeyBind == a_strPressedKey)
  {
    Serial.println("******* FOUND");
    return m_arrKeys[1];
  }
  return "NULL";
}


bool Action::PerformAction(char a_strPressedKey)
{
  if(m_charKeyBind == a_strPressedKey)
  {
    Serial.println("******* FOUND");
    PerformTerminalCommand("git status");
    return true;
  }
  return false;
}

void Action::PerformTerminalCommand(String a_strCommand)
{
  Keyboard.print(a_strCommand);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}
