#include "messaging.h"
#include "accelerator.h"

void setup() {
  Serial.begin(9600);

  const int VccPin2 = A0;  // Käyttöjännite
  const int GNDPin2 = A4;  // laitteen maa-napa

  // Kiihtvyys-anturin napojen määrittely:
  pinMode(VccPin2, OUTPUT);  // Kiihtyvyysanturin käyttöjännite Vcc
  pinMode(GNDPin2, OUTPUT);  // Kiihtyvyysanturin GND

  // Asetetaan syöttöjännite (5V UNO-BOARDILLA, 3.3V Genuino 101:llä) ja maa-arvot (0V):
  digitalWrite(VccPin2, HIGH);
  delayMicroseconds(2);
  digitalWrite(GNDPin2, LOW);
  delayMicroseconds(2);

  while (Serial.available() != 0) {
    // Odotellaan että yhteys käynnistyy jos tässä sattuu olemaan viivettä. 0 tarkoittaa että yhteys on.
  }
}

void loop() {
  Accelerator Aobject;
  Messaging Mobject;
  Serial.println("Give number how many measurements");
  int NumberOfMeasurements = 0;
  while (NumberOfMeasurements == 0) {
    if (Serial.available() > 0) {
      NumberOfMeasurements = Serial.parseInt();
    }
  }
  Serial.println("Give the rotation (1=up, 2=down, 3= right, 4= left");
  int NumberOfRotation = 0;
  while (NumberOfRotation == 0) {
    if (Serial.available() > 0) {
      NumberOfRotation = Serial.parseInt();
    }
  }

  for (int M = 0; M < NumberOfMeasurements; M++) {
    Aobject.makeMeasurement();
    Measurement m = Aobject.getMeasurement();
    uint8_t id = M;
    uint8_t flags = NumberOfRotation;
    Mobject.createMessage(m);
    Aobject.print();
    if (Mobject.sendMessage(id, flags)) {
      Serial.println("Successfull transmission");
    } else {
      Serial.println("Transmission fails");
    }
    if (Mobject.receiveACK()) {
      Serial.println("Receiver got message, going to next measurement");
    } else {
      Serial.println("Reciver did not get the message. Need to resend it");
      // M--;  // Let's just revind for
    }
  }  // end of for
}  // end of loop