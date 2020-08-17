all: bst
objs=bst.o
bst.o: bst.c
	cc -c -g bst.c
bst: $(objs)
	cc $(objs) -g -o bst
.PHONY: clean
clean:
	-rm $(objs) bst
