/* 
   MC145192.h - MC145192 PLL library

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   aunsigned long with this program.  If not, see <http://www.gnu.org/licenses/>.

 */
#ifndef MC145192_h
#define MC145192_h

#include "Arduino.h"

// C register
#define MC145192_C_POL(val) (val << 7)   // detector out polarity
#define MC145192_C_PDA(val) (val << 6)   // select phase/frequency detector
#define MC145192_C_LDE(val) (val << 5)   // enable lock detector
#define MC145192_C_STBY(val) (val << 4)  // set to standby
#define MC145192_C_I2I1(val) (val << 2)  // PDout current
#define MC145192_C_PORT(val) (val << 1)  // output A state
#define MC145192_C_OUTB(val) (val << 0)  // output B state

// A register
#define MC145192_A_OUT(val) ((unsigned long)val << 22)  // data out port
#define MC145192_A_FILL ((unsigned long)3 << 20)        // 11 fill values
#define MC145192_A_NREG(val) ((unsigned long)val << 8)  // N reg value 
#define MC145192_A_AREG(val) ((unsigned long)val << 0)  // A reg value

// R register
#define MC145192_R_REF(val) ((unsigned int)val << 13)  // reference mode
#define MC145192_R_RREG(val) ((unsigned int)val << 0)  // R reg value

// reference modes
#define MC145192_REF_SHUTDOWN   0
#define MC145192_REF_ACTIVE     1
#define MC145192_REF_LOW        2
#define MC145192_REF_1          3
#define MC145192_REF_2          4 
#define MC145192_REF_4          5
#define MC145192_REF_8          6
#define MC145192_REF_16         7

class MC145192
{
    public: 
        MC145192(byte);
        void set_registers(byte, unsigned int, unsigned long);

    private:
        void write_registers();

    private:
        byte ss_pin_;

        byte reg_c_;
        unsigned int reg_r_;
        unsigned long reg_a_;
};
 
#endif
