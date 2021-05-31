#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL670 - Linguagens de Programação
# Prof. Miguel
# Autor: Leticia Tavares
# Descricao: arquivo de Makefile
#
#
# g++ -Wall main.cpp catalogo.cpp filme.cpp -o gerenciadorFilmes


#Compilar
CC = g++
LD = g++

#Linkeditar

CFLAGS = -Wall
LFLAGS = -Wall

#Dependencias
LAB07OBJS = main.o catalogo.o filme.o

LAB07 = gerenciadorFilmes
EXECS = $(LAB07)

ALL = $(EXECS)

#Regra Implicita

.cpp.o:
	$(CC)  $(CFLAGS) -c $<

all: $(ALL)

gerenciadorFilmes: $(LAB07OBJS)
	$(LD) $(LFLAGS) -o $@ $(LAB07OBJS)

clean:
	rm -f *.o $(EXECS)

clean-all:
	rm -f *.o $(EXECS)
