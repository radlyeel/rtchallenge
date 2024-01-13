PROG = tracetest
OBJS = tupletest.o

CXX = g++

# Linkage with Googletest
CXXFLAGS = -std=c++20 -Wall -Werror -I/opt/homebrew/Cellar/googletest/1.14.0/include
LDFLAGS += -L/opt/homebrew/Cellar/googletest/1.14.0/lib

$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) -lm -lgtest_main -lgtest

clean:
	rm -f $(PROG) $(OBJS)
	
check: $(PROG)
	./$(PROG)


