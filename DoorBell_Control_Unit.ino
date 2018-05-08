/*                        DoorBell Control Utility
 *                           Made by: Vinylwalk3r
 *  DoorBell CU is a lightweight program to use with an Arduino / Genuiono Uno
 *    It allows you to controll your doorbells ringing with an On/Off switch
 *             Feel free to use and modify this code as se fit,
 *                  but give me credit for the base code
 */

#define Greenlight 6       // The green light, Digital Pin 6
#define Redlight 7         // The red warning light, Digital Pin 7
#define Bell 2             // The bell itself, Digital Pin 2
#define Bellbutton 12      // House bellbutton, Analog pin 0
#define BellswitchInput A2 // Sends signal to the Ardino to start the bell ringing cycle, Analog pin 2
#define BellswitchOutput 9 // Arduino sends signal to the switch that the bellbutton has bin pressed, Digital pin 9
int SwitchState;           // Initiates the value "SwitchState" and sets it to 0

void setup()
{
  /* The following code will only run ONCE ---------------
  ---Press the reset button on the Arduino to run again-- */

  pinMode(Redlight, OUTPUT); // Sets the pins as outputs
  pinMode(Greenlight, OUTPUT);
  pinMode(Bell, OUTPUT);
  pinMode(Bellbutton, INPUT);        // Bellbutton is the button visitors push to activate bell
  pinMode(BellswitchInput, INPUT);   // Sends signal to the switch
  pinMode(BellswitchOutput, OUTPUT); // Recives the signal from the switch, either a HIGH or LOW

  digitalWrite(Redlight, HIGH); // Turn LED on
  digitalWrite(Greenlight, HIGH);
  delay(1000);                 // Waits for 1 second
  digitalWrite(Redlight, LOW); // Turn LED off
  digitalWrite(Greenlight, LOW);

  digitalWrite(Bell, HIGH); // Tests the bell
  delay(1000);
  digitalWrite(Bell, LOW); // Turns off the bell
}

void loop()
{
  /* The following code will run continually ----------
  ---Press the reset button on the Arduino to re-run-- */

  while (digitalRead(Bellbutton) == HIGH)
    ;
  { // Monitors if the bellbutton is pressed

    digitalWrite(BellswitchOutput, HIGH);            // Sends current to the switch when the bell is pressed
    int SwitchState = digitalRead(BellswitchOutput); // Reads the signal from the BellSwitch and stores it in the integer "SwitchState"

    if (SwitchState == 1)
    {                                 // Runs if the switch gives a positive signal
      digitalWrite(Greenlight, HIGH); // Turn LED on
      digitalWrite(Bell, HIGH);       // Rings the bell
      delay(3000);
      digitalWrite(Bell, LOW);
      digitalWrite(Greenlight, LOW);
    }
    else
    { // Runs if the switch gives a negative / no signal
      digitalWrite(Redlight, HIGH);
      delay(3000);
      digitalWrite(Redlight, LOW);
    }
  }
}
