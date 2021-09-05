CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/main
CFLAGS := -g

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

OPENCV := `pkg-config --cflags --libs opencv` 
LIBS := $(OPENCV)

all: $(TARGET)
	mkdir bin

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir $(BUILDDIR)
	$(CC) $(CFLAGS) $(LIB) $(INC)  -c -o $@ $< 