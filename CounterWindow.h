//
// CounterWindow.h
//

#pragma once

#if !defined(_COUNTER_WINDOW_H)
#define _COUNTER_WINDOW_H

#include <memory>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include "Counter.h"


class CounterWindow : public Fl_Window {
    Counter & _counter;
    Fl_Button _down_button;
    Fl_Button _up_button;
    Fl_Box _box;

public:
    CounterWindow(Counter & counter);

    static void down_callback(Fl_Widget * down_button, void * data);
    static void up_callback(Fl_Widget * up_button, void * data);

private:
    void handle_down();
    void handle_up();
    void update_label();
};  // class CounterWindow

#endif  // !_COUNTER_WINDOW_H
