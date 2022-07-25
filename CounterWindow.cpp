//
// CounterWindow.cpp
//

#include "CounterWindow.h"


CounterWindow::CounterWindow(Counter & counter)
    : _counter(counter),
        Fl_Window(180, 80),
        _down_button(0, 0, 60, 80, "down"),
        _up_button(120, 0, 60, 80, "up"),
        _box(60, 0, 60, 80, "42") {

    end();

    _down_button.callback(down_callback, this);
    _up_button.callback(up_callback, this);

    update_label();
}

void
CounterWindow::handle_down() {
    _counter.down();
    update_label();
}

void
CounterWindow::handle_up() {
    _counter.up();
    update_label();
}

void
CounterWindow::update_label() {
    _label = std::to_string(_counter.value());
    _box.label(_label.c_str());
}

void
CounterWindow::down_callback(Fl_Widget * down_button, void * data) {
    auto window = (CounterWindow *)data;
    window->handle_down();
}

void
CounterWindow::up_callback(Fl_Widget * up_button, void * data) {
    auto window = (CounterWindow *)data;
    window->handle_up();
}
