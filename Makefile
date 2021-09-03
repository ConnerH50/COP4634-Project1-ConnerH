CXX = g++
CXXFLAGS = -std=c++11 -g -Wall 


OBJECTS = parse.o 

main:  $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o main final


