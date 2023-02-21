// defines pins numbers
const int stepPin = 3; 
const int dirPin = 2; 
const int enPin = 4;
const int endstopPin1 = 7;
const int endstopPin2 = 8; 
const int stepPerRevolution = 200;
const int cmToMove = 60;
void setup() {
  
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(endstopPin1, INPUT_PULLUP);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
}
void loop()
{
label:
 digitalWrite(dirPin, HIGH); //Changes the rotations direction  
  while (digitalRead(endstopPin1)== LOW)
      {
        digitalWrite(dirPin,HIGH);
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(80);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(80);

          while(digitalRead(endstopPin1)== HIGH)
          {
            //delay(1000);
            digitalWrite(dirPin, LOW);
            digitalWrite(stepPin,HIGH);
            delayMicroseconds(80);
            digitalWrite(stepPin,LOW);
            delayMicroseconds(80);

                while (digitalRead(endstopPin1)== LOW)
                    {
                        digitalWrite(dirPin,LOW);
                        digitalWrite(stepPin,HIGH);
                        delayMicroseconds(80);
                        digitalWrite(stepPin,LOW);
                        delayMicroseconds(80);

                      while(digitalRead(endstopPin2)== HIGH)
                           {
                              //delay(1000);
                              digitalWrite(dirPin, HIGH);
                              digitalWrite(stepPin,HIGH);
                              delayMicroseconds(80);
                              digitalWrite(stepPin,LOW);
                              delayMicroseconds(80);

                                  while(digitalRead(endstopPin2)== LOW)
                                      {
                                          //delay(1000);
                                          digitalWrite(dirPin, HIGH);
                                          digitalWrite(stepPin,HIGH);
                                          delayMicroseconds(80);
                                          digitalWrite(stepPin,LOW);
                                          delayMicroseconds(80);
                                          goto label;
                                      }
                            }
                      }
            }

        }
}

          
