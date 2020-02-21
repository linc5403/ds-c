all: josephus_seq_list single_list circle_list
.PHONY : clean

objs_seqList = seqlist.o seq_test.o
objs_singleList = linked_list.o single_linked_list_test.o
objs_circleList = linked_list.o circle_linked_list_test.o

josephus_seq_list: $(objs_seqList)
	cc $(objs_seqList) -g -o josephus_seq_list

single_list: $(objs_singleList)
	cc $(objs_singleList) -g -o single_list

circle_list: $(objs_circleList)
	cc $(objs_circleList) -g -o circle_list

clean:
	-rm $(objs_seqList) josephus_seq_list $(objs_singleList) single_list $(objs_circleList) circle_list
