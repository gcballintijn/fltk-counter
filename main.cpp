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
    class Handler {
        Counter & _counter;
        Fl_Box & _box;

    public:
        Handler(Counter & counter, Fl_Box & box)
            : _counter(counter), _box(box) {}

        static void
        down_callback(Fl_Widget * down_button, void * data) {
            auto handler = (Handler *)data;
            handler->handle_down();
        }

        static void
        up_callback(Fl_Widget * up_button, void * data) {
            auto handler = (Handler *)data;
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

    Fl_Window window(180, 80);
    Fl_Button down_button(0, 0, 60, 80, "down");
    Fl_Button up_button(120, 0, 60, 80, "up");
    Fl_Box box(60, 0, 60, 80, "42");

    Handler handler(counter, box);
    down_button.callback(Handler::down_callback, &handler);
    up_button.callback(Handler::up_callback, &handler);

    window.end();
    window.show(argc, argv);

    return Fl::run();
}
