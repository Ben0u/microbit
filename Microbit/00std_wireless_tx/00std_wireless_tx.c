#include <nrf.h>
#include "nrf52833.h"

static uint8_t pdu1[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x31
};
static uint8_t pdu2[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x32
};
static uint8_t pdu3[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x33
};
static uint8_t pdu4[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x34
};
static uint8_t pdu5[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x35
};
static uint8_t pdu6[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x36
};
static uint8_t pdu7[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x37
};
static uint8_t pdu8[] = {
    0x00, // header
       6, // length
    0x00,0x00,0x00,0x00,0x00,0x38
};
uint32_t wait;
int compteur =1;
int main(void) {
    
    // configured HF clock
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
    NRF_RADIO->PCNF1         = (                    sizeof(pdu1) << RADIO_PCNF1_MAXLEN_Pos)         |
                               (                              0 << RADIO_PCNF1_STATLEN_Pos)        |
                               (                              3 << RADIO_PCNF1_BALEN_Pos)          |
                               (      RADIO_PCNF1_ENDIAN_Little << RADIO_PCNF1_ENDIAN_Pos)         |
                               (   RADIO_PCNF1_WHITEEN_Disabled << RADIO_PCNF1_WHITEEN_Pos);
    NRF_RADIO->BASE0         = 0xAAAAAAAAUL;
    NRF_RADIO->TXADDRESS     = 0UL;
    NRF_RADIO->RXADDRESSES   = (RADIO_RXADDRESSES_ADDR0_Enabled << RADIO_RXADDRESSES_ADDR0_Pos);
    NRF_RADIO->TIFS          = 1000U;
    NRF_RADIO->CRCCNF        = (         RADIO_CRCCNF_LEN_Three << RADIO_CRCCNF_LEN_Pos)           |
                               (     RADIO_CRCCNF_SKIPADDR_Skip << RADIO_CRCCNF_SKIPADDR_Pos);
    NRF_RADIO->CRCINIT       = 0xFFFFUL;
    NRF_RADIO->CRCPOLY       = 0x00065b; // CRC poly: x^16 + x^12^x^5 + 1
    NRF_RADIO->FREQUENCY     = 15;
    NRF_RADIO->PACKETPTR     = (uint32_t)pdu4;

    NRF_RADIO->INTENCLR = 0xffffffff;
    NRF_RADIO->SHORTS = (RADIO_SHORTS_READY_START_Enabled << RADIO_SHORTS_READY_START_Pos) |
                        (RADIO_SHORTS_END_DISABLE_Enabled << RADIO_SHORTS_END_DISABLE_Pos);
    NRF_RADIO->INTENSET = (RADIO_INTENSET_DISABLED_Enabled << RADIO_INTENSET_DISABLED_Pos);
    NVIC_EnableIRQ(RADIO_IRQn);

   while(1) {
        // send
       // NRF_RADIO->TASKS_TXEN = (RADIO_TASKS_TXEN_TASKS_TXEN_Trigger << RADIO_TASKS_TXEN_TASKS_TXEN_Pos);
        //NRF_RADIO->PACKETPTR     = (uint32_t)pdu7;
         NRF_RADIO->TASKS_TXEN = (RADIO_TASKS_TXEN_TASKS_TXEN_Trigger << RADIO_TASKS_TXEN_TASKS_TXEN_Pos);
        /*
        if (compteur==1){
         NRF_RADIO->PACKETPTR     = (uint32_t)pdu8;
         compteur++;
         }
         else{
         NRF_RADIO->PACKETPTR     = (uint32_t)pdu7;
         compteur--;
         }
         */
        while (NRF_RADIO->EVENTS_DISABLED != 0) {}
        // wait a bit
        wait = 0x00ffffff;
       // while (wait--);
       // NRF_RADIO->TASKS_TXEN = (RADIO_TASKS_TXEN_TASKS_TXEN_Trigger << RADIO_TASKS_TXEN_TASKS_TXEN_Pos);
       //  NRF_RADIO->PACKETPTR     = (uint32_t)pdu8;
         //NRF_RADIO->TASKS_TXEN = (RADIO_TASKS_TXEN_TASKS_TXEN_Trigger << RADIO_TASKS_TXEN_TASKS_TXEN_Pos);
         // NRF_RADIO->PACKETPTR     = (uint32_t)pdu6;
         
    }
}

void RADIO_IRQHandler(void) {
    if (NRF_RADIO->EVENTS_DISABLED) {
        NRF_RADIO->EVENTS_DISABLED = 0;
    }
}


