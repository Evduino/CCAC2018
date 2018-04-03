sconst int inpin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(3);
  int val = analogRead(inpin);
  Serial.println(val);
}
