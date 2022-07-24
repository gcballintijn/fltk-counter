//
// Counter.h
//

#pragma once

class Counter {
    int _value;

public:
    Counter(int value);

    int value() const;
    void value(int value);

    void down();
    void up();
};
