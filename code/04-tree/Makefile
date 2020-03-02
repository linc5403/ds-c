objs = tree.o stack.o util.o notation_tree.o

test: $(objs)
	cc $(objs) -Wall -o test
	# cc tree.o stack.o util.o notation_tree.o -Wall -o test
clean:
	-rm $(objs) test
