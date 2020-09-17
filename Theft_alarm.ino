#define Buzzer 3    // Buzzer connected to digital pin 3
#define Button 2    // Button connected to digital pin 2

bool RaiseAlarm = true;

void setup() {
  pinMode(Buzzer,OUTPUT);       //Settng buzzer pin as output
  pinMode(Button,INPUT_PULLUP); //Setting button pin as input
}

void loop() {
  if(analogRead(A0) > 200){   //Vary this value according
                              //to your ambience
      RaiseAlarm = true;      //Enable the Alarm
  }
  
  if(!digitalRead(Button)){   //If button is pressed
      RaiseAlarm = false;     //Disable the Alarm
      digitalWrite(Buzzer,LOW);
  }

  if(RaiseAlarm == true){     //If Alarm is Enabled
    MakeSomeNoise();          //Raise Alarm
  }
}

void MakeSomeNoise(){     // This function gives the siren effect
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(Buzzer, fadeValue);
    // wait for 5 milliseconds to hear the siren effect
    delay(5);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(Buzzer, fadeValue);
    // wait for 5 milliseconds to hear the siren effect
    delay(5);
  }
}


