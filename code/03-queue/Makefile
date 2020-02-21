all: queue
.PHONY : clean

objs_queue = queue.o queue_test.o

queue: $(objs_queue)
	cc $(objs_queue) -g -o queue

clean:
	-rm $(objs_queue) queue
