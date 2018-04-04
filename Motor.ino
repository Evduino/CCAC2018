#define Tach01 2
#define Tach02 4
#define Tach03 3
#define Tach04 5
volatile int TachPos1 = 0;
volatile int TachPos2 = 0;

int i = 0;

void setup() { 
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
