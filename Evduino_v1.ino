int Button1 = 11;
int ButtonState2 = 0;
int Button2 = 12;
int ButtonState1 = 0;
int Button3 = 13;
int ButtonState3 = 0;

int i, avr, str = 0;
int WBthreshold, LSreading = 0;
int state = 0;


int LSensor = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);

  Serial.begin(9600);
  while ( !Serial );
  pinMode(LSensor, INPUT);
  WBthreshold = analogRead(LSensor);
}

void loop() {
  if ( digitalRead(Button3) == HIGH ) {
    WBthreshold = analogRead(LSensor);
  }

  ButtonState1 = digitalRead(Button1);
  ButtonState2 = digitalRead(Button2);
  ButtonState3 = digitalRead(Button3);

  sensorValue = analogRead(LSensor);

  str = 0;
  for (i = 0; i < 99; i++)
  {
    str += WBthreshold - sensorValue;
  }
  avr = str / 100;

  LSreading = avr;

  if ( (LSreading < 30) && (LSreading > -30) ) {
    state = 0;
    Serial.println ( "you gay" );
  }
  else if (LSreading > 30) {
    state = 1;
    Serial.println ( "White power" );
  }
  else if (LSreading < -30) {
    state = -1;
    Serial.println ( "Black lives matter" );
  }

  // Serial.println ( state );
  Serial.println(LSreading);
  Serial.print(ButtonState1); Serial.print("  ");
  Serial.print(ButtonState2); Serial.print("  ");
  Serial.print(ButtonState3); Serial.print("  ");
  delay(100);

}
