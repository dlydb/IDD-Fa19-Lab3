// This borrows code from Examples->EEPROM->eeprom_write

//String textarray = "hello cornell tech!";


void state2Setup() {
  digitalWrite(ledPin, LOW);
  Serial.println("Start weighting item");

  /*
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
  endAddr = min(textarray.length(), EEPROMSIZE);
  for (int i = 0; i < endAddr; i++) {
    EEPROM.write(i, textarray[i]);
  }
  */

  int val = analogRead(FSR) / 4;
  EEPROM.write(cur_addr, val);
  cur_addr += 1;
  
  Serial.println("Finish weighting\n");
  delay(500);
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
