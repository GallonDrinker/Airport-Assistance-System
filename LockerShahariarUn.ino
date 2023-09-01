#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN         9
#define SS_PIN          10
#define PUSH_BUTTON_PIN 2

MFRC522 rfid(SS_PIN, RST_PIN);

Servo myservo;
const int servoPin = 6;
const int servoClosed = 0;
const int servoOpen = 90;

bool isEvenAttempt = false;
bool isDoorOpen = false;

const String masterUID = "834DA2A0";

String lastCardID;  // Declare the lastCardID variable

// Debounce variables for push button
unsigned long lastButtonPressTime = 0;
const unsigned long debounceDelay = 50;  // 50 milliseconds

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  myservo.attach(servoPin);
  myservo.write(servoClosed);
  pinMode(PUSH_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
  // Check for button press to close the door if it's open
  if (isDoorOpen && digitalRead(PUSH_BUTTON_PIN) == LOW && millis() - lastButtonPressTime > debounceDelay) {
      lastButtonPressTime = millis();
      closeDoor();
  }

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  String currentCardID = "";
  for (byte i = 0; i < rfid.uid.size; i++)
  {
    currentCardID += String(rfid.uid.uidByte[i], HEX);
  }

  if (currentCardID == masterUID)
  {
    openDoor();
  }
  else if (isEvenAttempt)
  {
    if (currentCardID == lastCardID)
    {
      openDoor();
      isEvenAttempt = !isEvenAttempt;
    }
    else
    {
      // Handle wrong card attempt
    }
  }
  else
  {
    if (currentCardID == lastCardID)
    {
      // Handle using the same card again in odd attempts
    }
    else
    {
      lastCardID = currentCardID;
      openDoor();
      isEvenAttempt = !isEvenAttempt;
    }
  }
}


void openDoor()
{
  myservo.write(servoOpen);
  isDoorOpen = true;
}

void closeDoor()
{
  Serial.println("Closing door");
  myservo.write(servoClosed);
  isDoorOpen = false;
}
