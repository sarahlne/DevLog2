CXXFLAGS= -Wall -O0 -g

objects = main.o Noeud.o  Valeur.o Variable.o Plus.o Moins.o Fois.o  Sur.o Fonction.o

all:main

main: $(objects)
	g++ -o main $(objects) $(CXXFLAGS)

main.o: main.cpp
Noeud.o: Noeud.cpp Noeud.h
Valeur.o: Valeur.cpp Valeur.h
Plus.o: Plus.cpp Plus.h
Variable.o: Variable.cpp Variable.h
Moins.o : Moins.cpp  Moins.h
Fois.o: Fois.cpp Fois.h
Sur.o: Sur.cpp Sur.h
Fonction.o: Fonction.cpp Fonction.h
%.o:%.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

clean:
	rm $(objects) main
leak:
	valgrind --leak-check=full ./main
