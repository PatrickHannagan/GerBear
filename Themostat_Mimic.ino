//Lighting Up Led Based on Potentioemeter and Temp

const int temperaturePin = 0;
const int potPin = 1;
int ledBlue = 8;
int ledRed=7;
int thresh=80;
int potValue;

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600); //Start reading serial port, baud rate of 9600 or 10 char a sec
}


void loop()
{
  float voltage, degreesC, degreesF;

  // First we'll measure the voltage at the analog pin. Normally
  // we'd use analogRead(), which returns a number from 0 to 1023.
  // Here we've written a function (further down) called
  // getVoltage() that returns the true voltage (0 to 5 Volts)
  // present on an analog input pin.
  potValue=analogRead(potPin);
  thresh=70+(511-potValue)/51.15;
  voltage = getVoltage(temperaturePin);
  
  degreesC = (voltage - 0.5) * 100.0;
  
  degreesF = degreesC * (9.0/5.0) + 32.0;

  Serial.print("voltage: "); //printing temp to serial
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.print(degreesF);
  Serial.print(" Thresh: ");
  Serial.print(thresh);
  Serial.print(" Pot Value ");
  Serial.println(potValue);

  delay(1000); // repeat once per second (change as you wish!)
  if(degreesF>thresh){
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, LOW);
  }
  else{
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, HIGH);
  }
}


float getVoltage(int pin)
{
  // This function has one input parameter, the analog pin number
  // to read. You might notice that this function does not have
  // "void" in front of it; this is because it returns a floating-
  // point value, which is the true voltage on that pin (0 to 5V).
  
  // You can write your own functions that take in parameters
  // and return values. Here's how:
  
    // To take in parameters, put their type and name in the
    // parenthesis after the function name (see above). You can
    // have multiple parameters, separated with commas.
    
    // To return a value, put the type BEFORE the function name
    // (see "float", above), and use a return() statement in your code
    // to actually return the value (see below).
  
    // If you don't need to get any parameters, you can just put
    // "()" after the function name.
  
    // If you don't need to return a value, just write "void" before
    // the function name.

  // Here's the return statement for this function. We're doing
  // all the math we need to do within this statement:
  
  return (analogRead(pin) * 0.004882814);
  
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}

// Other things to try with this code:

//   Turn on an LED if the temperature is above or below a value.

//   Read that threshold value from a potentiometer - now you've
//   created a thermostat!

