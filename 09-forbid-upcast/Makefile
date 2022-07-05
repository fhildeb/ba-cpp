APPNAME = generic
OBJECTS = generic.o

INCLUDES = -D_REENTRANT -I/usr/local/include

LIBS = -lpthread -ldl -L/usr/lib -L/usr/lib -Wl,-rpath,/usr/lib -lXext

DEBUG = -g

$(APPNAME) : $(OBJECTS)
	g++ -o $(APPNAME) $(OBJECTS) $(LIBS) -std=c++11

generic.o : generic.cxx
	g++ -c $(DEBUG) $(INCLUDES) generic.cxx -std=c++11

disassemble:
	objdump -d -M intel -S generic.o

clean :
	rm -f $(OBJECTS)
	rm -f $(APPNAME)
	rm -f *~
