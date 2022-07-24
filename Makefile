CXX = $(shell fltk-config --cxx)
LINK = $(CXX)

CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags) -I.
LDFLAGS = $(shell fltk-config --use-gl --use-images --ldflags)
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags)
DEBUG = -g

TARGET = counter
OBJS = Counter.o main.o
SRCS = Counter.cpp main.cpp

.SUFFIXES: .o .cpp

%.o:	%.cpp
		$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

all:	$(TARGET)
		$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

clean:	$(TARGET) $(OBJS)
		rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)

main.o:		Counter.h main.cpp
Counter.o:	Counter.h Counter.cpp
