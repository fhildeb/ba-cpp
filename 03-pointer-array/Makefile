APPNAME = pointer_array
OBJECTS = pointer_array.o

INCLUDES = -D_REENTRANT -I/usr/local/include

LIBS = -ldl -L/usr/lib -L/usr/lib -Wl,-rpath,/usr/lib

DEBUG = -g

$(APPNAME) : $(OBJECTS)
	g++ -o $(APPNAME) $(OBJECTS) $(LIBS)

pointer_array.o : pointer_array.cxx
	g++ -c $(DEBUG) $(INCLUDES) pointer_array.cxx

clean :
	rm -f $(OBJECTS)
	rm -f $(APPNAME)
	rm -f *~
