#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define TOUCH_SENSOR_1    4
#define TOUCH_SENSOR_2    5
#define TOUCH_SENSOR_3    12
#define TOUCH_SENSOR_4    13

const char* ssid = "Etisalat-HjHC";
const char* password = "missarahmed@246";
// IP address of the server
const char* serverAddress = "192.168.1.4";
// Port of the server
const int serverPort = 12345;

WiFiUDP udp;

bool btnState1 = LOW;
bool prevState1 = LOW;

bool btnState2 = LOW;
bool prevState2 = LOW;

bool btnState3 = LOW;
bool prevState3 = LOW;

bool btnState4 = LOW;
bool prevState4 = LOW;

void setup()
{
  Serial.begin(115200);

  pinMode(TOUCH_SENSOR_1, INPUT);
  pinMode(TOUCH_SENSOR_2, INPUT);
  pinMode(TOUCH_SENSOR_3, INPUT);
  pinMode(TOUCH_SENSOR_4, INPUT);

  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  btnState1 = digitalRead(TOUCH_SENSOR_1);
  btnState2 = digitalRead(TOUCH_SENSOR_2);
  btnState3 = digitalRead(TOUCH_SENSOR_3);
  btnState4 = digitalRead(TOUCH_SENSOR_4);

//         first sensor

  if (btnState1 && (!prevState1))
  {
    prevState1 = btnState1;

    // Send data using UDP
    udp.beginPacket(serverAddress, serverPort);
    udp.print("First");
    udp.endPacket();
  }
  else if ( (!btnState1) && prevState1)
  {
    prevState1 = LOW;
  }


//         Second sensor

  if (btnState2 && (!prevState2))
  {
    prevState2 = btnState2;

    // Send data using UDP
    udp.beginPacket(serverAddress, serverPort);
    udp.print("Second");
    udp.endPacket();
  }
  else if ( (!btnState2) && prevState2)
  {
    prevState2 = LOW;
  }

//         Third sensor

  if (btnState3 && (!prevState3))
  {
    prevState3 = btnState3;

    // Send data using UDP
    udp.beginPacket(serverAddress, serverPort);
    udp.print("Third");
    udp.endPacket();
  }
  else if ( (!btnState3) && prevState3)
  {
    prevState3 = LOW;
  }

//         Fourth sensor

  if (btnState4 && (!prevState4))
  {
    prevState4 = btnState4;

    // Send data using UDP 
    udp.beginPacket(serverAddress, serverPort);
    udp.print("Fourth");
    udp.endPacket();
  }
  else if ( (!btnState4) && prevState4)
  {
    prevState4 = LOW;
  }

}
