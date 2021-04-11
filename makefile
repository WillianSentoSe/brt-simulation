CXX=g++
RM=rm -f
SRCS=./src/main.cpp
OBJS=exec

all:
	$(CXX) $(SRCS) -o $(OBJS)

clean:
	$(RM) $(OBJS)