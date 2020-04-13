EXEC = tc
TEST = text.tri

all: main.cpp
	g++ main.cpp -o $(EXEC)

test: all
	./tc $(TEST) 
	./Interpreter/tam ./temp.tam

compile:
	./tc $(TEST) 

run:
	./Interpreter/tam ./temp.tam

clean:
	rm $(EXEC) temp.tam

valgrind:
	valgrind ./tc $(TEST)
	valgrind ./Interpreter/tam ./temp.tam