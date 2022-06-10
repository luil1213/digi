#ifndef PINOUT_H
#define	PINOUT_H

#ifdef	__cplusplus
extern "C" {
#endif
#define _BOTONES
#define _DIPSWITCH    
    
#ifdef  _BOTONES
    
#define PIN_VELOCIDAD TRISBbits.TRISB7
#define PIN_EFECTO TRISBbits.TRISB6
#define BTN_EFECTO PORTBbits.RB7
#define BTN_VELOCIDAD PORTBbits.RB6
#endif    
    
#ifdef  _DIPSWITCH    
#define PIN_EFECTO1 TRISBbits.TRISB7
#define PIN_EFECTO2 TRISBbits.TRISB6
#define PIN_EFECTO3 TRISBbits.TRISB5
#define PIN_EFECTO4 TRISBbits.TRISB4
    
#define BTN_EFECTO1 PORTBbits.RB7
#define BTN_EFECTO2 PORTBbits.RB6
#define BTN_EFECTO3 PORTBbits.RB5
#define BTN_EFECTO4 PORTBbits.RB4    
#endif    
    
#define PIN_LEDS TRISD
#define LEDS LATD


#define INPUT 1
#define OUTPUT 0

#define HIGH 1
#define LOW 0
    

#ifdef	__cplusplus
}
#endif

#endif	/* PINOUT_H */


