#include "PIC18simulator.h"
#include <stdint.h>
#include <stdio.h>

instructionExecutor pic18executionTable[256] = {
  [0x24] = addwf, addwf , addwf , addwf ,
};


//Range of file registers between 0x000 to 0xfff
uint8_t fileRegisters[0x1000];

//Max range code memory: 0x000000 to 0x1fffff
//Range code memory for simulator: 0x0000 to 0xffff
uint8_t codeMemory[0x10000];

int8_t add(int val1, int val2) {
  //clear status
  status = 0x00;
  
  //status flags C, DC, Z, OV, N 
  int val3 = val1 + val2;
  if (val3>0xFF) {
    status |= STATUS_C;
  }
  if((((uint8_t)val1&0x0f) + ((uint8_t)val2&0x0f))>0x0f) {
    status |= STATUS_DC;
  }
  if((uint8_t)val3==0) {
    status |= STATUS_Z;
  }
  if (!((uint8_t)val1&0x80) && !((uint8_t)val2&0x80 && ((uint8_t)val3&0x80))) {
    status |= STATUS_OV;
  }
  if((val3&0x80) && !(val3>0xff)) {
    status |= STATUS_N;
  }
  return val3;
}

int computeFileregAddress(int address, int bankType) {
  if(bankType){
    //BANKED
    address += (unsigned int)bsr << 8;
  }else{
    //ACCESS
    //Adjust the address if it is in SFR region
    if(address > 0x5f)
      address += 0xf00;
  }
return address;
}



//--------------executionInstruction function----------------------------
void executionIntruction()
{
  //uint8_t v1 = codePtr[0];    //v1 = 0x45
  //uint8_t v2 = cpdePtr[1];    //v2 = 0x25
  uint8_t *codePtr = &codeMemory[pc];
  instructionExecutor executor = pic18executionTable[codePtr[1]];
  executor();
}

/*
 *-------------addwf function----------------------------
 *Direction       (d):    0 ==> WREG, 1 ==> file register
 *Bank            (a):    0 ==> ACCESS BANK, 1 ==> BANKED
 *File Register   (f):    range from 0 to 255
 
 *Mnemonic: addwf, f, d, a 
 *Opcode: 0010 01da ffff ffff 
 */
uint8_t *addValueAndFileReg(int val) {
  uint8_t *codePtr = &codeMemory[pc];
  int d = codePtr[1] &0x02;
  int addr = computeFileregAddress(codePtr[0], codePtr[1] & 0x01);
  
  if(d) {
    //d is a 1 ==> store result in file register
    fileRegisters[addr] = add(fileRegisters[addr], val);
    
  }else {
    //d is a 0 ==> store result in WREG 
    wreg = add(fileRegisters[addr], val);
  }
  pc += 2; 
}
 void addwf () {
   addValueAndFileReg(wreg);
 }
   