CC = c++
VERSION = -std=c++11
# CFLAGS =  -Wall -Wextra -Werror

src = src/stackTest.cpp 

all: $(src) src/*.hpp
	$(CC) $(VERSION) $(CFLAGS)  -o main $(src) 

exec: all
	./main