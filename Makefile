CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC = main.cpp
TARGET = change_plan

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)