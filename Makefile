INCPATH = inc/
SRCPATH = src/
UNITTESTPATH = unittest/

CC = gcc
CFLAGS = -Wall -c

build: main.o serializer.o deserializer.o
	$(CC) $(CFALGS) main.o serializer.o deserializer.o -o build

main.o: $(SRCPATH)main.c $(INCPATH)main.h
	$(CC) $(CFLAGS) $(SRCPATH)main.c -I$(INCPATH)

serializer.o: $(SRCPATH)serializer.c $(INCPATH)main.h
	$(CC) $(CFLAGS) $(SRCPATH)serializer.c -I$(INCPATH)

deserializer.o: $(SRCPATH)deserializer.c $(INCPATH)main.h
	$(CC) $(CFLAGS) $(SRCPATH)deserializer.c -I$(INCPATH)

clean:
	rm build main.o serializer.o deserializer.o

run:
	$(CC) -Wall -o run $(UNITTESTPATH)unittest.c serializer.o deserializer.o -lcunit

uclean:
	rm run
