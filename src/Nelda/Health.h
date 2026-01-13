#ifndef HEALTH_H
#define HEALTH_H

struct Health {
  int current;
  int max;

  bool isDead() const { return current <= 0; }
};

#endif
