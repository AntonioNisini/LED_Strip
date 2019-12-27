// LED_Strip
//
// Ciao Ale !!!

extern HardwareSerial Serial;

int led = LED_BUILTIN;

void setup() {

  Serial.begin(250000);
  while (!Serial) ;
  Serial.println("ciao");

  pinMode(led, OUTPUT);

}

void loop() {

  digitalWrite(led, HIGH);
  delay(250);

  digitalWrite(led, LOW);
  delay(250);
}