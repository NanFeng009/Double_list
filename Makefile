VERSION = debug

C_FLAGS = -g -Wall

CC = gcc

CUR_DIR = $(shell pwd)

INC = -I./src

#LIB += -lmysqlclient -L/usr/lib/mysql

.PHONEY : clean all

VPATH = src test

SRCS = list_t.c main.c hash_t.c

OBJS = $(SRCS:.c=.o)


TARGET = util 

all : $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(C_FLAGS) $^ $(LIB) $(INC) -o $@

%.o:%.c
	$(CC) $(C_FLAGS) $(INC) -c $< -o $@


clean:
	-rm *.o $(TARGET)
