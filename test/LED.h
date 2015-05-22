#define LED_Red_DIR  	DDRC
#define LED_Red_PORT 	PORTC
#define LED_Red_PIN  	PINC
#define LED_Red	 		(1 << PC3)

#define LED_Grn_DIR  	DDRC
#define LED_Grn_PORT 	PORTC
#define LED_Grn_PIN  	PINC
#define LED_Grn	 		(1 << PC2)




#define LED_Red_ON()	(LED_Red_PORT |= LED_Red)
#define LED_Red_OFF()	(LED_Red_PORT &= ~LED_Red)

#define LED_Grn_ON() 	(LED_Grn_PORT |= LED_Grn)
#define LED_Grn_OFF() 	(LED_Grn_PORT &= ~LED_Grn)


void LEDs_init()
{
	LED_Red_DIR|= LED_Red;
	LED_Grn_DIR|= LED_Grn;
}
