//
// Counter.cpp
//

#include "Counter.h"


Counter::Counter(int value) : _value(value) {}

int
Counter::value() const {
    return _value;
}

void
Counter::value(int value) {
    _value = value;
}

void
Counter::down() {
    _value--;
}

void
Counter::up() {
    _value++;
}
