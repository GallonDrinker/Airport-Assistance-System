#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN1 53 // SS pin for first RFID scanner module
#define RST_PIN1 9 // RST pin for first RFID scanner module
#define SS_PIN2 49  // SS pin for second RFID scanner module
#define RST_PIN2 8 // RST pin for second RFID scanner module
// Motor Pins
const int motorPin1 = 5;
const int motorPin2 = 6;
const int motorEnable = 10;

// IR Sensor Pins
const int irPin1 = 2;

MFRC522 mfrc522_1(SS_PIN1, RST_PIN1); // Create MFRC522 instance for first scanner module
MFRC522 mfrc522_2(SS_PIN2, RST_PIN2); // Create MFRC522 instance for second scanner module

Servo myServo; // Define servo name

bool card1Matched = false;
bool card2Matched = false;

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate SPI bus
  mfrc522_1.PCD_Init();   // Initiate first MFRC522
  mfrc522_2.PCD_Init();   // Initiate second MFRC522
  myServo.attach(3); // Servo pin
  myServo.write(0); // Servo start position
  Serial.println("Put your first card to the first reader...");
  Serial.println("Then put your second card to the second reader...");
  Serial.println();
  // Initialize pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorEnable, OUTPUT);
  pinMode(irPin1, INPUT);
}

void loop() 
{
  // Read from IR sensors
  int irDetect1 = digitalRead(irPin1);

  // If any IR sensor detects an object, stop the motor
  if (irDetect1 == LOW ) {
    stopMotor();
    delay(4000);  // Stop for 2 seconds
    runMotor();   // Resume motor operation
    delay(500);   // Run for at least 0.5 seconds before checking again
  }
  // Otherwise, keep the motor running
  else {
    runMotor();
  }
  if (mfrc522_1.PICC_IsNewCardPresent() && !card1Matched) 
  {
    if (mfrc522_1.PICC_ReadCardSerial()) 
    {
      card1Matched = checkCardUID(mfrc522_1);
    }
  }
  
  if (mfrc522_2.PICC_IsNewCardPresent() && !card2Matched) 
  {
    if (mfrc522_2.PICC_ReadCardSerial()) 
    {
      card2Matched = checkCardUID(mfrc522_2);
    }
  }
  
  if (card1Matched && card2Matched) 
  {
    Serial.println("Authorized access for both cards");
    Serial.println();
    delay(500);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    card1Matched = false; // Reset card1Matched for the next use
    card2Matched = false; // Reset card2Matched for the next use
  }
}

bool checkCardUID(MFRC522 &rfidScanner)
{
  String content = "";
  for (byte i = 0; i < rfidScanner.uid.size; i++) 
  {
    content.concat(String(rfidScanner.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(rfidScanner.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  
  // Define an array of allowed UIDs
  String allowedUIDs[] = {
    "B3 0C AE A9",  // Example UID 1
    "6C 8A D2 38"   // Example UID 2
    // Add more allowed UIDs here if needed
  };

  for (int i = 0; i < sizeof(allowedUIDs) / sizeof(allowedUIDs[0]); i++) 
  {
    if (content.substring(1) == allowedUIDs[i]) 
    {
      Serial.println("Card UID Matched");
      return true;
    }
  }
  
  Serial.println("Card UID Not Matched");
  return false;
}

void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorEnable, 0);
}

void runMotor() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorEnable, 60);
}
