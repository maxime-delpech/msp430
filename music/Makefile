TARGET := music.elf
CC     := msp430-gcc
CFLAGS := -0s -Wall -mmcu=msp430g2553 -g -lc
OBJS   := music.o

$(TARGET): $(OBJS)
	$(CC) -lm -o $(TARGET) $(CFLAGS) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)

prog: $(TARGET)
	mspdebug tilib "prog $(TARGET)"
