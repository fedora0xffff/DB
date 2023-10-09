CXX=g++
CXXFLAGS=-std=c++17 -Wall

SRC=condition_parser.cpp \
    condition_parser_test.cpp \
    database.cpp \
    database_test.cpp \
    date.cpp \
    main.cpp \
    node.cpp \
    token.cpp \
    UnitTestFramework.cpp

#OBJS=condition_parser.o condition_parser_test.o database.o database_test.o date.o main.o node.o token.o UnitTestFramework.o
OBJS=$(SRC:.cpp=.o)

all: $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) #$(LDFLAGS) $(LDLIBS)

$(OBJS): %.o: %.cpp

clean:
	rm -f *.o all

