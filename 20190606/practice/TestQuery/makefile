CC:=g++
CXXFLAGS:= -g -Wall
LIBS:= -llog4cpp -lpthread
OBJS:= Query.o TestQuery.o main.o

all:Query.exe TestQuery.exe Query_base.exe 
Query.exe: Query.o $(OBJS) 
		$(CC) -o $@ $^ $(CXXFLAGS)  $(LIBS)

TestQuery.exe:TestQuery.o $(OBJS) 
		$(CC) -o $@ $^ $(CXXFLAGS)  $(LIBS)

Query_base.exe:Query_base.o $(OBJS) 
		$(CC) -o $@ $^ $(CXXFLAGS)  $(LIBS)
