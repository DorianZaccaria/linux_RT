all:
	@echo "Usage :"
	@echo "	make compile : to build the project"
	@echo "	make run : to run the program with the priority asked"
	@echo "	make clean : to remove binaries and temporary files"

compile:
	gcc -pedantic -ansi -lrt -o preempt preempt.c

run: compile
	sudo chrt --fifo 99 ./preempt

clean:
	rm -f preempt
	rm -f *~
	rm -f *#
