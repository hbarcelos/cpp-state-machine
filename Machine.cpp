// machine.cpp
#include "Machine.h"
#include "MachineStates.h"

Machine::Machine(unsigned int _stock) : stock(_stock) {
  state = stock > 0 ? static_cast<AbstractState *>(new Normal())
                     : static_cast<AbstractState *>(new SoldOut());
}

Machine::~Machine() { delete state; }

void Machine::sell(unsigned int quantity) { state->sell(*this, quantity); }

void Machine::refill(unsigned int quantity) { state->refill(*this, quantity); }

unsigned int Machine::getStock() { return stock; }
