CC:=gcc
SOURCEDIR:=src
SOURCES:=src/std.c src/strings.c src/various.c
OBJECTSDIR:=obj
OBJECTS:=obj/std.o obj/strings.o obj/various.o
LIB:=libvarious.so
LIBVER:=0.3
LIBSUBVER:=1
SONAME:=$(LIB).$(LIBVER)
LIBNAME:=$(LIB).$(LIBVER).$(LIBSUBVER)
INSTALL_DIR:=${HOME}/.local/lib
CFLAGS:=-Wall -fPIC
LDFLAGS:=-shared -Wl,-soname,$(SONAME)

.PHONY: all build build-debug install uninstall clean clean-all

all: build

build: $(LIBNAME)

build-debug: CFLAGS += -ggdb
build-debug: $(LIBNAME)


$(LIBNAME): $(OBJECTSDIR) $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)
	ln -sf $(LIBNAME) $(SONAME)
	ln -sf $(SONAME) $(LIB)

obj/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -c $< -o $@

src/%.c:
	$(error File $@ not found)

$(SOURCEDIR):
	$(error Source files directory not found)

$(OBJECTSDIR): $(SOURCEDIR)
	mkdir -p $@

install: $(LIBNAME)
	mkdir -p $(INSTALL_DIR)
	install -C $(LIBNAME) $(INSTALL_DIR)
	ln -sf $(LIBNAME) $(INSTALL_DIR)/$(SONAME)
	ln -sf $(SONAME) $(INSTALL_DIR)/$(LIB)

uninstall:
	rm -rf $(INSTALL_DIR)/$(LIB)*

clean:
	rm -rf ./obj/*.o ./obj *~ core

clean-all: clean
	rm -f $(LIB)*