//
// Counter.h
//

#pragma once

#if !defined(_COUNTER_H)
#define _COUNTER_H


class Counter {
    int _value;

public:
    Counter(int value);

    int value() const;
    void value(int value);

    void down();
    void up();
};  // class Counter

#endif  // !_COUNTER_H
