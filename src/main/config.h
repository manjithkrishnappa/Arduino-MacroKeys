#ifndef HEADER_CONFIG
  #define HEADER_CONFIG

  #include <Arduino_JSON.h>
  
  class Config{
    public:
      void begin( void );
      const char* getStringValue(const char a_strKey[]);
      
    private:
      JSONVar objConfigJSON;
      void deserializeJSON();
  };
   
#endif
