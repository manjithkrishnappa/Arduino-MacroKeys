#include "Action.h"
//#include <Arduino.h>


void Action::PrintValues()
{
   Serial.println("*******");
   Serial.print(m_charKeyBind);
   Serial.print("    :    ");
   Serial.print(m_arrKeys);
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
    return m_arrKeys;
  }
  return "NULL";
}
