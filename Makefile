SRCS := main.c runner.c config.c

all:
	gcc $(SRCS) -O2 -march=native -o liveasm
