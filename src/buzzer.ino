int buzzPin = D0;

void setup()
{
  pinMode(buzzPin, OUTPUT);
}

void loop()
{
  int eigthNote = 50;
  int quarterNote = 150;
  int halfNote = 500;

  buzz(buzzPin, quarterNote);
  buzz(buzzPin, eigthNote);
  buzz(buzzPin, eigthNote);
  buzz(buzzPin, quarterNote);
  buzz(buzzPin, halfNote);
  buzz(buzzPin, quarterNote);
  buzz(buzzPin, quarterNote);

  delay(10000);
}

void buzz(int bPin, int bDelay)
{
  int bLength = 100;
  digitalWrite(bPin, HIGH);
  delay(bLength);
  digitalWrite(bPin, LOW);
  delay(bDelay);
}
