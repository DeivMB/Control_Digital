#include <stdio.h>
#include "pulsantes.h"
#include <Arduino.h>

typedef enum {
    ESTADO_INICIAL,
    ESTADO_UP,
    ESTADO_DOWN
} estado_t;

estado_t estadoActual;


void init_MEF(){
    estadoActual = ESTADO_INICIAL;   
}

int act_MEF(){
    switch (estadoActual)
    {
    case ESTADO_INICIAL:
        // inicializar hardware
        //Serial.println("Estado inicial");
        pinMode(SW1,INPUT_PULLUP);
        estadoActual = ESTADO_UP;
        return 1;
        break;
    case ESTADO_UP:
        //Serial.println("Estado up");
        if (digitalRead(SW1) == 0)
        {
            estadoActual = ESTADO_DOWN;
        }
        return 2;
        break;


    case ESTADO_DOWN:
        //Serial.println("Estado up");
        if (digitalRead(SW1) == 1)
        {
            estadoActual = ESTADO_UP;
        }
        return 3;
        break;
    default:
        init_MEF();
    }
}