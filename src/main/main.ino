/*4x4 Matrix Keypad connected to Arduino
This code prints the key pressed on the keypad to the serial port*/

#include <Keypad.h>
#include "Keyboard.h"
#include <Arduino_JSON.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

char strJSON[]= "{\"message\": \"Hello World\",\"Count\": 4}";
JSONVar objConfigJSON;

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
  // put your setup code here, to run once:
  // Initialize serial port
  Serial.begin(9600);
  while (!Serial) continue;
  
  // put your setup code here, to run once:
  // initialize control over the keyboard:
  Keyboard.begin();

  //deserialize config
  deserializeJSON();

}

void deserializeJSON()
{
  // Deserialize the JSON document
  objConfigJSON = JSON.parse(strJSON);

  // JSON.typeof(jsonVar) can be used to get the type of the variable
  if (JSON.typeof(objConfigJSON) == "undefined") {
    Serial.println("Parsing input failed!");
    return;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    Serial.println(keypressed);
    if (keypressed == '1')
    {
      Keyboard.print("git status");
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.releaseAll();
    }
    else if (keypressed == '2')
    {
      Keyboard.print("git fetch");
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.releaseAll();
    }
    else if (keypressed == '3')
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      delay(100);
      Keyboard.releaseAll();
    }
    else if (keypressed == '4')
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      delay(100);
      Keyboard.releaseAll();
    }
    else if (keypressed == '5')
    {
      if (objConfigJSON.hasOwnProperty("message"))
      {
        Serial.print("myObject[\"message\"] = ");    
        Serial.println(objConfigJSON["message"]);
        Keyboard.print(objConfigJSON["message"]);
      }
    }
  }

}
