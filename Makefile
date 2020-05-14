targets = main

cppComp = $(CROSS_TOOL)g++

flags = -Wall -Werror -std=c++14 -g

all: clean $(targets)

$(targets):
	$(cppComp) $(flags) $@.cpp -o main

clean:
	rm -f $(targets)