#define ANIM_SPEED 250

#ifndef HEADER_ACTION
#define HEADER_ACTION

#include <Arduino.h>

enum ACTION_TYPE
{
    TERMINAL_COMMAND,
    LAUNCH_APPLICATION,
    KEYBOARD_SHORTCUT,
    TYPE_STRING
};
  
  
class Action
{
  public:
    Action() { } ;
    Action(char a_charKeyBind, ACTION_TYPE a_eType,int a_nCommands, String* a_arrKeys) : m_charKeyBind(a_charKeyBind), m_eType(a_eType), m_nCommands(a_nCommands)
    {
        m_arrKeys = a_arrKeys;
        
    } ;
    static void Begin();
    void PrintValues();
    String GetKeys(char a_strPressedKey);
    bool PerformAction(char a_strPressedKey);
    
  private:
    char m_charKeyBind;
    ACTION_TYPE m_eType;
    int m_nCommands;
    String* m_arrKeys;
   
    void PerformTerminalCommand();
    void PerformLauchApplication();
    void PerformKeyboardShortcut();
    void PerformTypeString();
    
};
 
#endif
