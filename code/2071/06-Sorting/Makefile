all: bs-test sort-test

common_objs = mylib.o
sort_objs = quick.o 
search_objs = bs.o

.PHONY : clean

bs-test: $(sort_objs) $(search_objs) $(common_objs) bs-test.o
	cc $(sort_objs) $(search_objs) $(common_objs) bs-test.o -o bs-test

sort-test: $(sort_objs) $(common_objs) sort-test.o
	cc $(sort_objs) $(common_objs) sort-test.o -o sort-test


clean:
	-rm sort-test bs-test $(sort_objs) $(search_objs) $(common_objs)

