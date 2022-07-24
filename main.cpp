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
        std::unique_ptr<Counter> _counter;
        std::unique_ptr<Fl_Box> _box;

    public:
        Handler(std::unique_ptr<Counter> && counter, std::unique_ptr<Fl_Box> && box)
            : _counter(std::move(counter)), _box(std::move(box)) {}

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

    auto window = std::make_unique<Fl_Window>(180, 80);
    auto down_button = std::make_unique<Fl_Button>(0, 0, 60, 80, "down");
    auto up_button = std::make_unique<Fl_Button>(120, 0, 60, 80, "up");
    auto box = std::make_unique<Fl_Box>(60, 0, 60, 80, "42");

    auto handler = std::make_unique<Handler>(std::move(counter), std::move(box));
    down_button->callback(Handler::down_callback, handler.get());
    up_button->callback(Handler::up_callback, handler.get());

    window->end();
    window->show(argc, argv);

    return Fl::run();
}
