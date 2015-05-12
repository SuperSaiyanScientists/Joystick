
 int on;
 int buttonPin = 0;
 int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1

 void setup() {
  on = 0; 
  pinMode(buttonPin, INPUT_PULLUP);              // initializes digital pins 0 to 7 as outputs
  Serial.begin(9600);
 }

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 void loop() {
   
   if(digitalRead(buttonPin) == LOW)
     { if(on == 0)
         {
           on = 1;
         }
       else if(on == 1)
         {
           on = 0;
       }
       delay(500);
   }
   
   
   if(on == 1)
   {
    // reads the value of the variable resistor 
    value1 = analogRead(joyPin1);   
    // this small pause is needed between reading
    // analog pins, otherwise we get the same value twice
    delay(100);             
    // reads the value of the variable resistor 
    value2 = analogRead(joyPin2);   
    
    Keyboard.begin();
    
    if (value1 < 250 )
      { Keyboard.print("Left"); }
    else if (value1 > 775 )
      { Keyboard.print("Right"); }
    else
      { }
      
    if (value2 < 250 )
      { Keyboard.print("Down"); }
    else if (value2 > 775 )
      {Keyboard.print("Up"); }
    else
      { }
      
   }
 }
 
//Pin 1: 485  --  
