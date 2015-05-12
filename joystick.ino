
 int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 1;

 // slider variable connecetd to analog pin 1
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1

 void setup() {
  Serial.begin(9600);
 }


 void loop() {
  // reads the value of the variable resistor 
  value1 = analogRead(joyPin1);   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);             
  // reads the value of the variable resistor 
  value2 = analogRead(joyPin2);   
        
  Keyboard.begin();
  if (value1 > 800) //  Y-axis
  // if the computer detects a reading over 800 it will activate the up arrow key on the y-axis
  {Keyboard.write(KEY_UP_ARROW);}
  else if (value1 < 225)
  // if the computer's reading is below 225 it will activate the down arrow key on the y-axis
  {Keyboard.write(KEY_DOWN_ARROW);}
    
  if (value2 > 800) // X-axis
  // if the computer detects a reading over 800 it will activate the left arrow key on the x-axis
  {Keyboard.write(KEY_LEFT_ARROW);}
  else if (value2 < 225)
  // if the computer detects a reading over 225 it will activate the right arrow key on the x-axis
  {Keyboard.write(KEY_RIGHT_ARROW);}
  
  delay(50);

}
 
