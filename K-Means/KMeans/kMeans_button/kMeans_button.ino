#include "accelerator.h"
#include "keskipisteet.h"

const int buttonPin = 2;  // Painonapin pinni
const int VCC = A0;       // Käyttöjännite
const int GND = A4;       // laitteen maa-napa

int buttonState = 0;  // Muuttuja, joka lukee painonapin tilaa

void setup() {
  Serial.begin(9600);

  // Pinnien määrittely:
  pinMode(VCC, OUTPUT);       // Kiihtyvyysanturin käyttöjännite Vcc
  pinMode(GND, OUTPUT);       // Kiihtyvyysanturin GND
  pinMode(buttonPin, INPUT);  // Määritellään painonapin pinni inputiksi

  // Asetetaan syöttöjännite (5V) ja maa-arvot (0V):
  digitalWrite(VCC, HIGH);
  delayMicroseconds(2);
  digitalWrite(GND, LOW);
  delayMicroseconds(2);

  while (Serial.available() != 0) {
    // Odotellaan että yhteys käynnistyy jos tässä sattuu olemaan viivettä. 0 tarkoittaa että yhteys on.
  }
}

void loop() {
  Accelerator Aobject;
  buttonState = digitalRead(buttonPin);

  int M = 0;
  float value;
  int j = 0;
  float minvalue = 500;
  int paikka = 0;
  int NumberOfMeasurements = 1;

  while (buttonState != HIGH) {
    // Odotellaan että yhteys käynnistyy jos tässä sattuu olemaan viivettä. 0 tarkoittaa että yhteys on.
    buttonState = digitalRead(buttonPin);
  }

  if (buttonState == HIGH) {
    for (int M = 0; M < NumberOfMeasurements;) {
      Aobject.makeMeasurement();
      Measurement foo = Aobject.getMeasurement();
      Aobject.makeMeasurement();
      Aobject.Print();
      Measurement m = Aobject.getMeasurement();
      float minvalue = 500;

      for (int j = 0; j < 6;) {
        value = abs(sqrt(pow((w[j][0] - m.x), 2) + pow((w[j][1] - m.y), 2) + pow((w[j][2] - m.z), 2)));
        if (value < minvalue) {
          minvalue = value;
          paikka = w[j][3];
        }
        j++;
      }
      M++;
    }  // end of for
  }    // end of if
  if (paikka == 1) {
    Serial.println("X-up");
  } else if (paikka == 2) {
    Serial.println("X-down");
  } else if (paikka == 3) {
    Serial.println("Y-up");
  } else if (paikka == 4) {
    Serial.println("Y-down");
  } else if (paikka == 5) {
    Serial.println("Z-up");
  } else if (paikka == 6) {
    Serial.println("Z-down");
  } else {
    Serial.println("Tapahtui virhe, mittaa uudelleen.");
  }

  // Serial.print("Suunta on: ");
  // Serial.println(paikka);
  buttonState == LOW;
  digitalWrite(buttonPin, LOW);
}  // end of loop
