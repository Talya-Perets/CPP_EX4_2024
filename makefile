CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = tree_demo
TEST_TARGET = test_tree
SOURCES = Demo.cpp Complex.cpp
TEST_SOURCES = Test.cpp Complex.cpp
HEADERS = Node.hpp Tree.hpp Iterator.hpp Complex.hpp

all: $(TARGET) $(TEST_TARGET)

tree: $(TARGET)
	./$(TARGET)
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

$(TEST_TARGET): $(TEST_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o


