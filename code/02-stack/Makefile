all: rpn
.PHONY : clean

objs_rpn = stack.o rpn.o

rpn: $(objs_rpn)
	cc $(objs_rpn) -g -o rpn

clean:
	-rm $(objs_rpn) rpn
