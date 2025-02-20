CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o clothing.o movie.o mydatastore.o book.o

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c amazon.cpp
user.o: user.cpp user.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c user.cpp
db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c db_parser.cpp
product.o: product.cpp product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp
product_parser.o: product_parser.cpp product_parser.h product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product_parser.cpp
util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c util.cpp
clothing.o: Clothing.cpp Clothing.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c Clothing.cpp
movie.o: Movie.cpp Movie.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c Movie.cpp
mydatastore.o: MyDataStore.cpp MyDataStore.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c MyDataStore.cpp
book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c Book.cpp

clean:
	rm -f *.o amazon
