CXX				= g++
CFLAGS			= -O3 --std=c++11 -m64
RM				= rm -f
SRCS			= ./src/main.cpp
LIBDIR			= -L/usr/lib
LIBS			= -lm
LINK			=  $(LIBDIR) $(LIBS)
OBJS			= main
CPU_COMPILE_CPP	= $(CXX) $(CFLAGS)

all:
	$(CPU_COMPILE_CPP) $(SRCS) $(LINK) -o $(OBJS) -fopenmp

clean:
	$(RM) $(OBJS)