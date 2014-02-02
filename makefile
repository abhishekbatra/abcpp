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
	@echo "Sources = "$(SOURCES)""
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -g -c -Wall -I$(INCDIR) $< -o $@
	@echo "Complete "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(LIBDIR)/$(TARGET).so
	@$(rm) $(OBJECTS)
