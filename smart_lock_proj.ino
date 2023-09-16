#include <Key.h>
#include <Keypad.h>

int ledR1=13;
int ledR2=12;
int buzzer=3;

const byte r = 4;  // number of rows
const byte c = 4;  // number of cols

char hexakeys[r][c] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowpins[r] = {11, 10, 9, 8};  // pins at rows
byte colpins[c] = {7, 6, 5, 4};    // pins at cols

Keypad pad = Keypad(makeKeymap(hexakeys), rowpins, colpins, r, c);
char entered_pswd[5];
const char original_pswd[] = "4567";

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  char key = pad.getKey();
  if (key && strlen(entered_pswd)<4)   //if entered string is not of length 4 then print only value 
   {
    Serial.print(key);
    entered_pswd[strlen(entered_pswd)] = key;
    if (strlen(entered_pswd) == 4)    //compare at string length of 4 
     {
      if (strcmp(entered_pswd, original_pswd) == 0) 
      {
        Serial.println(" Access granted");
        digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        noTone(3);

      } else 
      {
        Serial.println(" Access denied");
        digitalWrite(13,HIGH);
        digitalWrite(12,HIGH);
        tone(3,5000);
        
      }
    }
  }
}