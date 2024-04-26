#define BUTTON_PIN     8
#define LED            9

bool btnState = LOW;
bool prevState = LOW;

void setup()
{
 pinMode(BUTTON_PIN, INPUT);
 
 pinMode(LED, OUTPUT);
 digitalWrite(LED,LOW);

 Serial.begin(115200);
}

void loop() 
{
  btnState = digitalRead(BUTTON_PIN);
  if (btnState && (!prevState))
  {
    digitalWrite(LED,HIGH);
    prevState = btnState;
  }
  else if ( (!btnState) && prevState)
  {
    digitalWrite(LED,LOW);
    prevState = LOW;
  }
}
