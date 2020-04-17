VERSION = debug

C_FLAGS = -g -Wall

CC = gcc

CUR_DIR = $(shell pwd)

#INC = -I./Macro 

#LIB += -lmysqlclient -L/usr/lib/mysql

.PHONEY : clean all

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)


TARGET = test

all : $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(C_FLAGS) $^ $(LIB) $(INC) -o $@

%.o:%.c
	$(CC) $(C_FLAGS) -c $< -o $@


clean:
	-rm *.o $(TARGET)
