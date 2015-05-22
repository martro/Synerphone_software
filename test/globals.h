volatile unsigned char keyboard_int, pressed, keyboard_ready, toggle, CAPS;
volatile unsigned char received[40], usart_received[40];
volatile unsigned char to_send[40];
volatile unsigned char usart_receive_index;
volatile unsigned char usart_transmit_index;
volatile unsigned char mode;
volatile unsigned char LCD_top[17];
volatile unsigned char LCD_bottom[17];
volatile unsigned char ready_to_send;



