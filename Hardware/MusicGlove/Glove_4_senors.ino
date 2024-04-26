#define TOUCH_SENSOR_1 8
#define TOUCH_SENSOR_2 9
#define TOUCH_SENSOR_3 10
#define TOUCH_SENSOR_4 11

#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5

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
 pinMode(TOUCH_SENSOR_1, INPUT);
 pinMode(TOUCH_SENSOR_2, INPUT);
 pinMode(TOUCH_SENSOR_3, INPUT);
 pinMode(TOUCH_SENSOR_4, INPUT);
 
 pinMode(LED_1, OUTPUT);
 pinMode(LED_2, OUTPUT);
 pinMode(LED_3, OUTPUT);
 pinMode(LED_4, OUTPUT);

 digitalWrite(LED_1,LOW);
 digitalWrite(LED_2,LOW);
 digitalWrite(LED_3,LOW);
 digitalWrite(LED_4,LOW);

 Serial.begin(115200);
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
    digitalWrite(LED_1,HIGH);
    prevState1 = btnState1;
  }
  else if ( (!btnState1) && prevState1)
  {
    digitalWrite(LED_1,LOW);
    prevState1 = LOW;
  }


//         Second sensor 

if (btnState2 && (!prevState2))
  {
    digitalWrite(LED_2,HIGH);
    prevState2 = btnState2;
  }
  else if ( (!btnState2) && prevState2)
  {
    digitalWrite(LED_2,LOW);
    prevState2 = LOW;
  }


//         Third sensor 

if (btnState3 && (!prevState3))
  {
    digitalWrite(LED_3,HIGH);
    prevState3 = btnState3;
  }
  else if ( (!btnState3) && prevState3)
  {
    digitalWrite(LED_3,LOW);
    prevState3 = LOW;
  }


//         Fourth sensor 

if (btnState4 && (!prevState4))
  {
    digitalWrite(LED_4,HIGH);
    prevState4 = btnState4;
  }
  else if ( (!btnState4) && prevState4)
  {
    digitalWrite(LED_4,LOW);
    prevState4 = LOW;
  }

}