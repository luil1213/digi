#include <xc.h>
#include <pic18f4550.h>  /*Header file PIC18f4550 definitions*/
#include "fuses.h"
#include "pinout.h"

#define _XTAL_FREQ  8000000

void secuencial_Efecto1(void);
void secuencial_Efecto2(void);
void secuencial_Efecto3(void);
void secuencial_Efecto4(void);
void secuencial_Efecto5(void);


unsigned char efecto = 1;
unsigned long velocidad = 1;

int main(void) {

    OSCCON = 0x72;
    PIN_LEDS = OUTPUT;
    LEDS = LOW;
    PIN_EFECTO = INPUT;
    PIN_VELOCIDAD = INPUT;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB4 = 1;
    INTCON2bits.RBPU = 0;
    while (1) {
        //efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==6){efecto=1;}
        }
        
        switch (efecto) {
            case 1: secuencial_Efecto1();
                break;
            case 2: secuencial_Efecto2();
                break;
            case 3: secuencial_Efecto3();
                break;
            case 4: secuencial_Efecto4();
                break;
            case 5: secuencial_Efecto5();
                break;    
        }
    }
    return 1;
}

void secuencial_Efecto1(void) {
    for (int i = 0; i < 8; i++) {
        LATD = 1 << i;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
    }
}

void secuencial_Efecto2(void) {
    for (int i = 0, j = 7; i < 8; i++, j--) {
        LATD = (1 << i) + (1 << j);
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
    }
}

void secuencial_Efecto3(void) {
    for (int i = 0; i < 9; i++) {
        LATD = (1 << i) - 1;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
    }
}

void secuencial_Efecto4(void) {
    volatile unsigned int m=0,n=0;
    for (int i = 0; i < 5; i++) {
        LATD = m+n;
        m += (1 << i) & 0x0f;
        n += (1 << (7-i)) & 0xf0;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
    }
}

void secuencial_Efecto5(void) {
    for (int i = 0; i < 4; i++) {
        LATD = (2 << i) - 1;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
    }
}