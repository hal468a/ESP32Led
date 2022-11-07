#include <Arduino.h>
#include <iostream>
#include <analogWrite.h>
#include "Controller.h"

void Event_Listener();

Controller ctr;

Red *red = new Red();
Green *green = new Green();
Blue *blue = new Blue();
Yellow *yellow = new Yellow();
White *white = new White();
NightLight *nightlight = new NightLight();
Neon_light *neon = new Neon_light();

// 紀錄目前的燈光顏色預設為white.
Color *c = white;

const int Voltage_12V = 1;

void setup()
{
	Serial.begin(9600);
	digitalWrite(Voltage_12V, HIGH);
  	pinMode(Voltage_12V, OUTPUT);

    //RGB腳位
  	pinMode(2, OUTPUT);
  	pinMode(3, OUTPUT);
  	pinMode(4, OUTPUT);

	pinMode(ctr.IO1, INPUT); //15
	pinMode(ctr.IO2, INPUT); //14
	pinMode(ctr.IO3, INPUT); //13
	pinMode(ctr.IO4, INPUT); //12
	pinMode(ctr.IO5, INPUT); //11
	pinMode(ctr.IO6, INPUT); //10
	pinMode(ctr.IO7, INPUT); //9
	pinMode(ctr.IO8, INPUT); //8
}

void loop()
{
    ctr.IOMonitor();
    Event_Listener();
}

void Event_Listener()
{
    if(digitalRead(ctr.IO1) == 1 && digitalRead(ctr.IO2) == 0 && digitalRead(ctr.IO3) == 0 && digitalRead(ctr.IO4) == 0 && digitalRead(ctr.IO5) == 0)
    {
        Serial.println("開燈");
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO2) == 1 && digitalRead(ctr.IO1) == 0)
    {
        c = white;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO3) == 1 && digitalRead(ctr.IO1) == 0)
    {
        c = red;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO4) == 1 && digitalRead(ctr.IO1) == 0)
    {
        c = blue;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO5) == 1 && digitalRead(ctr.IO1) == 0)
    {
        c = green;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO6) == 1)
    {
        c = yellow;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO7) == 1)
    {
        c = neon;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO8) == 1)
    {
        c = nightlight;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO1) == 1 && digitalRead(ctr.IO2) == 1)
    {
        c->TurnOff();
    }
    else if(digitalRead(ctr.IO1) == 1 && digitalRead(ctr.IO3) == 1)
    {
        Serial.println("變亮");
        c->brigth = 1;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO1) == 1 && digitalRead(ctr.IO4) == 1)
    {
        Serial.println("變暗");
        c->brigth = 230;
        ctr.LightUp(c);
    }
    else if(digitalRead(ctr.IO1) == 1 && digitalRead(ctr.IO5) == 1)
    {
        Serial.println("唱歌中...");
    }
    // else if(digitalRead(ctr.IO1) == 0 && digitalRead(ctr.IO2) == 0 && digitalRead(ctr.IO3) == 0 && digitalRead(ctr.IO4) == 0 
    //              && digitalRead(ctr.IO5) == 0 && digitalRead(ctr.IO6) == 0 && digitalRead(ctr.IO7) == 0 && digitalRead(ctr.IO8) == 0)
    // {
    //      //把關燈設成00000000
    //      c->TurnOff();
    // }
}