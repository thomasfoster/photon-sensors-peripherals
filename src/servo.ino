Servo myservo;

int pos = 0;
int mom_pin = D5;
// setting debounce count and debouncing bool
// out of loop so it can be used in loop
int debounce_count = 0;
bool debouncing = false;

int reset_count = 0;

void setup()
{
  myservo.attach(D0);
  pinMode(mom_pin, INPUT_PULLDOWN);

  myservo.write(0);
  Serial.begin(115200);

  delay(500);
}

void loop()
{
  int mom_state = 0;
  int debounce_max_time = 300;
  int delay_time = 30;

  mom_state = digitalRead(mom_pin);

  // If the button is pressed or it is currently debouncing
  if (mom_state || debounce_count)
  {
    debounce_count += delay_time;
    // If currently debouncing, run once
    if (debounce_count < debounce_max_time)
    {
      if (!debouncing)
      {
        turnServo();
        debouncing = true;
      }
    }
    // if time has exceeded max, reset debounce and count
    else
    {
      Serial.println("RESET");
      debouncing = false;
      debounce_count = 0;
      reset_count += 1;
      Particle.publish("reset_count", String(reset_count), PRIVATE);
    }
  }
  delay(delay_time);
}

void turnServo()
{
  if (pos <= 180)
  {
    pos += 20;
  }
  else
  {
    pos = 0;
  }
  myservo.write(pos);
}
