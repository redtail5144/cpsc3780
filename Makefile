CC = g++
TESTLIBS = -lgtest  -lgtest_main -lpthread
OBJS = Header.o testHeader.o
# HEADERDIRS =
# CCFLAGS = -I $(HEADERDIRS)
CCFLAGS = -std=c++11

testSH: $(OBJS)
	$(CC) -o $@  $(OBJS) $(TESTLIBS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c $<
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d


.PHONY : clean
clean :
	rm -f *.o *~ *.d


## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJS)))
