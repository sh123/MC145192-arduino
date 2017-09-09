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

MC145192::MC145192(byte ss_pin)
{
    ss_pin_ = ss_pin;
    pinMode(ss_pin_, OUTPUT);
    digitalWrite(ss_pin_, HIGH);
}

void MC145192::set_registers(byte c, unsigned int r, unsigned long a)
{
    reg_c_ = c;
    reg_r_ = r;
    reg_a_ = a;

    write_registers();
}

void MC145192::write_registers()
{
    digitalWrite(ss_pin_, LOW);

    // MSB first
  
    // C, 1 byte
    SPI.transfer(reg_c_);

    // R, 2 bytes
    for(int i = 1; i >= 0 ; i--)
    {
        SPI.transfer(lowByte(reg_r_ >> 8 * i));
    }

    // A, 3 bytes
    for(int i = 2; i >= 0 ; i--)
    {
        SPI.transfer(lowByte(reg_a_ >> 8 * i));
    }

    digitalWrite(ss_pin_, HIGH);

}
