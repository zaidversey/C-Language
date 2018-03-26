#
# Simple Makefile
# application-specific settings and run target

EXE=main
TEST=date_test
TESTDEPS = dates.h
MODS=date.o
DEPS=date.h
LIBS=


default: $(EXE)

run: $(EXE)
	./$(EXE)

test: $(TEST)
	./$(TEST)


# compiler/linker settings

CC=gcc
CFLAGS=-g -O0 -Wall -pedantic -ansi
LDFLAGS=-g -O0

TESTCFLAGS=$(CFLAGS) -Wno-gnu-zero-variadic-macro-arguments 
TESTLIBS=-lcheck -lm -lpthread -lrt -lsubunit


# build targets

$(EXE): $(EXE).o $(MODS)
	$(CC) $(LDFLAGS) -o $(EXE) $^ $(LIBS)

$(TEST): $(TEST).o $(MODS)
	$(CC) $(TESTLDFLAGS) -o $(TEST) $^ $(LIBS) $(TESTLIBS)

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $<

$(TEST).o: $(TEST).c $(TESTDEPS)
	$(CC) -c $<

clean:
	rm -f $(EXE) $(EXE).o $(TEST) $(TEST).o $(MODS)

cleanrun: clean $(EXE) run
cleantest: clean $(TEST) test

.PHONY: default clean run cleanrun test cleantest

