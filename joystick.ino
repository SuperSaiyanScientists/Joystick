//Setting up the joystick and arduino
//Gather jumper wires, arduino leonardo, breadboard and a joystick
//Connect a wire to the ground (GND) port of the Arduino Leondardo to a pin on the ground rail of the breadboard
//Connect a wire from the power rail of the breadboard to the 5V port on the Arduino leonardo
//Connect a wire from row 58 and row 59 to A-1 and A-0 respectively on the arduino
//Connect a jumper wire from the ground rail of the breadboard (be sure it's along the same column as the wire you already attached to the ground rail) to row 56 
//Connect a jumper wire from the power rail of the breadboard (same column as the wire already connecting the power rail to the 5V port on the arduino) to row 60 of the breadboard
//Connect a wire from the VCC port on the joystick to row 60 on the breadboard
//Connect a wire from the Vertical port (VERT) on the joystick to row 59 (Joystick)
//Connect a wire from the Horizontal port (Horz) on the joystick to row 58 (Joystick)
//Connect a wire from the (SEL) port on the joystick to row 57 (Joystick)
//Connect a wire from the (GND) port on the joystick to row 56 (Joystick)



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
 
