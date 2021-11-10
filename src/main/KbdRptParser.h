#ifndef HEADER_KDBRPTPARSER
#define HEADER_KDBRPTPARSER

#include <hidboot.h>
#include "config.h"

#define UHS_HID_BOOT_KEY_ESC        0x29
#define UHS_HID_BOOT_KEY_DEL        0x4C
#define UHS_HID_BOOT_KEY_BACKSPACE  0x2A
#define UHS_HID_BOOT_KEY_HOME       0x4A
#define UHS_HID_BOOT_KEY_PAGE_UP    0x4B
#define UHS_HID_BOOT_KEY_END        0x4D
#define UHS_HID_BOOT_KEY_PAGE_DN    0x4E
#define UHS_HID_BOOT_KEY_TAB        0x2B
#define UHS_HID_BOOT_KEY_CAPS       0x39

class KbdRptParser : public KeyboardReportParser
{
  private:
    Config m_Config;
    void PrintKey(uint8_t mod, uint8_t key);
    uint8_t KbdRptParser::mapExtraAsciiKeys(uint8_t key);

  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);

    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);

  public:
    void begin();
};

#endif
