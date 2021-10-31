#ifndef HEADER_KDBRPTPARSER
  #define HEADER_KDBRPTPARSER

  #include <hidboot.h>
  #include "config.h"

class KbdRptParser : public KeyboardReportParser
{
  private:
    Config m_Config;
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);

    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);

  public:
    void begin();
};

  #endif
