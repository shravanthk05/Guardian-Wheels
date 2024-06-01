#include <SoftwareSerial.h>

SoftwareSerial SIM7670Serial(2, 3);      // RX, TX for GSM module
SoftwareSerial Bluetooth_Serial(9, 10);   // RX, TX for Bluetooth module

char Incoming_value = 0;
int b = 6;
int bval;
int state;

void setup() 
  {
    pinMode(b, INPUT);
    digitalWrite(b, HIGH);
    Serial.begin(115200);  // Start hardware serial for debugging
    SIM7670Serial.begin(115200);  // Start software serial for GSM module at 115200 baud rate
    Bluetooth_Serial.begin(9600);  // Start software serial for Bluetooth module
    pinMode(13, OUTPUT);
  }

void sendATCommand(SoftwareSerial &serial, const char* cmd, const char* expectedResponse, unsigned long timeout) 
  {
    serial.println(cmd);
    String response = "";
    unsigned long startTime = millis();
    bool responseOK = false;

    while (millis() - startTime < timeout) 
      {
        while (serial.available() > 0) 
          {
            char c = serial.read();
            response += c;
          }
        if (response.indexOf(expectedResponse) != -1) 
          {
            responseOK = true;
            break; // found it
          }
      }
    Serial.println(response);

    if (responseOK)
      Serial.println("Response OK");
    else
      Serial.println("Timeout without expected Response");
  }

void sendSMS(const char* number, const char* message) 
  {
    String cmd = "AT+CMGS=\"";
    cmd += number;
    cmd += "\"\r\n";
    SIM7670Serial.print(cmd);
    delay(100);
    SIM7670Serial.println(message);
    delay(100);
    SIM7670Serial.write(0x1A); // send ctrl-z
    delay(100);
  }

void loop() 
  {
    bval = digitalRead(b);
    Serial.println(bval);

    if (state == 0 && bval == 0) 
      {
        // If button is pressed and state is 0, send SMS and make a call using the GSM module
        sendSMS("+919840473695", "THEFT ALERT!");
        // Make a call
        SIM7670Serial.println("ATD +919840473695;"); // Replace +123456789 with the desired phone number
        delay(1000);
        if (SIM7670Serial.available()) 
          {
            String response = SIM7670Serial.readString();
            Serial.println(response);
            // Check if the response indicates a call has been connected
            if (response.indexOf("CONNECT") != -1) 
              {
                // Call connected
                Serial.println("Call Connected");
                // Add code here to perform actions during the call
              }
          }
        // Set digital pin 13 to HIGH
        digitalWrite(13, HIGH);
      } 
      else if(state == 1 && bval == 0)
        {
          // Set digital pin 13 to LOW
          digitalWrite(13, LOW);
        }
  
      // Handle incoming data from Bluetooth
      if (Bluetooth_Serial.available() > 0) 
        {
          Incoming_value = Bluetooth_Serial.read();
          Serial.print("Bluetooth Input: ");
          Serial.println(Incoming_value);
          // Add code to handle Bluetooth input
          if (Incoming_value == '1') 
            {
              digitalWrite(13, HIGH);
              delay(125);
              digitalWrite(13, LOW);
              delay(125);
              digitalWrite(13, HIGH);
              delay(125);
              digitalWrite(13, LOW);
              state = 0;
            }       
          else if (Incoming_value == '0') 
            {
              digitalWrite(13, HIGH);
              delay(125);
              digitalWrite(13, LOW);
              delay(125);
              digitalWrite(13, HIGH);
              delay(125);
              digitalWrite(13, LOW);
              state = 1;
            }
        }
  }
