# Makefile for the 'Binary Calculator' project.

EXECUTABLE = bin_calc

.PHONY: all clean run
# Phony purposes.
all: $(EXECUTABLE)
clean: 
	rm $(EXECUTABLE) *.o
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Actual purposes.	
calculator.o: calculator.c
	gcc -c calculator.c
operations.o: operations.c
	gcc -c operations.c
$(EXECUTABLE): calculator.o operations.o
	gcc calculator.o operations.o -o $(EXECUTABLE)
