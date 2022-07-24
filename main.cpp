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

    Counter counter(42);
    CounterWindow window(counter);
    window.show(argc, argv);

    return Fl::run();
}
