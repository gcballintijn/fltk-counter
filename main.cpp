//
// main.cpp
//

#include <cstdlib>
#include <memory>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include "Counter.h"


namespace {
    class CounterWindow {
        std::unique_ptr<Counter> _counter;
        std::unique_ptr<Fl_Window> _window;
        std::unique_ptr<Fl_Button> _down_button;
        std::unique_ptr<Fl_Button> _up_button;
        std::unique_ptr<Fl_Box> _box;

    public:
        CounterWindow(std::unique_ptr<Counter> && counter)
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
        show(int argc, char ** argv) {
            _window->show(argc, argv);
        }

        static void
        down_callback(Fl_Widget * down_button, void * data) {
            auto handler = (CounterWindow *)data;
            handler->handle_down();
        }

        static void
        up_callback(Fl_Widget * up_button, void * data) {
            auto handler = (CounterWindow *)data;
            handler->handle_up();
        }

    private:
        void
        handle_down() {
            _counter->down();
            update_label();
        }

        void
        handle_up() {
            _counter->up();
            update_label();
        }

        void
        update_label() {
            auto label = std::to_string(_counter->value());
            _box->label(label.c_str());
        }
    };
}

int
main(int argc, char ** argv) {

    auto counter = std::make_unique<Counter>(42);
    auto handler = std::make_unique<CounterWindow>(std::move(counter));
    handler->show(argc, argv);

    return Fl::run();
}
