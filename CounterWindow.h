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


class CounterWindow {
    std::unique_ptr<Counter> _counter;
    std::unique_ptr<Fl_Window> _window;
    std::unique_ptr<Fl_Button> _down_button;
    std::unique_ptr<Fl_Button> _up_button;
    std::unique_ptr<Fl_Box> _box;

public:
    CounterWindow(std::unique_ptr<Counter> && counter);

    void show(int argc, char ** argv);

    static void down_callback(Fl_Widget * down_button, void * data);
    static void up_callback(Fl_Widget * up_button, void * data);

private:
    void handle_down();
    void handle_up();
    void update_label();
};  // class CounterWindow

#endif  // !_COUNTER_WINDOW_H
