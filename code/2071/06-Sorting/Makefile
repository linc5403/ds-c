all: binary-search

objs_sort = quick.o mylib.o
objs_search = bs-test.o bs.o mylib.o

.PHONY : clean

binary-search: $(objs_sort) $(objs_search)
	cc $(objs_sort) $(objs_search) -o binary-search

clean:
	-rm binary-search $(objs_sort) $(objs_search)

