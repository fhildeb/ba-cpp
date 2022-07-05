APPNAME = generic
OBJECTS = generic.o

INCLUDES = -D_REENTRANT -I/usr/local/include

LIBS = -lpthread -ldl -L/usr/lib -L/usr/lib -Wl,-rpath,/usr/lib -lpthread -lXext

DEBUG = -g

$(APPNAME) : $(OBJECTS)
	g++ -o $(APPNAME) $(OBJECTS) $(LIBS)

generic.o : generic.cxx
	g++ -g -c $(DEBUG) $(INCLUDES) generic.cxx

disassemble :
	objdump -d -M intel -S generic.o

clean :
	rm -f $(OBJECTS)
	rm -f $(APPNAME)
	rm -f *~
