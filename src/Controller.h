#pragma once
#include <iostream>
#include <Arduino.h>

#include "Color.h"
#include "Colors.h"

class Controller
{
    public:
        const int IO1 = 15;
        const int IO2 = 14;
        const int IO3 = 13;
        const int IO4 = 12;
        const int IO5 = 11;
        const int IO6 = 10;
        const int IO7 = 9;
        const int IO8 = 8;

        void IOMonitor()
        {
            Serial.printf("IO1: %d\n", digitalRead(this->IO1));
            Serial.printf("IO2: %d\n", digitalRead(this->IO2));
            Serial.printf("IO3: %d\n", digitalRead(this->IO3));
            Serial.printf("IO4: %d\n", digitalRead(this->IO4));
            Serial.printf("IO5: %d\n", digitalRead(this->IO5));
            Serial.printf("IO6: %d\n", digitalRead(this->IO6));
            Serial.printf("IO7: %d\n", digitalRead(this->IO7));
            Serial.printf("IO8: %d\n", digitalRead(this->IO8));
            Serial.println("-------------------------");
            delay(500);
        }

        void LightUp(Color *color)
        {
            color->LightUp();
        }
};