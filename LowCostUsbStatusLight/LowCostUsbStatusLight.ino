#include <DigiCDC.h>

/* pin mapping */
const int redLedPin = 1;
const int yellowLedPin = 0;
const int greenLedPin = 2;

#if 1
  /* typically a low-active LED configuration is used */
  #define ON    LOW
  #define OFF   HIGH
#else
  /* but there are also builds with a high-active LED configuration */
  #define ON    HIGH
  #define OFF   LOW
#endif

void initSequence();

void setup() {
  SerialUSB.begin();
  SerialUSB.delay(1000);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  initSequence();
  SerialUSB.write("Status light\n");
  SerialUSB.write("Build date/time: " __DATE__ " " __TIME__ "\n");
}

void loop() {
  if (SerialUSB.available()) {
    char input = SerialUSB.read();
    switch(input)
    {
      case 'r':
        digitalWrite(redLedPin, OFF);
        break;
      case 'R':
        digitalWrite(redLedPin, ON);
        break;
      case 'y':
        digitalWrite(yellowLedPin, OFF);
        break;
      case 'Y':
        digitalWrite(yellowLedPin, ON);
        break;
      case 'g':
        digitalWrite(greenLedPin, OFF);
        break;
      case 'G':
        digitalWrite(greenLedPin, ON);
        break;
      case 'a':
        digitalWrite(redLedPin,    OFF);
        digitalWrite(yellowLedPin, OFF);
        digitalWrite(greenLedPin,  OFF);
        break;
      case 'A':
        digitalWrite(redLedPin,    ON);
        digitalWrite(yellowLedPin, ON);
        digitalWrite(greenLedPin,  ON);
        break;
    }
  }
  
   SerialUSB.delay(100); // keep USB alive              
}

void initSequence()
{
  digitalWrite(redLedPin, OFF);
  digitalWrite(yellowLedPin, OFF);
  digitalWrite(greenLedPin, OFF);
  SerialUSB.delay(1000);

  digitalWrite(redLedPin, ON);
  SerialUSB.delay(400);

  digitalWrite(redLedPin, OFF);
  digitalWrite(yellowLedPin, ON);
  SerialUSB.delay(400);

  digitalWrite(yellowLedPin, OFF);
  digitalWrite(greenLedPin, ON);
  SerialUSB.delay(400);

  digitalWrite(redLedPin, ON);
  digitalWrite(yellowLedPin, ON);
  SerialUSB.delay(400);

  digitalWrite(redLedPin, OFF);
  digitalWrite(yellowLedPin, OFF);
  digitalWrite(greenLedPin, OFF);
  SerialUSB.delay(1500);
}
