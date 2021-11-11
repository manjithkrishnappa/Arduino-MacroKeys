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
  Keyboard.press(ConvertKeyStringToInt("KEY_LEFT_CTRL"));
  Keyboard.print(m_arrKeys[1]);
  Keyboard.releaseAll();
}

void Action::PerformTypeString()
{
  for(int i = 0; i< m_nCommands; i++)
  {
    Keyboard.print(m_arrKeys[i]);
    Keyboard.releaseAll();
  }
}

int Action::ConvertKeyStringToInt(String a_strKey)
{

  if("KEY_LEFT_CTRL")   return  0x80;
  if("KEY_LEFT_SHIFT")  return  0x81;
  if("KEY_LEFT_ALT")    return  0x82;
  if("KEY_LEFT_GUI")    return  0x83;
  if("KEY_RIGHT_CTRL")  return  0x84;
  if("KEY_RIGHT_SHIFT") return  0x85;
  if("KEY_RIGHT_ALT")   return  0x86;
  if("KEY_RIGHT_GUI")   return  0x87;
  if("KEY_UP_ARROW")    return  0xDA;
  if("KEY_DOWN_ARROW")  return  0xD9;
  if("KEY_LEFT_ARROW")  return  0xD8;
  if("KEY_RIGHT_ARROW") return  0xD7;
  if("KEY_BACKSPACE")   return  0xB2;
  if("KEY_TAB")         return  0xB3;
  if("KEY_RETURN")      return  0xB0;
  if("KEY_ESC")         return  0xB1;
  if("KEY_INSERT")      return  0xD1;
  if("KEY_DELETE")      return  0xD4;
  if("KEY_PAGE_UP")     return  0xD3;
  if("KEY_PAGE_DOWN")   return  0xD6;
  if("KEY_HOME")        return  0xD2;
  if("KEY_END")         return  0xD5;
  if("KEY_CAPS_LOCK")   return  0xC1;
  if("KEY_F1")          return  0xC2;
  if("KEY_F2")          return  0xC3;
  if("KEY_F3")          return  0xC4;
  if("KEY_F4")          return  0xC5;
  if("KEY_F5")          return  0xC6;
  if("KEY_F6")          return  0xC7;
  if("KEY_F7")          return  0xC8;
  if("KEY_F8")          return  0xC9;
  if("KEY_F9")          return  0xCA;
  if("KEY_F10")         return  0xCB;
  if("KEY_F11")         return  0xCC;
  if("KEY_F12")         return  0xCD;
  if("KEY_F13")         return  0xF0;
  if("KEY_F14")         return  0xF1;
  if("KEY_F15")         return  0xF2;
  if("KEY_F16")         return  0xF3;
  if("KEY_F17")         return  0xF4;
  if("KEY_F18")         return  0xF5;
  if("KEY_F19")         return  0xF6;
  if("KEY_F20")         return  0xF7;
  if("KEY_F21")         return  0xF8;
  if("KEY_F22")         return  0xF9;
  if("KEY_F23")         return  0xFA;
  if("KEY_F24")         return  0xFB;
  
  return NULL;
}
