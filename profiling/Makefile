exec := profiler
srcs := $(wildcard *.cpp)

objs := $(srcs:.cpp=.o)

$(exec): $(objs)
	$(CXX) -o $@ $+

