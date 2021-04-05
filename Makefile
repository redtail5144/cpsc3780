CXX_9=g++9.1
CXX=g++ -std=c++11
CXXFLAGS= -g -fprofile-arcs -ftest-coverage
TESTLIBS = -lgtest  -lgtest_main -lpthread
OBJS = Header.o testHeader.o

PROGRAM_SENDER = sender
PROGRAM_RECEIVER = receiver

testSH: $(OBJS)
	$(CXX) -o $@  $(OBJS) $(TESTLIBS)

.PHONY: all
all: $(OBJS) $(PROGRAM_SENDER) $(PROGRAM_RECEIVER)

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o *.d *~ *.gcov *.gcda *.gcno \
	$(PROGRAM_SENDER) \
	$(PROGRAM_RECEIVER) \
	$(OBJS) \
	obj bin \

sender: $(PROGRAM_SENDER)

receiver: $(PROGRAM_RECEIVER)

## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJS)))
