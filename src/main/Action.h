#ifndef HEADER_ACTION
  #define HEADER_ACTION

  #include <Arduino.h>
  
  class Action
  {
    public:
      Action() { } ;
      Action(char a_charKeyBind, String* a_arrKeys) : m_charKeyBind(a_charKeyBind)
      {
        m_arrKeys = a_arrKeys;
      } ;

      void PrintValues();
      String GetKeys(char a_strPressedKey);
      bool PerformAction(char a_strPressedKey);
      
    private:
      char m_charKeyBind;
      String* m_arrKeys;

      void PerformTerminalCommand(String a_strCommand);
      
  };
   
  #endif
