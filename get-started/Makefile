TARGET := 11_LED_Fade_Timer_PWM.elf
CC     := msp430-gcc
CFLAGS := -0s -Wall -mmcu=msp430g2553 -g -lc
OBJS   := 11_LED_Fade_Timer_PWM.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)

prog: $(TARGET)
	mspdebug tilib "prog $(TARGET)"
