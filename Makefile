default: run
compile main.out: main.o des.o sha.o
	@gcc -o main.out main.o des.o sha.o -lm
usage:
	@echo
	@echo "USAGE"
	@echo "=========="
	@echo
	@echo "FLAGS"
	@echo "=========="
main.o: main.c main.h des.h sha.h
	@gcc -c main.c
des.o: des.c main.h des.h
	@gcc -c des.c
sha.o: sha.c main.h sha.h
	@gcc -c sha.c
run: main.out
	@./main.out $(ARGS)
encrypt: main.out
	@./main.out encrypt ${ARGS}
decrypt: main.out
	@./main.out decrypt ${ARGS}
clean:
	rm *.o main.out
