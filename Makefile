SRCS := main.c \
	runner.c \
	config.c \
	errors.c \
	instructions/define.c \
	instructions/mov.c \
	instructions/helper.c

all:
	gcc $(SRCS) -O2 -march=native -o liveasm
