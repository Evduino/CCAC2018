int Button2 = 12;   // select the input pin 
int sensorValue2 = 98;  // variable to store the value coming from the sensor
int Button1 = 13;   // select the input pin 
int sensorValue1 = 99;
int Button3 = 11;
int sensorValue3 = 97;
int Button4 = 10;
int sensorValue4 = 96;

void setup() { 
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
}

void loop()
{
  sensorValue1 = digitalRead(Button1);  
  sensorValue2 = digitalRead(Button2);    
  sensorValue3 = digitalRead(Button3);
  sensorValue4 = digitalRead(Button4);
}

