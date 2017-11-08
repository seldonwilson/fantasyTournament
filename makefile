main: main.o Die.o Creatures.o ioutil.o CreatureStack.o CreatureQueue.o testingSuite.o configureTeam.o fight.o
	g++ -g -Wextra -Wall -pedantic -std=c++11 main.o Creatures.o Die.o ioutil.o CreatureStack.o CreatureQueue.o testingSuite.o configureTeam.o fight.o -o main

main.o: main.cpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 main.cpp

Die.o: Die.cpp Die.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 Die.cpp

Creatures.o: Creatures.cpp Creatures.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 Creatures.cpp

ioutil.o: ioutil.cpp ioutil.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 ioutil.cpp

CreatureStack.o: CreatureStack.cpp CreatureStack.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 CreatureStack.cpp

CreatureQueue.o: CreatureQueue.cpp CreatureQueue.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 CreatureQueue.cpp

testingSuite.o: testingSuite.cpp testingSuite.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 testingSuite.cpp

configureTeam.o: configureTeam.cpp configureTeam.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 configureTeam.cpp

fight.o: fight.cpp fight.hpp
	g++ -g -c -Wextra -Wall -pedantic -std=c++11 fight.cpp

clean:
	rm *.o main