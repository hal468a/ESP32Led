#pragma once
#include <analogWrite.h>
#include "Color.h"

class Red : public Color
{
    public:
        void LightUp()
        {
            analogWrite(this->red, this->brigth);
            analogWrite(this->green, 255);
            analogWrite(this->blue, 255);
        }
};

class Green : public Color
{
    public:
        void LightUp()
        {
            analogWrite(this->green, this->brigth);
            analogWrite(this->red, 255);
            analogWrite(this->blue, 255);
        }
};

class Blue : public Color
{
    public:
        void LightUp()
        {
            analogWrite(this->blue, this->brigth);
            analogWrite(this->red, 255);
            analogWrite(this->green, 255);
        }
};

class Yellow : public Color
{
    public:
        void LightUp()
        {
            analogWrite(this->red, this->brigth);
            analogWrite(this->green, this->brigth);
            analogWrite(this->blue, 255);
        }
};

class White : public Color
{
    public:
        void LightUp()
        {
            analogWrite(this->red, this->brigth);
            analogWrite(this->green, this->brigth);
            analogWrite(this->blue, this->brigth);
        }
};

class NightLight : public Color
{
    public:
        void LightUp()
        {
            analogWrite(this->red, this->brigth / 2);
            analogWrite(this->green, this->brigth / 2);
	        analogWrite(this->blue, 240);
        }
};

class Neon_light : public Color
{
    public:
        void LightUp()
        {
            //red to green
            for(int i = 0; i <= 255; i+=5)
            {
                analogWrite(this->red, i);
                analogWrite(this->green, 255 - i);
                analogWrite(this->blue, 255);
                delay(10);
            }

            //green to red
            for(int i = 0; i <= 255; i+=5)
            {
                analogWrite(this->green, i);
                analogWrite(this->red, 255 - i);
                analogWrite(this->blue, 255);
                delay(10);
            }

            //red to blue
            for(int i = 0; i <= 255; i+=5)
            {
                analogWrite(this->red, i);
                analogWrite(this->blue, 255 - i);
                analogWrite(this->green, 255);
                delay(10);
            }

            //blue to green
            for(int i = 0; i <= 255; i+=5)
            {
                analogWrite(this->blue, i);
                analogWrite(this->green, 255 - i);
                analogWrite(this->red, 255);
                delay(10);
            }

            //green to blue
            for(int i = 0; i <= 255; i+=5)
            {
                analogWrite(this->green, i);
                analogWrite(this->blue, 255 - i);
                analogWrite(this->red, 255);
                delay(10);
            }

            //blue to red
            for(int i = 0; i <= 255; i+=5)
            {
                analogWrite(this->blue, i);
                analogWrite(this->red, 255 - i);
                analogWrite(this->green, 255);
                delay(10);
            }
        }
};