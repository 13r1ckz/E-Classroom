OBJS = curlrq.o  
CC = gcc
CFLAGS =
LFLAGS =
NAME = curlRequest


all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)  -o $(NAME)
curlrq.o : curlrq.cpp
	$(CC) $(CFLAGS) curlrq.cpp
clean : 
	\rm *.o $(NAME)
