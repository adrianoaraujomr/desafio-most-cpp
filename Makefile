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

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(LIB) $(INC)  -c -o $@ $< 