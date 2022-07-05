SRCDIR=./
APPNAME=hello

VPATH=$(SRCDIR)

HDR=$(wildcard $(SRCDIR)/*.h)

LDLIBS=-lOpenCL -lSDL -L/usr/X11R6/lib -lX11 -lXext
INC_DIR=/opt/intel/opencl/include
LINK_DIR=/opt/intel/opencl/lib64

$(APPNAME): $(APPNAME).o
	g++ -L$(LINK_DIR) -o $(APPNAME) $(APPNAME).o -Wl,-rpath,$(LINK_DIR) -L$(LINK_DIR) $(LDLIBS)

$(APPNAME).o: $(APPNAME).cxx
	g++ -c -I $(INC_DIR) $(APPNAME).cxx

cl_compile:
	./bin/ioc64.bin -cmd=build -input=./hello.cl

clean:
	$(RM) $(APPNAME).o $(APPNAME) *~*
