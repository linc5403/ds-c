objs = test.o list.o bubble.o selection_sort_array.o insert_sort_array.o bubble_sort_array.o

all: test select insert bubble insert_list
.PHONY : clean

test: test.o list.o bubble.o
	cc test.o list.o bubble.o -Wall -o test

select: selection_sort_array.o
	cc selection_sort_array.o -Wall -o select

insert: insert_sort_array.o
	cc insert_sort_array.o -Wall -o insert

bubble: bubble_sort_array.o
	cc bubble_sort_array.o -Wall -o bubble

insert_list: insert_sort_list.o
	cc insert_sort_list.o -Wall -o insert_list

clean:
	-rm $(objs) test select bubble insert_list
