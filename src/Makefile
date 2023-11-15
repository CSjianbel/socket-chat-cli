CC = gcc
FLAGS = -Wshadow -Wno-unused-result 

socket:
	$(CC) $(FLAGS) -c -O2 -o memory.o memory.c
	$(CC) $(FLAGS) -c -O2 -o server.o server.c
	$(CC) $(FLAGS) -c -O2 -o client.o client.c
	$(CC) $(FLAGS) -O2 memory.o server.o -o server.out
	$(CC) $(FLAGS) -O2 memory.o client.o -o client.out

# debug:
# 	$(CC) -c -O0 -ggdb3 -o memory.o memory.c
# 	$(CC) -O0 -ggdb3 -o server server.c
# 	$(CC) -O0 -ggdb3 -o client client.c

clean: 
	rm *.o 
	rm *.out
