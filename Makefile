DIRS    := src
SOURCES := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJS    := $(patsubst %.cpp, %.o, $(SOURCES))
OBJS    := $(foreach o,$(OBJS),./obj/$(o))
DEPFILES:= $(patsubst %.o, %.P, $(OBJS))

CFLAGS   = -Wall -MMD -std=c++0x -c 
COMPILER = g++
 
#link the executable
client: $(OBJS)
	$(COMPILER) $(OBJS) -o client
 
#generate dependency information and compile
obj/%.o : %.cpp
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -o $@ -MF obj/$*.P $<
 
#remove all generated files
clean:
	rm -f client
	rm -rf obj
 
#include the dependency information
-include $(DEPFILES)
