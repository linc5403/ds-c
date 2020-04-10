all: queue recentCount
.PHONY : clean

objs_queue = queue.o queue_test.o recentCount.o

queue: queue.o queue_test.o
	cc queue.o queue_test.o -g -o queue

recentCount: recentCount.o
	cc recentCount.o -o recentCount

clean:
	-rm $(objs_queue) queue recentCount
