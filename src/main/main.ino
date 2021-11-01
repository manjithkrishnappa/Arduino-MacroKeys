#include <Keyboard.h>
#include "KbdRptParser.h"

USB     Usb;
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

KbdRptParser Prs;

void setup() 
{
  // put your setup code here, to run once:
  // Initialize serial port
  Serial.begin(9600);
  while (!Serial) continue;
  
  // put your setup code here, to run once:
  // initialize control over the keyboard:
  Keyboard.begin();
  Prs.begin();
  
  if (Usb.Init() == -1)
    Serial.println("OSC did not start.");

  delay( 200 );

  HidKeyboard.SetReportParser(0, &Prs);
}

void loop() 
{
  Usb.Task();
}
