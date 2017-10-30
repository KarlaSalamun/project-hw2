SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
EXESRC=$(wildcard exe/*c)
EXEOBJ=$(patsubst %c, %o, $(EXESRC))
INC=inc/

CFLAGS=-I $(INC)
EXE=$(patsubst %c, %elf, $(EXESRC))

.SECONDARY:

all: $(EXE)
	@for exe in $(EXE) ; \
	do \
		./$$exe ; \
	done

%.elf: %.o $(OBJ)
	gcc  $(OBJ) $< -lm -lfftw3 -o $@

%.o: %.c
	gcc -c $< -I inc/ -lm -lfftw3 -o $@

clean:
	rm -f $(OBJ) $(EXEOBJ) $(EXE)


