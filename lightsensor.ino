const int inpin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(inpin);
  Serial.println(val);
}
