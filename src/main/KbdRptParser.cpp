#include "KbdRptParser.h"

void KbdRptParser::begin()
{
  m_Config.begin();
}

void KbdRptParser::PrintKey(uint8_t m, uint8_t key)
{
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;
  Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
  Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
  Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

  Serial.print(" >");
  PrintHex<uint8_t>(key, 0x80);
  Serial.print("< ");

  Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
  Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
  Serial.println((mod.bmRightGUI    == 1) ? "G" : " ");
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
//  Serial.print("DN ");
////  PrintKey(mod, key);
//  uint8_t c = OemToAscii(mod, key);
//
//  if (c)
//    OnKeyPressed(c);
}

// Map some of the keys currently not handled by OemToAscii
uint8_t KbdRptParser::mapExtraAsciiKeys(uint8_t key) {
Serial.print("******mapExtraAsciiKeys: ");
PrintHex<uint8_t>(key, 0x80);
Serial.println(key);
  switch(key) {
      case UHS_HID_BOOT_KEY_SPACE: return ' ';
      case UHS_HID_BOOT_KEY_ZERO2: return '0';
      case UHS_HID_BOOT_KEY_PERIOD: return '.';
      case UHS_HID_BOOT_KEY_ESC: return 0x1B;
      case UHS_HID_BOOT_KEY_DEL: return 0x7F;
      case UHS_HID_BOOT_KEY_BACKSPACE: return 0x08;
      case UHS_HID_BOOT_KEY_TAB: return 0x09;
  }

  return ( 0);
}

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    Serial.println("LeftCtrl changed");
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    Serial.println("LeftShift changed");
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    Serial.println("LeftAlt changed");
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    Serial.println("LeftGUI changed");
  }

  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    Serial.println("RightCtrl changed");
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    Serial.println("RightShift changed");
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    Serial.println("RightAlt changed");
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    Serial.println("RightGUI changed");
  }

}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
  Serial.print("UP ");
//  PrintKey(mod, key);
   uint8_t c = OemToAscii(mod, key);
   if (!c) {
      c = mapExtraAsciiKeys(key);
    }
    if (c)
      OnKeyPressed(c);

}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  Serial.print("ASCII: ");
  Serial.println((char)key, HEX);

  Serial.println(m_Config.PerformAction((char)key));
}
