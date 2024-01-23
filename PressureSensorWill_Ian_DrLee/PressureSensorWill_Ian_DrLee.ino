//#define debug

const float vS = 5; // in volts
int sensorPin = A0;
float pressureValue = 0;
const float ADC_V = .0048828125;
//const float sensitivity = 90; // mv/kPa
const float cmH20 = 10.197162129779; // cmH20/kPa




void setup() {
  Serial.begin(9600);

}

void loop() {

  int pinVal = analogRead(sensorPin);
  //#ifdef debug
  Serial.println(pinVal);
  //#endif //debug

  float pVal1 = pinVal * ADC_V;
  //#ifdef debug
  Serial.println(pVal1);
  //#endif //debug 

  //pressureValue = ((pVal1 * 1000) / sensitivity) * cmH20;
  pressureValue = pVal1 * 1000 * cmH20;

  Serial.println(pressureValue);

  Serial.print("\n\n");

  delay(1000);

}