CC = clang++
CFLAGS = -g -Wall -std=c++17

main: main.o Machine.o MachineStates.o
	$(CC) $(CFLAGS) -o main main.o Machine.o MachineStates.o

main.o: main.cpp Machine.h MachineStates.h
	$(CC) $(CFLAGS) -c main.cpp

Machine.o: Machine.h MachineStates.h

MachineStates.o: Machine.h MachineStates.h

clean:
	$(RM) main
