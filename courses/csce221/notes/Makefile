PROJ        = output.out
CXX         = g++
CXXFLAGS    = -g -Wall -std=c++11
OBJS        = driver.o Airplane.o

$(PROJ): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
Airplane.o: Airplane.cpp Airplane.h
	$(CXX) $(CXXFLAGS) -c $<
driver.o: driver.cpp Airplane.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean run valgrind finish
clean:
	rm $(OBJS)
	rm $(PROJ)
run: $(PROJ)
	./$(PROJ) $(PARAM)
valgrind: $(PROJ)
	valgrind ./$(PROJ) $(PARAM)
finish: #dependency list?
	#To-do
