int Button1 = 13;   // select the input pin 
int sensorValue1 = 99;
int Button2 = 12;   // select the input pin 
int sensorValue2 = 98;  // variable to store the value coming from the sensor
int Button3 = 11;
int sensorValue3 = 97;
int Button4 = 10;
int sensorValue4 = 96;

#define Tach01 2
#define Tach02 4
#define Tach03 3
#define Tach04 5
volatile int TachPos1 = 0;
volatile int TachPos2 = 0;

int i = 0;

void setup() { 
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600); //sets serial port for communication

  pinMode(Tach01, INPUT);
  pinMode(Tach02, INPUT);
  pinMode(Tach03, INPUT);
  pinMode(Tach04, INPUT);
  attachInterrupt(0, Tach01encoder, CHANGE); //pin 2
  attachInterrupt(1, Tach02encoder, CHANGE); //pin 3
  Serial.begin(9600);
}

void loop()
{
  sensorValue1 = digitalRead(Button1);  
  sensorValue2 = digitalRead(Button2);    
  sensorValue3 = digitalRead(Button3);
  sensorValue4 = digitalRead(Button4);

  
  delay(10);
  Serial.print(TachPos1); Serial.print(" ");
  Serial.print(TachPos2); Serial.println();
}

void Tach01encoder() {
  if ((PIND & B00010100) == 0 || (PIND & B00010100) == 20) //pin 2 == pin 4
  {
    TachPos1--;
  }
  else {
    TachPos1++;
  }

}
void Tach02encoder() {
  if ((PIND & B00101000) == 0 || (PIND & B00101000) == 40) //pin 3 == pin 5
  {
    TachPos2--;
  }
  else {
    TachPos2++;
  }
}
