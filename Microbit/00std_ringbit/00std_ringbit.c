#include <stdio.h>
#include <nrf.h>
#include <string.h>
#include "nrf52833.h"

#define ROW1_DISCONNECT()    (NRF_P0->PIN_CNF[21]     = 0x00000002 )          // P0.21
#define ROW2_DISCONNECT()    (NRF_P0->PIN_CNF[22]     = 0x00000002 )          // P0.22
#define ROW3_DISCONNECT()    (NRF_P0->PIN_CNF[15]     = 0x00000002 )          // P0.15
#define ROW4_DISCONNECT()    (NRF_P0->PIN_CNF[24]     = 0x00000002 )          // P0.24
#define ROW5_DISCONNECT()    (NRF_P0->PIN_CNF[19]     = 0x00000002 )          // P0.19

#define ROW1_OUTPUT()        (NRF_P0->PIN_CNF[21]     = 0x00000003 )          // P0.21
#define ROW2_OUTPUT()        (NRF_P0->PIN_CNF[22]     = 0x00000003 )          // P0.22
#define ROW3_OUTPUT()        (NRF_P0->PIN_CNF[15]     = 0x00000003 )          // P0.15
#define ROW4_OUTPUT()        (NRF_P0->PIN_CNF[24]     = 0x00000003 )          // P0.24
#define ROW5_OUTPUT()        (NRF_P0->PIN_CNF[19]     = 0x00000003 )          // P0.19

#define ROW1_HIGH()          (NRF_P0->OUTSET          = (0x00000001 << 21) )   // P0.21
#define ROW2_HIGH()          (NRF_P0->OUTSET          = (0x00000001 << 22) )   // P0.22
#define ROW3_HIGH()          (NRF_P0->OUTSET          = (0x00000001 << 15) )   // P0.15
#define ROW4_HIGH()          (NRF_P0->OUTSET          = (0x00000001 << 24) )   // P0.24
#define ROW5_HIGH()          (NRF_P0->OUTSET          = (0x00000001 << 19) )   // P0.19
                        
#define COL1_DISCONNECT()    (NRF_P0->PIN_CNF[28]     = 0x00000002 )           // P0.28
#define COL2_DISCONNECT()    (NRF_P0->PIN_CNF[11]     = 0x00000002 )           // P0.11
#define COL3_DISCONNECT()    (NRF_P0->PIN_CNF[31]     = 0x00000002 )           // P0.31
#define COL4_DISCONNECT()    (NRF_P1->PIN_CNF[05]     = 0x00000002 )           // P1.05
#define COL5_DISCONNECT()    (NRF_P0->PIN_CNF[30]     = 0x00000002 )           // P0.30

#define COL1_OUTPUT()        (NRF_P0->PIN_CNF[28]     = 0x00000003 )           // P0.28
#define COL2_OUTPUT()        (NRF_P0->PIN_CNF[11]     = 0x00000003 )           // P0.11
#define COL3_OUTPUT()        (NRF_P0->PIN_CNF[31]     = 0x00000003 )           // P0.31
#define COL4_OUTPUT()        (NRF_P1->PIN_CNF[05]     = 0x00000003 )           // P1.05
#define COL5_OUTPUT()        (NRF_P0->PIN_CNF[30]     = 0x00000003 )           // P0.30
                             
#define COL1_LOW()           (NRF_P0->OUTCLR          = (0x00000001 << 28) )   // P0.28
#define COL2_LOW()           (NRF_P0->OUTCLR          = (0x00000001 << 11) )   // P0.11
#define COL3_LOW()           (NRF_P0->OUTCLR          = (0x00000001 << 31) )   // P0.31
#define COL4_LOW()           (NRF_P1->OUTCLR          = (0x00000001 << 05) )   // P1.05
#define COL5_LOW()           (NRF_P0->OUTCLR          = (0x00000001 << 30) )   // P0.30

typedef enum {
    LED11,LED12,LED13,LED14,LED15,
    LED21,LED22,LED23,LED24,LED25,
    LED31,LED32,LED33,LED34,LED35,
    LED41,LED42,LED43,LED44,LED45,
    LED51,LED52,LED53,LED54,LED55
} led_id_t;

const led_id_t LEDS_DEVANT[] = {
   
          LED22,      LED24,
    
          LED42,LED43,LED44

};

void leds_all_off(void) {
   
    ROW1_DISCONNECT();
    ROW2_DISCONNECT();
    ROW3_DISCONNECT();
    ROW4_DISCONNECT();
    ROW5_DISCONNECT();

    COL1_DISCONNECT();
    COL2_DISCONNECT();
    COL3_DISCONNECT();
    COL4_DISCONNECT();
    COL5_DISCONNECT();
}

void leds_on(led_id_t led_id) {
    
    switch(led_id) {
        
        case LED11: ROW1_OUTPUT(); ROW1_HIGH(); COL1_OUTPUT(); COL1_LOW(); break;
        case LED12: ROW1_OUTPUT(); ROW1_HIGH(); COL2_OUTPUT(); COL2_LOW(); break;
        case LED13: ROW1_OUTPUT(); ROW1_HIGH(); COL3_OUTPUT(); COL3_LOW(); break;
        case LED14: ROW1_OUTPUT(); ROW1_HIGH(); COL4_OUTPUT(); COL4_LOW(); break;
        case LED15: ROW1_OUTPUT(); ROW1_HIGH(); COL5_OUTPUT(); COL5_LOW(); break;

        case LED21: ROW2_OUTPUT(); ROW2_HIGH(); COL1_OUTPUT(); COL1_LOW(); break;
        case LED22: ROW2_OUTPUT(); ROW2_HIGH(); COL2_OUTPUT(); COL2_LOW(); break;
        case LED23: ROW2_OUTPUT(); ROW2_HIGH(); COL3_OUTPUT(); COL3_LOW(); break;
        case LED24: ROW2_OUTPUT(); ROW2_HIGH(); COL4_OUTPUT(); COL4_LOW(); break;
        case LED25: ROW2_OUTPUT(); ROW2_HIGH(); COL5_OUTPUT(); COL5_LOW(); break;

        case LED31: ROW3_OUTPUT(); ROW3_HIGH(); COL1_OUTPUT(); COL1_LOW(); break;
        case LED32: ROW3_OUTPUT(); ROW3_HIGH(); COL2_OUTPUT(); COL2_LOW(); break;
        case LED33: ROW3_OUTPUT(); ROW3_HIGH(); COL3_OUTPUT(); COL3_LOW(); break;
        case LED34: ROW3_OUTPUT(); ROW3_HIGH(); COL4_OUTPUT(); COL4_LOW(); break;
        case LED35: ROW3_OUTPUT(); ROW3_HIGH(); COL5_OUTPUT(); COL5_LOW(); break;

        case LED41: ROW4_OUTPUT(); ROW4_HIGH(); COL1_OUTPUT(); COL1_LOW(); break;
        case LED42: ROW4_OUTPUT(); ROW4_HIGH(); COL2_OUTPUT(); COL2_LOW(); break;
        case LED43: ROW4_OUTPUT(); ROW4_HIGH(); COL3_OUTPUT(); COL3_LOW(); break;
        case LED44: ROW4_OUTPUT(); ROW4_HIGH(); COL4_OUTPUT(); COL4_LOW(); break;
        case LED45: ROW4_OUTPUT(); ROW4_HIGH(); COL5_OUTPUT(); COL5_LOW(); break;

        case LED51: ROW5_OUTPUT(); ROW5_HIGH(); COL1_OUTPUT(); COL1_LOW(); break;
        case LED52: ROW5_OUTPUT(); ROW5_HIGH(); COL2_OUTPUT(); COL2_LOW(); break;
        case LED53: ROW5_OUTPUT(); ROW5_HIGH(); COL3_OUTPUT(); COL3_LOW(); break;
        case LED54: ROW5_OUTPUT(); ROW5_HIGH(); COL4_OUTPUT(); COL4_LOW(); break;
        case LED55: ROW5_OUTPUT(); ROW5_HIGH(); COL5_OUTPUT(); COL5_LOW(); break;
    }
}


static uint8_t pdu[8+1] = { 0 };

/*
sources:
    https://wiki.elecfreaks.com/en/microbit/microbit-smart-car/microbit-ringbit-car-v2/
    https://github.com/elecfreaks/circuitpython_ringbit/blob/main/ringbit.py
    https://github.com/elecfreaks/pxt-ringbitcar-old/blob/master/ringbitcar.ts
    https://learn.adafruit.com/adafruit-neopixel-uberguide/advanced-coding#writing-your-own-library-2894697
    
    servos
        left ==P1 onthe micro:bit silkscreen==P0.03 on the nRF (RING1 line on schematic)
        right==P2 onthe micro:bit silkscreen==P0.04 on the nRF (RING2 line on schematic)
    per https://shop.elecfreaks.com/products/elecfreaks-360-digital-servo-with-wheel-and-tire-ef90d
        looks like
            max backwards rotation speed: pulse width of  500us
                       no rotation speed: pulse width of 1500us
            max forwards  rotation speed: pulse width of 2500us

    LEDs
        NeoPixel connected to P0 onthe micro:bit silkscreen==P0.02 on the nRF (RING0 line on schematic)
*/

#define SPEED_FORWARD   12000
#define SPEED_NONE      10000
#define SPEED_BACKWARD   8000

#define PIN_MOTOR_LEFT  3
#define PIN_MOTOR_RIGHT 3

uint16_t left_motor_pwm_comp[1];
uint16_t right_motor_pwm_comp[1];

void motor_left_init(void) {
    // configure P0.03 as output
    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ...A A: DIR:     1=Output
    // .... .... .... .... .... .... .... ..B. B: INPUT:   1=Disconnect
    // .... .... .... .... .... .... .... CC.. C: PULL:    0=Disabled
    // .... .... .... .... .... .DDD .... .... D: DRIVE:   0=S0S1
    // .... .... .... ..EE .... .... .... .... E: SENSE:   0=Disabled
    // xxxx xxxx xxxx xx00 xxxx xxxx xxxx 0011 
    //    0    0    0    0    0    0    0    3 0x00000003
    NRF_P0->PIN_CNF[3]            = 0x00000003;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... ...A AAAA A: PIN:      00 (P0.00)
    // .... .... .... .... .... .... ..B. .... B: PORT:     0  (P0.00)
    // C... .... .... .... .... .... .... .... C: CONNECT:  0=Connected
    // 0xxx xxxx xxxx xxxx xxxx xxxx xx00 0011 
    //    0    0    0    0    0    0    0    3 0x00000003
    NRF_PWM0->PSEL.OUT[0]         = 0x00000003;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ...A A: ENABLE:   1=Enabled
    // 0xxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1 
    //    0    0    0    0    0    0    0    1 0x00000001
    NRF_PWM0->ENABLE              = 0x00000001;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ...A A: UPDOWN:   0=Up
    // 0xxx xxxx xxxx xxxx xxxx xxxx xxxx xxx0 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->MODE                = 0x00000000;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... .AAA A: PRESCALER: 2=DIV_4
    // 0xxx xxxx xxxx xxxx xxxx xxxx xxxx x000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->PRESCALER           = 2;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... AAAA AAAA AAAA AAAA A: CNT:      0=Disabled
    // 0xxx xxxx xxxx xxxx 0000 0000 0000 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->LOOP                = 0x00000000;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... .... .... .... .... .... ..AA A: LOAD:     0=Common
    // .... .... .... .... .... ...B .... .... B: MODE:     0=RefreshCount
    // 0xxx xxxx xxxx xxxx xxxx xxx0 xxxx xx00 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->DECODER             = 0x00000000;
    NRF_PWM0->SEQ[0].PTR          = (uint32_t)(left_motor_pwm_comp);
    NRF_PWM0->SEQ[0].CNT          = (sizeof(left_motor_pwm_comp) / sizeof(uint16_t));

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... AAAA AAAA AAAA AAAA AAAA AAAA A: CNT:      0=Continuous
    // 0xxx xxxx 0000 0000 0000 0000 0000 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->SEQ[0].REFRESH      = 0;

    //  3           2            1           0
    // 1098 7654 3210 9876 5432 1098 7654 3210
    // .... .... AAAA AAAA AAAA AAAA AAAA AAAA A: CNT
    // 0xxx xxxx 0000 0000 0000 0000 0000 0000 
    //    0    0    0    0    0    0    0    0 0x00000000
    NRF_PWM0->SEQ[0].ENDDELAY     = 0;

    NRF_PWM0->COUNTERTOP          = 16000; // 16000@4MHz==4000us
    //left_motor_pwm_comp[0]        =  2000; //  2000@4MHz== 500us
    left_motor_pwm_comp[0]        = 10000; //  10000@4MHz==2500us
    //left_motor_pwm_comp[0]        = 10000; // 10000@4MHz==2500us

    NRF_PWM0->EVENTS_SEQSTARTED[0]=0;
    NRF_PWM0->TASKS_SEQSTART[0]   = 0x00000001;
    while(NRF_PWM0->EVENTS_SEQSTARTED[0]==0);
}

void motor_left_speed(uint16_t speed) {
    
    if(NRF_PWM0->EVENTS_SEQSTARTED[0]==1) {
        NRF_PWM0->EVENTS_STOPPED  = 0;
        NRF_PWM0->TASKS_STOP      = 0x00000001;
        while(NRF_PWM0->EVENTS_STOPPED==0);
    }

    left_motor_pwm_comp[0]        = speed;

    NRF_PWM0->EVENTS_SEQSTARTED[0]=0;
    NRF_PWM0->TASKS_SEQSTART[0]   = 0x00000001;
    while(NRF_PWM0->EVENTS_SEQSTARTED[0]==0);
}

void motor_right_init(void) {
    
    NRF_P0->PIN_CNF[4]            = 0x00000003;
    NRF_PWM1->PSEL.OUT[0]         = 0x00000004;
    NRF_PWM1->ENABLE              = 0x00000001;
    NRF_PWM1->MODE                = 0x00000000;
    NRF_PWM1->PRESCALER           = 2;
    NRF_PWM1->LOOP                = 0x00000000;
    NRF_PWM1->DECODER             = 0x00000000;
    NRF_PWM1->SEQ[0].PTR          = (uint32_t)(right_motor_pwm_comp);
    NRF_PWM1->SEQ[0].CNT          = (sizeof(right_motor_pwm_comp) / sizeof(uint16_t));
    NRF_PWM1->SEQ[0].REFRESH      = 0;
    NRF_PWM1->SEQ[0].ENDDELAY     = 0;
    NRF_PWM1->COUNTERTOP          = 16000;
}

void motor_right_speed(uint16_t speed) {

    if(NRF_PWM1->EVENTS_SEQSTARTED[0]==1) {
        NRF_PWM1->EVENTS_STOPPED  = 0;
        NRF_PWM1->TASKS_STOP      = 0x00000001;
        while(NRF_PWM1->EVENTS_STOPPED==0);
    }

    right_motor_pwm_comp[0]       = speed;

    NRF_PWM1->EVENTS_SEQSTARTED[0]=0;
    NRF_PWM1->TASKS_SEQSTART[0]   = 0x00000001;
    while(NRF_PWM1->EVENTS_SEQSTARTED[0]==0);
}


int main(void) {
    // confiureg HF clock
    NRF_CLOCK->TASKS_HFCLKSTART = 1;
    while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0) {}

    // configure radio
    NRF_RADIO->MODE          = (  RADIO_MODE_MODE_Ble_LR125Kbit << RADIO_MODE_MODE_Pos);
    NRF_RADIO->TXPOWER       = (  RADIO_TXPOWER_TXPOWER_Pos8dBm << RADIO_TXPOWER_TXPOWER_Pos);
    NRF_RADIO->PCNF0         = (                              8 << RADIO_PCNF0_LFLEN_Pos)          |
                               (                              1 << RADIO_PCNF0_S0LEN_Pos)          |
                               (                              0 << RADIO_PCNF0_S1LEN_Pos)          |
                               (                              2 << RADIO_PCNF0_CILEN_Pos)          |
                               (     RADIO_PCNF0_PLEN_LongRange << RADIO_PCNF0_PLEN_Pos)           |
                               (                              3 << RADIO_PCNF0_TERMLEN_Pos);
    NRF_RADIO->PCNF1         = (                    sizeof(pdu) << RADIO_PCNF1_MAXLEN_Pos)         |
                               (                              0 << RADIO_PCNF1_STATLEN_Pos)        |
                               (                              3 << RADIO_PCNF1_BALEN_Pos)          |
                               (      RADIO_PCNF1_ENDIAN_Little << RADIO_PCNF1_ENDIAN_Pos)         |
                               (   RADIO_PCNF1_WHITEEN_Disabled << RADIO_PCNF1_WHITEEN_Pos);
    NRF_RADIO->BASE0         = 0xAAAAAAAAUL;
    NRF_RADIO->TXADDRESS     = 0UL;
    NRF_RADIO->RXADDRESSES   = (RADIO_RXADDRESSES_ADDR0_Enabled << RADIO_RXADDRESSES_ADDR0_Pos);
    NRF_RADIO->TIFS          = 0;
    NRF_RADIO->CRCCNF        = (         RADIO_CRCCNF_LEN_Three << RADIO_CRCCNF_LEN_Pos)           |
                               (     RADIO_CRCCNF_SKIPADDR_Skip << RADIO_CRCCNF_SKIPADDR_Pos);
    NRF_RADIO->CRCINIT       = 0xFFFFUL;
    NRF_RADIO->CRCPOLY       = 0x00065b; // CRC poly: x^16 + x^12^x^5 + 1
    NRF_RADIO->FREQUENCY     = 15;
    NRF_RADIO->PACKETPTR     = (uint32_t)pdu;

    // receive
    NRF_RADIO->SHORTS = (RADIO_SHORTS_READY_START_Enabled << RADIO_SHORTS_READY_START_Pos) |
                        (RADIO_SHORTS_END_DISABLE_Enabled << RADIO_SHORTS_END_DISABLE_Pos) |
                        (RADIO_SHORTS_DISABLED_RXEN_Enabled << RADIO_SHORTS_DISABLED_RXEN_Pos);
    NRF_RADIO->TASKS_RXEN    = 1;

    NRF_RADIO->INTENCLR = 0xffffffff;
    NVIC_EnableIRQ(RADIO_IRQn);
    NRF_RADIO->INTENSET = (RADIO_INTENSET_DISABLED_Enabled << RADIO_INTENSET_DISABLED_Pos);

    motor_left_init();
    motor_right_init();

    while(1) {
        __WFE();
    }
    
}

uint8_t i;

void RADIO_IRQHandler(void) {
    if (NRF_RADIO->EVENTS_DISABLED) {
        NRF_RADIO->EVENTS_DISABLED = 0;

        if (NRF_RADIO->CRCSTATUS != RADIO_CRCSTATUS_CRCSTATUS_CRCOk) {
            puts("Invalid CRC");
        } else {
            printf("Received packet (%dB): %s\n", pdu[1], &pdu[7]);

            i=0;

            while ((i+1)sizeof(LEDS_DEVANT)) {
              leds_on(LEDS_DEVANT[i]);
              i = (i+1)%sizeof(LEDS_DEVANT);
            }
  
            //printf("%s",pdu[7]);
            switch (pdu[7]) {
              case 0x31: //Devant, a gauche
                motor_right_speed(SPEED_NONE);
                motor_left_speed(SPEED_FORWARD);

                break;
              case 0x32: //Devant
                motor_right_speed(SPEED_BACKWARD);
                motor_left_speed(SPEED_FORWARD);
                
                break;
              case 0x33: //Devant, a droite 
                motor_right_speed(SPEED_BACKWARD);
                motor_left_speed(SPEED_NONE);

                break;
              case 0x34: //Derrière, a gauche
                motor_right_speed(SPEED_NONE);
                motor_left_speed(SPEED_BACKWARD);

                break;
              case 0x35: //Derrière
                motor_right_speed(SPEED_FORWARD);
                motor_left_speed(SPEED_BACKWARD);

                break;
              case 0x36: //Derrière, a droite
                motor_right_speed(SPEED_FORWARD);
                motor_left_speed(SPEED_NONE);

                break;
              case 0x37: //Arret
                motor_right_speed(SPEED_NONE);
                motor_left_speed(SPEED_NONE);
                leds_all_off();
                break;
              case 0x38:
                break;
              case 0x39:
                break;
            }
            
        }
    }
}
