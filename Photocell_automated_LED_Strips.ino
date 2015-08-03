/* Photocell controlling RGB LED Strip

Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
 
For more information see http://learn.adafruit.com/photocells */

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  
  //  Assign the output for the RGB LED Strips
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}
 
void loop(void) {
  
  photocellReading = analogRead(photocellPin);  
  int r_max, g_max, b_max;
  int r_min, g_min, b_min;
  
  // Maximum Total on all LED's. This is due to limitations of current/volts
  r_max = 100;
  g_max = 100;
  b_max = 100;

  r_min = 0;
  g_min = 0;
  b_min = 0;
 
  Serial.print("Analog reading = ");
  Serial.print(photocellReading);     // the raw analog reading
 
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 10) {
    Serial.println(" - Dark");
  } else if (photocellReading < 200) {
    Serial.println(" - Dim");
  } else if (photocellReading < 500) {
    Serial.println(" - Light");
  } else if (photocellReading < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
  
  // Wait every 5 seconds for a check
  delay(5000);
  
  if (photocellReading <= 13) {
    analogWrite(REDPIN, r_max);
    analogWrite(GREENPIN, g_max);
    analogWrite(BLUEPIN, b_max);
  } else {
    analogWrite(REDPIN, r_min);
    analogWrite(GREENPIN, g_min);
    analogWrite(BLUEPIN, b_min);
  }
  
}
