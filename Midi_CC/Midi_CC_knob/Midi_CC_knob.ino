int a = 9;
int b = 10;
int c = 8;

int encoder0PinALast = 0;

char midiCCselect[6] = {0x01,0x02,0x03,0x04,0x05,0x06};
byte midiCC[6] = {0,0,0,0,0,0};
int channel = 0;
int channelPressedLast = 0;

void setup()
{
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
 Serial.begin(31250);
}



void loop()
{
  selectChannel();
  readEncoderPos();
}

void readEncoderPos()
{
  int n = digitalRead(a);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(b) == LOW) {
       if(midiCC[channel] > 0) {
         midiCC[channel]-=8;
       }
     } else {
       if(midiCC[channel] < 120) {
         midiCC[channel]+=8;
       }
     }
     cc(midiCCselect[channel], midiCC[channel]);;
   } 
   encoder0PinALast = n;
}
void selectChannel(){
  boolean pressed = digitalRead(c);
  if (pressed < channelPressedLast) {
     channel++;
    if (channel >= 3) {
      channel = 0;
    }
  }
  channelPressedLast = pressed;
}

void cc(char c_num, char c_val){
  Serial.write(0xB0);
  Serial.write(c_num);
  Serial.write(c_val);
}
