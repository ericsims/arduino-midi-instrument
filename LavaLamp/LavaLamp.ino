char midiCCselect[6] = {0x01,0x02,0x03,0x04,0x05,0x06};

void setup()
{
 Serial.begin(31250);
}



void loop()
{
  cc(midiCCselect[0], (analogRead(4)/8));
  delay(10);
  noteOn((analogRead(5)/8), 0x45);
  delay(10);
}


void noteOn(int pitch, int velocity) {
  Serial.write(0x90);
  Serial.write(pitch);
  Serial.write(velocity);
}

void cc(char c_num, char c_val){
  Serial.write(0xB0);
  Serial.write(c_num);
  Serial.write(c_val);
}
