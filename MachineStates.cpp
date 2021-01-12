// MachineStates.cpp
#include "MachineStates.h"

AbstractState::~AbstractState() {}

void AbstractState::setState(Machine &machine, AbstractState *state) {
  AbstractState *aux = machine.state;
  machine.state = state;
  delete aux;
}

void AbstractState::updateStock(Machine &machine, unsigned int quantity) {
  machine.stock = quantity;
}

Normal::~Normal() {}

void Normal::sell(Machine &machine, unsigned int quantity) {
  unsigned int currStock = machine.getStock();
  if (currStock < quantity) {
    throw std::runtime_error("Not enough stock");
  }

  updateStock(machine, currStock - quantity);

  if (machine.getStock() == 0) {
    setState(machine, new SoldOut());
  }
}

void Normal::refill(Machine &machine, unsigned int quantity) {
  int currStock = machine.getStock();
  updateStock(machine, currStock + quantity);
}

SoldOut::~SoldOut() {}

void SoldOut::sell(Machine &machine, unsigned int quantity) {
  throw std::runtime_error("Sold out!");
}

void SoldOut::refill(Machine &machine, unsigned int quantity) {
  updateStock(machine, quantity);
  setState(machine, new Normal());
}
