/*
   MC145192.cpp - MC145192 PLL library

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */
#include "Arduino.h"
#include "SPI.h"
#include <MC145192.h>

MC145192::MC145192(byte cs_pin)
{
    _cs_pin = cs_pin;
    pinMode(_cs_pin, OUTPUT);
    digitalWrite(_cs_pin, HIGH);
}

void MC145192::write(unsigned long data)
{
    digitalWrite(_cs_pin, LOW);

    // MSB first
    for(int i = 2; i >= 0 ; i--)
    {
        SPI.transfer(lowByte(data >> 8 * i));
    }

    digitalWrite(_cs_pin, HIGH);
}
