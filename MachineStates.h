// MachineStates.h
#pragma once

#include "Machine.h"
#include <exception>
#include <stdexcept>

class Machine;

class AbstractState {
public:
  virtual void sell(Machine &machine, unsigned int quantity) = 0;
  virtual void refill(Machine &machine, unsigned int quantity) = 0;
  virtual ~AbstractState();

protected:
  void setState(Machine &machine, AbstractState *st);
  void updateStock(Machine &machine, unsigned int quantity);
};

class Normal : public AbstractState {
public:
  virtual void sell(Machine &machine, unsigned int quantity);
  virtual void refill(Machine &machine, unsigned int quantity);
  virtual ~Normal();
};

class SoldOut : public AbstractState {
public:
  virtual void sell(Machine &machine, unsigned int quantity);
  virtual void refill(Machine &machine, unsigned int quantity);
  virtual ~SoldOut();
};
