APPNAME = params
OBJECTS = params.o

INCLUDES = -D_REENTRANT -I/usr/local/include

LIBS = -ldl -L/usr/lib -L/usr/lib -Wl,-rpath,/usr/lib

DEBUG = -g

$(APPNAME) : $(OBJECTS)
	g++ -o $(APPNAME) $(OBJECTS) $(LIBS)

params.o : params.cxx
	g++ -c $(DEBUG) $(INCLUDES) params.cxx

clean :
	rm -f $(OBJECTS)
	rm -f $(APPNAME)
	rm -f *~
