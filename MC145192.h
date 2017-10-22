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
#define MC145192_C_OUTA(val) (val << 1)  // output A state
#define MC145192_C_OUTB(val) (val << 0)  // output B state

// 7, PDout polarity
#define MC145192_POL_NONINV     0        // No inversion
#define MC145192_POL_INV        1        // Inverts PDout and phi_r / phi_v

// 6, PDout selection
#define MC145192_PDA_B          0        // B enabled and phi_r / phi_v
#define MC145192_PDA_A          1        // PDout is enabled

// 5, LDE enable/disable (lock detector output)
#define MC145192_LDE_DISABLE    0
#define MC145192_LDE_ENABLE     1

// 4, stand by
#define MC145192_STBY_DISABLE   0
#define MC145192_STBY_ENABLE    1

// 3,2 i2, i1 curents 
#define MC145192_I2I1_70_25     0
#define MC145192_I2I1_80_50     1
#define MC145192_I2I1_90_75     2
#define MC145192_I2I1_100       3

// 1, Output A
#define MC145192_OUTA_LOW_10    0       // Output A is low, 10% current step
#define MC145192_OUTA_HIGH_25   1       // Output A is high, 25% current step

// 0, Output B
#define MC145192_OUTB_LOW	0       // Output B low impedance
#define MC145192_OUTB_HIGH	1       // Output B high impedance


// A register
#define MC145192_A_OUT(val) ((unsigned long)val << 22)  // data out port
#define MC145192_A_FILL ((unsigned long)3 << 20)        // 11 fill values
#define MC145192_A_NREG(val) ((unsigned long)val << 8)  // N reg value 
#define MC145192_A_AREG(val) ((unsigned long)val << 0)  // A reg value

// data out port values
#define MC145192_A_OUT_PORT     0 
#define MC145192_A_OUT_DATA     1
#define MC145192_A_OUT_FV       2
#define MC145192_A_OUT_FR       3


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
        void write_c();
        void write_r();
        void write_a();

    private:
        byte ss_pin_;

        byte reg_c_;
        unsigned int reg_r_;
        unsigned long reg_a_;
};
 
#endif
