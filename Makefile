PROG := rt
CXX := g++

COMPILER_OPTIONS := -m64 -Wall -Wextra -Wshadow -Werror -pedantic
CXXFLAGS := -std=c++11 -Weffc++ $(COMPILER_OPTIONS)

# Flags for boost
BOOST_PATH = # Your own boost library
CXXFlAGS += -I $(BOOST_PATH)

DEBUGFLAGS := -g -O0 -D _DEBUG

TARGET  := $(PROG)
SOURCES := $(shell echo src/*.cc)
HEADERS := $(shell echo include/*.hh)
COMMON  := 
OBJECTS := $(SOURCES:.cpp=.o)

BACKUPS := $(shell echo src/*~) $(shell echo include/*~) *~
 
all: $(TARGET)

$(TARGET): $(OBJECTS) $(COMMON)
	$(CXX) $(FLAGS) $(CXXFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	-rm -f $(TARGET) $(OBJECTS) $(BACKUPS) $(PROG).zip

%.o: %.cpp $(HEADERS) $(COMMON)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c -o $@ $<

.PHONY : all release