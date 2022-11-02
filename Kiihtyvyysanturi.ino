
// These constants won't change. They're used to give names to the pins used:
const int analogInPinX = A0;  // X-kanavan kytkentänapa
const int analogInPinY = A1;  // Y-kanavan kytkentänapa
const int analogInPinZ = A2;  // Z-kanavan kytkentänapa


int sensorValueX = 0; // X-kiihtyvyyttä vastaava sensoriarvo 10 bittisessä järjestelmässä (0-1023)
int sensorValueY = 0; // Y-kiihtyvyyttä vastaava sensoriarvo 10 bittisessä järjestelmässä (0-1023)
int sensorValueZ = 0; // Z-kiihtyvyyttä vastaava sensoriarvo 10 bittisessä järjestelmässä (0-1023)
unsigned long aika = 0; // Aikaleima, joka luetaan millisekunteina. INT -tyyppinen määrittely 
int sisaanmeno = 0;

float Ax = 0.0;
float Ay = 0.0;
float Az = 0.0;
float A = 0.0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  if (sisaanmeno == 0){
    delay(500);    // Annetaan aikaa käynnistelylle
    Serial.print("Time(ms)");
    Serial.print("\t A_x");
    Serial.print("\t A_y");
    Serial.print("\t A_z");
    Serial.println("\t A");
    sisaanmeno = 1; // Vaihdetaan tunnistetieto niin tänne ei enää tulla
  }

  // Luetaan kanavien antamat sensoriarvot ja aikaleima

  sensorValueX = analogRead(analogInPinX);
  sensorValueY = analogRead(analogInPinY);
  sensorValueZ = analogRead(analogInPinZ);
  aika = millis();

  Ax = 0.1464*sensorValueX-48.119;
  Ay = 0.1497*sensorValueY-48.452;
  Az = 0.1475*sensorValueZ-50.352;
  A = sqrt(Ax*Ax+Ay*Ay+Az*Az);

  Serial.print(aika);
  Serial.print("\t;");
  Serial.print(Ax);
  Serial.print("\t;");
  Serial.print(Ay);
  Serial.print("\t;");
  Serial.print(Az);
  Serial.print("\t;");
  Serial.println(A);

  delay(100); //100 ms viive
}
