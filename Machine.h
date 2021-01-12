// machine.h
#pragma once

#include "MachineStates.h"

class AbstractState;

class Machine {
  friend class AbstractState;

public:
  Machine(unsigned int _stock);
  void sell(unsigned int quantity);
  void refill(unsigned int quantity);
  unsigned int getStock();
  ~Machine();

private:
  unsigned int stock;
  AbstractState *state;
};
