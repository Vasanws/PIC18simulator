#include "PIC18simulator.h"
#include <stdint.h>
#include <stdio.h>

InstructionExecutor pic18executionTable[256] = {
  [0x04] = decf, decf, decf, decf,
  //[0x20] = addwfc, addwfc, addwfc, addwfc,
  [0x24] = addwf, addwf, addwf, addwf,
  [0x28] = incf, incf, incf, incf,
  [0x6A] = clrf, clrf,
  /*[0x6E] = movwf, movwf,
  [0x90] = bcf, bcf, bcf, bcf, bcf, bcf, bcf, bcf,
           bcf, bcf, bcf, bcf, bcf, bcf, bcf, bcf,
  [0x80] = bsf, bsf, bsf, bsf, bsf, bsf, bsf, bsf,
           bsf, bsf, bsf, bsf, bsf, bsf, bsf, bsf,
  [0xE1] = bnz,
  [0xE2] = bc,
  [0xE5] = bnov,
  [0xE6] = bn,
  [0x14] = andwf, andwf, andwf, andwf,
  [0x34] = rlcf, rlcf, rlcf, rlcf,*/
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
  if (val3 > 0xFF) {
    status |= STATUS_C;
  }
  if((((uint8_t)val1 & 0x0f) + ((uint8_t)val2 & 0x0f)) > 0x0f) {
    status |= STATUS_DC;
  }
  if((uint8_t)val3 == 0) {
    status |= STATUS_Z;
  }
  if((val3 & 0x80) && !(val3 > 0xff)) {
    status |= STATUS_N;
  }
  if(((uint8_t)val1 & 0x80) && ((uint8_t)val2 & 0x80) && !((uint8_t)val3 & 0x80)) {
    status |= STATUS_OV;
  }
  if (!((uint8_t)val1 & 0x80) && !((uint8_t)val2 & 0x80 && ((uint8_t)val3 & 0x80))) {
    status |= STATUS_OV;
  }
  
  return val3;
}


//--------------executionInstruction function----------------------------
void executionIntruction()
{
  uint8_t *codePtr = &codeMemory[pc];
  InstructionExecutor executor = pic18executionTable[codePtr[1]];
  executor();
}

//--------------Banked Or Access-----------------------------------
int adjustAddrForBankedOrAccess(int type, int addr) {
  if(type) {
    //Banked
    addr += (unsigned int)bsr*0x100;
  }else {
    //ACCESS 
    if (addr > 0x5f)
      //adjust the addr in SFR region
      addr += 0xf00;
  }
  return addr; 
}

/*
 *Direction       (d):    0 ==> WREG, 1 ==> file register
 *Bank            (a):    0 ==> ACCESS BANK, 1 ==> BANKED
 *File Register   (f):    range from 0 to 255
 
 *Mnemonic: addwf, f, d, a 
 *Opcode: 0010 01da ffff ffff 
 */

void addwf()
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int d = codePtr[1] & 0x02;
  int a = codePtr[1] & 0x01;
  int addr = adjustAddrForBankedOrAccess(a, address);
  if(d){
    fileRegisters[addr] = add(fileRegisters[addr], wreg); // d = 1 ==> store result in fiel register
  }else {
    wreg = add(fileRegisters[addr], wreg);               // d = 0 ==> wreg
  }
  pc += 2;
}

void addwfc()
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int d = codePtr[1] & 0x02;
  int a = codePtr[1] & 0x01;
  int addr = adjustAddrForBankedOrAccess(a, address);
  int tempoNum = add(status & 0x01, wreg);
  int tempoFlag = status & 0x02;
  if(d){
    fileRegisters[addr] = add(fileRegisters[addr], wreg); // d = 1 ==> store result in fiel register
  }else {
    wreg = add(fileRegisters[addr], wreg);               // d = 0 ==> wreg
  }
  
  status |= tempoFlag;
  pc += 2;
}

void incf()
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int d = codePtr[1] & 0x02;
  int a = codePtr[1] & 0x01;
  int addr = adjustAddrForBankedOrAccess(a, address);
  if(d){
    fileRegisters[addr] = add(fileRegisters[addr], 1); // d = 1 ==> store result in fiel register
  }else {
    wreg = add(fileRegisters[addr], 1);               // d = 0 ==> wreg
  }
  pc += 2;
}

void decf()
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int d = codePtr[1] & 0x02;
  int a = codePtr[1] & 0x01;
  int addr = adjustAddrForBankedOrAccess(a, address);
  if(d){
    fileRegisters[addr] = add(fileRegisters[addr], -1); // d = 1 ==> store result in fiel register
  }else {
    wreg = add(fileRegisters[addr], -1);               // d = 0 ==> wreg
  }
  pc += 2;
}

void clrf()
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int a = codePtr[1] & 0x01;
  int addr = adjustAddrForBankedOrAccess(a, address);
  
  fileRegisters[addr] = 0;
  status |= STATUS_Z;
  pc += 2; 
}

void bsf() 
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int a = codePtr[1] & 0x01;
  int r = (codePtr[1] & 0x0e) >> 1;
  int addr = adjustAddrForBankedOrAccess(a, address);
  fileRegisters[addr] = 1 << r;
  
  pc += 2;
}

void bcf()
{
  uint8_t *codePtr = &codeMemory[pc];
  int address = (uint8_t)codePtr[0];
  int a = codePtr[1] & 0x01;
  int r = (codePtr[1] & 0x0e) >> 1;
  int addr = adjustAddrForBankedOrAccess(a, address);
  fileRegisters[addr] &= ~(1 << r);
  
  pc += 2;
}
   