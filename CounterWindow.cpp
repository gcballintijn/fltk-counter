//
// CounterWindow.cpp
//

#include "CounterWindow.h"


CounterWindow::CounterWindow(std::unique_ptr<Counter> && counter)
    : _counter(std::move(counter)),
        _window(std::make_unique<Fl_Window>(180, 80)),
        _down_button(std::make_unique<Fl_Button>(0, 0, 60, 80, "down")),
        _up_button(std::make_unique<Fl_Button>(120, 0, 60, 80, "up")),
        _box(std::make_unique<Fl_Box>(60, 0, 60, 80, "42")) {

    _down_button->callback(down_callback, this);
    _up_button->callback(up_callback, this);
    _window->end();
}

void
CounterWindow::show(int argc, char ** argv) {
    _window->show(argc, argv);
}

void
CounterWindow::down_callback(Fl_Widget * down_button, void * data) {
    auto handler = (CounterWindow *)data;
    handler->handle_down();
}

void
CounterWindow::up_callback(Fl_Widget * up_button, void * data) {
    auto handler = (CounterWindow *)data;
    handler->handle_up();
}

void
CounterWindow::handle_down() {
    _counter->down();
    update_label();
}

void
CounterWindow::handle_up() {
    _counter->up();
    update_label();
}

void
CounterWindow::update_label() {
    auto label = std::to_string(_counter->value());
    _box->label(label.c_str());
}
