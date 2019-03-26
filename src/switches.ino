int spdt_pin1 = D1;
int spdt_pin2 = D2;
int mom_pin = D5;

void setup()
{
  pinMode(spdt_pin1, INPUT_PULLDOWN);
  pinMode(spdt_pin2, INPUT_PULLDOWN);
  pinMode(mom_pin, INPUT_PULLDOWN);

  Serial.begin(115200);
}

void loop()
{
  int spdt_state1 = 0;
  int spdt_state2 = 0;
  int mom_state = 0;

  int mom_multiplier = 0;
  int switch_value = 0;

  spdt_state1 = digitalRead(spdt_pin1);
  spdt_state2 = digitalRead(spdt_pin2);
  mom_state = digitalRead(mom_pin);

  // If spdt is in state 1
  if (spdt_state1)
  {
    switch_value = 1;
  }
  // If spdt is in state 2
  else if (spdt_state2)
  {
    switch_value = 2;
  }

  // If mom is off
  if (!mom_state)
  {
    mom_multiplier = -1;
  }
  // If mom is on
  else
  {
    mom_multiplier = 1;
  }

  switch_value = switch_value * mom_multiplier;

  Particle.publish("switch_value", String(switch_value), PRIVATE);
  // Particle.publish("spdt_pin2", String(spdt_state2), PRIVATE);
  // Particle.publish("mom", String(mom_state), PRIVATE);

  Serial.print("spdt1: ");
  Serial.println(spdt_state1);
  Serial.print("spdt2: ");
  Serial.println(spdt_state2);
  Serial.print("mom: ");
  Serial.println(mom_state);
  Serial.println(" ");

  delay(15001);
}
