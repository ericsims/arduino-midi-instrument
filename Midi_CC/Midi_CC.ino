// by Tubedogg 12/2006; fabian at tubedogg.de

//This program reads up to 6 analog sensors / potentiometers ans converts the data to Midi-Controller messages
// define Switchpin:
#define switchPin 10
//  define LED:
#define LEDpin 13

// Variables

// define variables for the controller data
int AnalogValue = 0;    

// define the "lastValue" variables
int lastAnalogValue[6] = {0,0,0,0,0,0};
  
// select the midi Controller Number for each input
char midiCCselect[6] = {0x0B,0x11,0x12,0x13,0x50,51};

// select threshold for each analog input  
int thresh[6] = {1,1,1,1,1,1};  

// select number of desired analog inputs (max 6)
int input_no = 1;

void setup() {
  //  set the states of the I/O pins:
  pinMode(switchPin, INPUT);
  pinMode(LEDpin, OUTPUT);
  //  Set MIDI baud rate:
  Serial.begin(31250);

}

// main program loop
void loop() {

for(int i=0;i<input_no;i++){

          AnalogValue = (analogRead(i)/80);    // read the value from the analog input and divide by 8 for range 0-127
       // check if value is greater than defined threshold (good for resistive touchpads etc)
      if ( AnalogValue > thresh[i] ) {
            // check if analog input has changed
            if ( AnalogValue != lastAnalogValue[i]) {

            //send control change on cc#i
            midiCC(0xB0, midiCCselect[i], AnalogValue);
            // update lastAnalogValue variable
            lastAnalogValue[i] = AnalogValue;

            //End if
            }
        //End if
      }
    
  
//End for
}


//End Loop
delay(10);
}



// This function sends a Midi CC.
void midiCC(char CC_data, char c_num, char c_val){
  Serial.write(CC_data);
  Serial.write(c_num);
  Serial.write(c_val);
}
