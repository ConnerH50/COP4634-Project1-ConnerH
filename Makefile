CXX = g++
CXXFLAGS = -std=c++11 -g -Wall 


OBJECTS = 

main:  $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o main final


