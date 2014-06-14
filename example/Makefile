default: example

SRCS=\
  main.c \
  help.c \
  opt_o.c \
  cfgopt.c \

OBJS=$(SRCS:.c=.o)

CFLAGS+= -I../include -pipe -g -std=c99 -O0

example: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.PHONY: clean
clean:
	-rm -f *.o example
