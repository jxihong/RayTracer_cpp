CXX                 =  g++
DEBUG	    	    = -g
COMPILER_OPTIONS    = -O0 -m64 -Wall -Wextra -Wshadow -pedantic

CXXFLAGS     = $(DEBUG) -std=c++11  -Weffc++ $(COMPILER_OPTIONS)
LDFLAGS      = -Wl -lm

# Flags for boost
BOOST_PATH        =  # Your own boost library 
CXXFLAGS         += -I $(BOOST_PATH)

# Src files for the raytracer
RAYTRACER_CXXSRCS  = rt.cc
RAYTRACER_CXXSRCS += PlaneObject.cc SphereObject.cc CylinderObject.cc
RAYTRACER_CXXSRCS += Scene.cc Camera.cc Ray.cc Light.cc Color.cc

RAYTRACER_OBJS     = $(RAYTRACER_CXXSRCS:.cc=.o);

# Build rules for programs
rt              : $(RAYTRACER_OBJS)
	            $(CXX) -o $@ $^ $(LDFLAGS)

# C++ compilation implicit rule
%.o             : %.cc
	            $(CXX) -c $(CXXFLAGS) $< -o $@

# Default compilation
all 		: rt

# Tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o *~
 

