CC = gcc
FLAGS = -Wshadow -Wno-unused-result 

socket:
	$(CC) $(FLAGS) -c -O2 -o memory.o memory.c
	$(CC) $(FLAGS) -c -O2 -o message.o message.c
	$(CC) $(FLAGS) -c -O2 -o server.o server.c
	$(CC) $(FLAGS) -c -O2 -o client.o client.c
	$(CC) $(FLAGS) -O2 memory.o server.o message.o -o server.out
	$(CC) $(FLAGS) -O2 memory.o client.o message.o -o client.out

debug:
	$(CC) $(FLAGS) -c -O0 -ggdb3 -o memory.o memory.c
	$(CC) $(FLAGS) -c -O0 -ggdb3 -o message.o message.c
	$(CC) $(FLAGS) -c -O0 -ggdb3 -o server.o server.c
	$(CC) $(FLAGS) -c -O0 -ggdb3 -o client.o client.c
	$(CC) $(FLAGS) -O0 -ggdb3 memory.o server.o message.o -o server.out
	$(CC) $(FLAGS) -O0 -ggdb3 memory.o client.o message.o -o client.out

clean: 
	rm *.o 
	rm *.out
