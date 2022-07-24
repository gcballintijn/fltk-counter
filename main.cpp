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
    class CounterWindow : public Fl_Window {
        Counter & _counter;
        Fl_Button _down_button;
        Fl_Button _up_button;
        Fl_Box _box;

    public:
        CounterWindow(Counter & counter)
            : _counter(counter),
              Fl_Window(180, 80),
              _down_button(0, 0, 60, 80, "down"),
              _up_button(120, 0, 60, 80, "up"),
              _box(60, 0, 60, 80, "42") {

            _down_button.callback(down_callback, this);
            _up_button.callback(up_callback, this);
            end();
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
            _counter.down();
            update_label();
        }

        void
        handle_up() {
            _counter.up();
            update_label();
        }

        void
        update_label() {
            auto label = std::to_string(_counter.value());
            _box.label(label.c_str());
        }
    };
}

int
main(int argc, char ** argv) {

    Counter counter(42);
    CounterWindow window(counter);
    window.show(argc, argv);

    return Fl::run();
}
