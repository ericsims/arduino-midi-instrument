void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
}
int val0 = 0;
void loop() {
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
  
  /*for (int note = 0x1E; note < 0x5A; note ++) {
    //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(0x90, note, 0x45);
    delay(100);
    //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(0x90, note, 0x00);  
    delay(100);
  }
}*/
 val0 = analogRead(0);
   if (val0 > 1) {
    noteOn(0x90, 0x4B, 0x45);
    digitalWrite(13, HIGH);
  } else {
    noteOn(0x90, 0x4B, 0x00);
    digitalWrite(13, LOW);
  }
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
