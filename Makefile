CXX = g++
CFLAGS = -lm -std=c++20
OBJS = circle.o curve.o ellipse.o helix.o
EXECUTABLE = curves_program
SOURCES = src

all: $(OBJS) $(SOURCES)/main.cpp
	$(CXX) $(CFLAGS) $(OBJS) $(SOURCES)/main.cpp -o $(EXECUTABLE)

circle.o: $(SOURCES)/circle.cpp
	$(CXX) $(CFLAGS) -c $(SOURCES)/circle.cpp

curve.o: $(SOURCES)/curve.cpp
	$(CXX) $(CFLAGS) -c $(SOURCES)/curve.cpp

ellipse.o: $(SOURCES)/ellipse.cpp
	$(CXX) $(CFLAGS) -c $(SOURCES)/ellipse.cpp

helix.o: $(SOURCES)/helix.cpp
	$(CXX) $(CFLAGS) -c $(SOURCES)/helix.cpp

clean: $(OBJS) $(EXECUTABLE)
	rm $(OBJS) $(EXECUTABLE)
