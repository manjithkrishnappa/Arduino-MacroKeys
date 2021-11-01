#ifndef HEADER_CONFIG
  #define HEADER_CONFIG

//  #include <Arduino_JSON.h>
  #include "Action.h"
  
  class Config
  {
    public:
      void begin( void );
      String getKeys(String a_strPressedKey);
      
    private:
//      JSONVar m_actions;
      int m_nActions;
      Action** m_arrActions;
      void deserializeJSON();

      void PopulateActions();
  };
   
#endif
