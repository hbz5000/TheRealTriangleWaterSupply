CC=g++
#the following is for normal use:
CFLAGS=-O3 -Wall

#the following is for using gprof:
#CFLAGS=-g -O0
#LDFLAGS=-pg 

# List of sources and objects (include all .cpp files)
SOURCES=$(wildcard *.cpp)
SOURCESC = Borg-1.6/borgms.c Borg-1.6/mt19937ar.c
OBJECTS=$(SOURCES:.cpp=.o)
OBJECTS+=$(SOURCESC:.c=.o)

TARGET=triangleSimulation
LIBS=-lm

all: $(SOURCES) $(TARGET)

parallel: CC=mpiCC
parallel: INCL_DIR=./Borg-1.6/
parallel: CFLAGS += -DPARALLEL
parallel: all

debug: CFLAGS=-O3
debug: CFLAGS += -g
debug: all

# How to make objects and executables
.cpp.o:
	$(CC) -c $(CFLAGS) $^ -o $@ -I$(INCL_DIR)

.c.o:
	$(CC) -c $(CFLAGS) $^ -o $@ -I$(INCL_DIR)
	
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(CFLAGS) -o $@ -I$(INCL_DIR) -L$(LIB_DIR) $(LIBS) $(DEFINES)

clean:
	rm -rf *.o Borg-1.6/*.o $(TARGET)
