#ifndef SERIAL_H
#define SERIAL_H

// Init serial peripherals
void dbg_print_uart_init(void);

// Serial printf
void print2uart(char *format, ...);

// Serial print single character
void print2uartc(char c);

// dummy function
void dummyprint(char *format, ...);

// Put a string to serial
void print2uartlength(char *str, int length);

// Convert integer to a string
char *convert(unsigned int num, int base);

// Convert long integer to a string
char *convertl(unsigned long num, int base);

#endif // SERIAL_H
