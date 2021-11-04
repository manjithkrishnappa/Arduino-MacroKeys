#include "Action.h"
//#include <Arduino.h>
#include <Keyboard.h>


void Action::Begin()
{
  // initialize control over the keyboard:
  Keyboard.begin();
}

void Action::PrintValues()
{
   Serial.println("*******");
   Serial.print(m_charKeyBind);
   Serial.print("    :    ");
   Serial.print(m_arrKeys[0]);
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
    return m_arrKeys[0];
  }
  return "NULL";
}


bool Action::PerformAction(char a_strPressedKey)
{
  if(m_charKeyBind != a_strPressedKey)
  {
    return false;
  }
  Serial.println("******* Pressed Key was FOUND");

  switch(m_eType)
  {
    case LAUNCH_APPLICATION:
      PerformLauchApplication();
    break;
    case TERMINAL_COMMAND:
      PerformTerminalCommand();
    break;
    case KEYBOARD_SHORTCUT:
      PerformKeyboardShortcut();
    break;
    case TYPE_STRING:
      PerformTypeString();
    break;
  }
  
  return false;
}

void Action::PerformTerminalCommand()
{
  for(int i = 0; i< m_nCommands; i++)
  {
    Keyboard.print(m_arrKeys[i]);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void Action::PerformLauchApplication()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(ANIM_SPEED);

  int nCommandLength = m_arrKeys[0].length();
  for (int i = 0; i< nCommandLength; i++)
  {
    Keyboard.print(m_arrKeys[0].charAt(i));
    delay(ANIM_SPEED * 0.1);
  }
  
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  
}

void Action::PerformKeyboardShortcut()
{
  
}

void Action::PerformTypeString()
{
  for(int i = 0; i< m_nCommands; i++)
  {
    Keyboard.print(m_arrKeys[i]);
    Keyboard.releaseAll();
  }
}
