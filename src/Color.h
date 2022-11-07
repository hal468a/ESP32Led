#pragma once
#include <iostream>
#include <Arduino.h>
#include <analogWrite.h>

//腳位顏色定義
class Color
{
    public:
        const int red = 2;
        const int green = 3;
        const int blue = 4;
        int brigth;

        virtual void LightUp() {};
        void TurnOff()
        {
            analogWrite(2, 255);
            analogWrite(3, 255);
            analogWrite(4, 255);
        }
};