objs = test.o list.o bubble.o

all: test
.PHONY : clean

test: $(objs)
	cc $(objs) -Wall -o test

clean:
	-rm $(objs) test
