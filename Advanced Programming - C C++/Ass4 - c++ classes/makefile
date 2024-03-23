Ass4: Robot.o Map.o Game.o
	g++ Robot.o Map.o Game.o -o Ass4

Robot.o: Robot.cpp Robot.h
	g++ -c Robot.cpp
	
Map.o: Map.cpp Map.h
	g++ -c Map.cpp
	
Game.o: Game.cpp Map.h Robot.h
	g++ -c Game.cpp
clean:
	rm -f *.o
