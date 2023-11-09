 //#define debug

const float vS = 5; // in volts
int sensorPin = A0;
int sensorPin2 = A1;
float pressureValue = 0;
float pressureValue2 = 0;
const float ADC_V = .0048876;
const float sensitivity = 90; // mv/kPa
const float cmH20 = 10.197162129779; // cmH20/kPa




void setup() {
  Serial.begin(9600);

}

void loop() {

  int pinVal = analogRead(sensorPin);
  //#ifdef debug
  Serial.println(pinVal);
  //#endif debug

  int pinVal2 = analogRead(sensorPin2);
  Serial.println(pinVal2);

  float pVal1 = pinVal *ADC_V;
  //#ifdef debug
  Serial.println(pVal1);
  //#endif debug 

  float pVal2 = pinVal2 * ADC_V;
  Serial.println(pVal2);

  pressureValue = ((pVal1 * 1000) / sensitivity) * cmH20;
  Serial.print(pressureValue);
  Serial.println(" cmH2O");

  pressureValue2 = ((pVal2 * 1000) / sensitivity) * cmH20;
  Serial.print(pressureValue2);
  Serial.println(" cmH2O");

  Serial.println(pressureValue - pressureValue2);
 
  Serial.print("\n\n");

  delay(1000);

}
