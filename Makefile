src=./src/
headers=./include/
bin=./bin/
obj=./obj/
flags=-Wall -std=c99 -I$(headers)

all: make_directories documentorcat

documentorcat: lexer.o utils.o main.o
	gcc -o $(bin)documentorcat $(obj)lexer.o $(obj)utils.o $(obj)main.o $(flags)

lexer.o: $(src)lexer.c
	gcc -o $(obj)lexer.o -c $(src)lexer.c $(flags)

utils.o: $(src)utils.c
	gcc -o $(obj)utils.o -c $(src)utils.c $(flags)

main.o: $(src)main.c
	gcc -o $(obj)main.o -c $(src)main.c $(flags)

make_directories:
	mkdir -p $(obj) $(bin)

.PHONY: clean mrproper

clean:
	rm -Rf $(obj)

mrproper: clean
	rm -Rf $(bin)
