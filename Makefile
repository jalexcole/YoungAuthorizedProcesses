CXX = clang++
override CXXFLAGS += -g -Wno-everything -Wall -Wextra -pedantic -Og

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main

run:
	make clean
	make
	./main
