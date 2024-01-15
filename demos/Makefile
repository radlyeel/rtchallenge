# call with make PROG=projectile
OBJS = $(PROG).o

CXX = g++

CXXFLAGS = -std=c++20 -Wall -Werror  -I..

$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) -lm

clean:
	rm -f $(PROG) *.o
	
check: $(PROG)
	./$(PROG)


