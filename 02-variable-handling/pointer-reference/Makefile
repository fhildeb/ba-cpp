#Option zum erstellen mit
#Debug-Informationen für GDB
#Zeile 4 auskommentieren:
//DEBUG = -g

#Option zum Löschen von Objekt-
#und AutoSave-Dateien: 
#: make clear.PHONY: clean

#Makefiles erstellen:
#: make
generic:	generic.o helper.o tools.o
	g++ -o generic generic.o helper.o tools.o
	
generic.o:	generic.cxx tools.h
	g++ $(DEBUG) -c generic.cxx
	
helper.o:	helper.cxx helper.h
	g++ $(DEBUG) -c helper.cxx
	
tools.o:	tools.cxx tools.h helper.h
	g++ $(DEBUG) -c tools.cxx 
	
clean:
	rm -f *.o
	rm -f *~
	