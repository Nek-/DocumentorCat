src=./src/
headers=./include/
bin=./bin/
obj=./obj/
flags=-Wall -I$(headers)

all: make_directories documentorcat

documentorcat: reg_exp.o main.o
	gcc -o $(bin)documentorcat $(obj)reg_exp.o $(obj)main.o $(flags)

reg_exp.o: $(src)reg_exp.c
	gcc -o $(obj)reg_exp.o -c $(src)reg_exp.c $(flags)

main.o: $(src)main.c
	gcc -o $(obj)main.o -c $(src)main.c $(flags)

make_directories:
	mkdir -p $(obj) $(bin)

.PHONY: clean mrproper

clean:
	rm -Rf $(obj)

mrproper: clean
	rm -Rf $(bin)