SRCS := main.c \
	runner.c \
	config.c \
	errors.c \
	instructions/mov.c

all:
	gcc $(SRCS) -O2 -march=native -o liveasm
