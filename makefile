OBJS = bin/main.o bin/Server.o 
CC = gcc
CFLAGS = -Wall -c  
LFLAGS = -Wall
NAME = bin/server


all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)  -o $(NAME)
run: all
	sudo $(NAME) "localhost" "420"
clean : 
	\rm bin/*.o $(NAME)
bin/main.o : src/main.cpp src/main.h src/Server/Server.h   
	$(CC) $(CFLAGS) src/main.cpp -o bin/main.o
bin/Server.o : src/Server/Server.cpp src/Server/Server.h   
	$(CC) $(CFLAGS) src/Server/Server.cpp -o bin/Server.o
