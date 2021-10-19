#ifndef HEADER_CONFIG
  #define HEADER_CONFIG

  #include <Arduino_JSON.h>
  
  class Config{
    public:
      void begin( void );
      String getStringValue(String a_strKey);
      JSONVar getKeys(String a_strPressedKey);
      
    private:
      JSONVar objConfigJSON;
      void deserializeJSON();
      JSONVar hasAction(String a_strPressedKey);
      
  };
   
#endif
