CXX = g++
CXXFLAGS = -O3 -std=c++11

all: naive tiled

naive: naive_mul.cpp
	$(CXX) $(CXXFLAGS) -o naive naive_mul.cpp

tiled: tiled_mul.cpp
	$(CXX) $(CXXFLAGS) -o tiled tiled_mul.cpp

clean:
	rm -f naive tiled
