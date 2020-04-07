//initialise variables
int ledG = D6;
int ledB = D5;
int ledR = D4;

void setup() 
{
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);
   
  Particle.function("led",ledToggle); //the function that would link the particle device 
  // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.
   
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledR, LOW);
  //to ensure that the LED's are off at start
}

void loop()
{
   // Nothing to do here
}
// We're going to have a super cool function now that gets called when a matching API request is sent
// This is the ledToggle function we registered to the "led" Particle.function earlier.

int ledToggle(String command) 
{
    /* Particle.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */

    if (command=="green_light") 
    {
        digitalWrite(ledG,HIGH);
        digitalWrite(ledB,LOW);
        digitalWrite(ledR,LOW);
        return 1;
    }
    else if (command=="blue_light") 
    {
        digitalWrite(ledG,LOW);
        digitalWrite(ledB,HIGH);
        digitalWrite(ledR,LOW);
        return 1;
    }
    else if (command=="red_light") 
    {
        digitalWrite(ledG,LOW);
        digitalWrite(ledB,LOW);
        digitalWrite(ledR,HIGH);
        return 0;
    }
    else 
    {
        return -1;
    }
}