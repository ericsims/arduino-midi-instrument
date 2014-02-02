void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
}

void loop() {
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
  for (int note = 0x1E; note < 0x5A; note ++) {
    noteOn(note, 0x45);
    //cc(0x01, 0x00);
    delay(100);
    noteOff(note);
    //cc(0x01, 0x7F);
    delay(100);
  }
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int pitch, int velocity) {
  Serial.write(0x90);
  Serial.write(pitch);
  Serial.write(velocity);
}
void noteOff(int pitch) {
  Serial.write(0x90);
  Serial.write(pitch);
  Serial.write(0x00);
}
void cc(char c_num, char c_val){
  Serial.write(0xB0);
  Serial.write(c_num);
  Serial.write(c_val);
}
