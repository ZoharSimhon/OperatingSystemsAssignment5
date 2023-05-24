CC = gcc
FLAGS = -Wall -g -w
OBJECTS = helperFunctions.c ActiveObject.c Queue.c st_pipeline.c
HEADERS = ActiveObject.h Queue.h helperFunctions.h

all:main 

main: $(OBJECTS) $(HEADERS)
	$(CC) $(FLAGS) -o st_pipeline $(OBJECTS)

clean:
	rm st_pipeline