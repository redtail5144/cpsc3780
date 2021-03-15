CXX_9=g++9.1
CXX=g++ -std=c++11
CXXFLAGS= -g -fprofile-arcs -ftest-coverage

PROGRAM_SENDER = sender
PROGRAM_RECEIVER = receiver

.PHONY: all
all: $(PROGRAM_SENDER) $(PROGRAM_RECEIVER)

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ *.gcov *.gcda *.gcno \
	$(PROGRAM_SENDER) \
	$(PROGRAM_RECEIVER) \
	obj bin \

sender: $(PROGRAM_SENDER)

receiver: $(PROGRAM_RECEIVER)
