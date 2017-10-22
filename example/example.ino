/*
 * 
 *  test program for mc145192 library testing
 * 
 */

#include <SPI.h>
#include <MC145192.h>

MC145192 PLL(8);

unsigned int N, A, R;

void setup() {
  SPI.begin();
  Serial.begin(9600);
  Serial.println("Started");
/*
  R = 1280;
  A = 15;
  N = 770;
*/
  R = 128;
  A = 0;
  N = 625;
}

void loop() {
  
  byte reg_c;
  unsigned int reg_r;
  unsigned long reg_a;
  
  reg_c = MC145192_C_POL(MC145192_POL_NONINV) |
          MC145192_C_PDA(MC145192_PDA_A) |
          MC145192_C_LDE(MC145192_LDE_ENABLE) |
          MC145192_C_STBY(MC145192_STBY_DISABLE) |
          MC145192_C_I2I1(MC145192_I2I1_100) |
          MC145192_C_OUTA(MC145192_OUTA_HIGH_25) |
          MC145192_C_OUTB(MC145192_OUTB_LOW);

  reg_a = MC145192_A_OUT(MC145192_A_OUT_FR) |
          MC145192_A_FILL |
          MC145192_A_NREG(N) |
          MC145192_A_AREG(A) ;

  reg_r = MC145192_R_REF(MC145192_REF_LOW) |
          MC145192_R_RREG(R);

  Serial.println("Updating");
  Serial.println(reg_c, BIN);
  Serial.println(reg_r, BIN);
  Serial.println(reg_a, BIN);
   
  PLL.set_registers(reg_c, reg_r, reg_a);

  Serial.println("done");
  while (!Serial.available()) {}
  while (Serial.available()) { Serial.read();}
  N++;
}
