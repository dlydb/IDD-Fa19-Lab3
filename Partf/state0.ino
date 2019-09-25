// This borrows code from Examples->EEPROM->eeprom_clear

byte value;

void state0Setup() {
  digitalWrite(ledPin, LOW);
  Serial.println("Compare the weights");
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
  byte max_weight = 0;
  int max_pos = -1;
  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    if (value > max_weight){
      max_weight = value;
      max_pos = i;
    }
  }
  if (max_pos == -1){
    Serial.println("There is no item weighted yet!");
  }
  else{
    Serial.print("Item ");
    Serial.print(max_pos);
    Serial.print(" has the highest weight!\n\n");
  }
  delay(500);
}

void state0Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState0() {
  if (lastState != 0) { state0Setup(); }
  state0Loop();
}
