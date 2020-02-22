objs = tree.o stack.o util.o test.o

all: test
.PHONY : clean

test: $(objs)
	cc $(objs) -Wall -o test

clean:
	-rm $(objs) test
