TARGET = libabcpp

CC = g++

rm = rm -f
SRCDIR = src
INCDIR = inc
OBJDIR = obj
LIBDIR = lib

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(LIBDIR)/$(TARGET).so

$(LIBDIR)/$(TARGET).so: $(OBJECTS)
	g++ -shared -Wl,-soname,$(TARGET).so -o $(LIBDIR)/$(TARGET).so $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCDIR)/%.h
	g++ -g -fPIC -c -Wall -I$(INCDIR) $< -o $@

.PHONEY: clean
clean:
	@$(rm) $(LIBDIR)/$(TARGET).so
	@$(rm) $(OBJECTS)
