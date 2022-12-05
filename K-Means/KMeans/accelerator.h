#ifndef ACCELERATOR_H
#define ACCELERATOR_H

#include "messaging.h"

struct Measurement {
  int x;
  int y;
  int z;
};

class Accelerator {
public:
  Accelerator();
  ~Accelerator();
  void makeMeasurement();
  void print();
  Measurement getMeasurement();
  // Määritellään kytkentänavat kiihtyvyysanturille:
  
  const int xPin = A1;     // x-kanavan mittaus
  const int yPin = A2;     // y-kanava
  const int zPin = A3;     // z-kanava
  int sisaanmeno = 0;

private:
  Measurement m;
};

#endif  // ACCELERATOR_H