#ifndef HEADER_CONFIG
  #define HEADER_CONFIG

  #include <Arduino_JSON.h>
  
  class Config{
    public:
      void begin( void );
      const char* getStringValue(const char a_strKey[]);
      bool hasAction(String a_strPressedKey);
      bool getKeys(const char a_strActionName[]);
      
    private:
      JSONVar objConfigJSON;
      void deserializeJSON();
  };
   
#endif
