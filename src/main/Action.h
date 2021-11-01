#ifndef HEADER_ACTION
  #define HEADER_ACTION

  #include <Arduino.h>
  
  class Action
  {
    public:
      Action() { } ;
      Action(String a_charKeyBind, String a_arrKeys) : m_charKeyBind(a_charKeyBind), m_arrKeys(a_arrKeys) { } ;

      void PrintValues();
      String GetKeys(String a_strPressedKey);
      
    private:
      String m_charKeyBind;
      String m_arrKeys;
      
  };
   
  #endif
