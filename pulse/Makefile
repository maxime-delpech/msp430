TARGET := pulse.elf
CC     := msp430-gcc
CFLAGS := -0s -Wall -mmcu=msp430g2553 -g -lc
OBJS   := pulse.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)

prog: $(TARGET)
	mspdebug tilib "prog $(TARGET)"
