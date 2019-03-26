int rPin = D0;
int gPin = D1;
int bPin = D2;

void setup()
{
  // Set each R,G,B, pin as a digital output
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop()
{
  // set delay value to observe the change in color
  int delay_ms = 1;

  // fade each LED in and out
  fade(rPin, delay_ms); // blink the red LED
  fade(gPin, delay_ms); // blink the green LED
  fade(bPin, delay_ms); // blink the blue LED
}

// simple blink function
void fade(int pin, int delay_val)
{
  // blink "pin" a length of "delay_val" ms

  for (int brightness = 0; brightness < 256; brightness++)
  {
    // fade in
    analogWrite(pin, brightness); // turn LED on
    delay(delay_val);
  }
  for (int brightness = 255; brightness >= 0; brightness--)
  {
    // fade out
    analogWrite(pin, brightness); // turn LED off
    delay(delay_val);
  }
}
