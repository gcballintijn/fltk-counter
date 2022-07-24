//
// main.cpp
//

#include <cstdlib>
#include <memory>
#include <string>

#include <FL/Fl.H>

#include "Counter.h"
#include "CounterWindow.h"


int
main(int argc, char ** argv) {

    auto counter = std::make_unique<Counter>(42);
    auto counter_window = std::make_unique<CounterWindow>(std::move(counter));
    counter_window->show(argc, argv);

    return Fl::run();
}
