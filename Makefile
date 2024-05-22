default: run
compile main.out: main.o
	@gcc -o main.out main.o -lm
usage:
	@echo
	@echo "USAGE"
	@echo "=========="
	@echo
	@echo "FLAGS"
	@echo "=========="
main.o: main.c main.h
	@gcc -c main.c
run: main.out
	@./main.out $(ARGS)
encrypt: main.out
	@./main.out encrypt ${ARGS}
decrypt: main.out
	@./main.out decrypt ${ARGS}
clean:
	rm *.o main.out
