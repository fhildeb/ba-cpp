APPNAME = generic
OBJECTS = generic.o

INCLUDES = -D_REENTRANT -I/usr/local/include

LIBS = -lpthread -ldl -L/usr/lib -L/usr/lib -Wl,-rpath,/usr/lib -lpthread -lXext

DEBUG = -g

$(APPNAME) : $(OBJECTS)
	g++ -o $(APPNAME) $(OBJECTS) $(LIBS)

generic.o : generic.cxx
	g++ -std=c++11 -c $(DEBUG) $(INCLUDES) generic.cxx

clean :
	rm -f $(OBJECTS)
	rm -f $(APPNAME)
	rm -f *~
