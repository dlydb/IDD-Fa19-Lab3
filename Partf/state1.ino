// This borrows code from Examples->EEPROM->eeprom_read


void state1Setup() {
  Serial.println("Ready to weight items\n");
  delay(500);
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}
