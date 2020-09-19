#include "build/temp/_test_PIC18simulator.c"
#include "src/_testHelper.h"
#include "src/PIC18simulator.h"
#include "C:/Ruby25-x64/lib/ruby/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


extern uint8_t fileRegisters[];



void setUp(void){}

void tearDown(void){}

void test_executionInstruction_given_0x2645_expect_addwf_called_and_access_to_0x45_with_result_stored_in_fileRegister(void)

{



  uint8_t machineCode[] = {0x45, 0x26, 0x00, 0xff};



  fileRegisters[0xfe8] = 0x23;



  fileRegisters[0x45] = 0x56;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[(((_21BitInteger*)&fileRegisters[0xff9])-> value) = 0x0001]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executionIntruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x79)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0x45])), (

 ((void *)0)

 ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x23)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfe8])), (

 ((void *)0)

 ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0001 + 2)), (UNITY_INT64)(((((_21BitInteger*)&fileRegisters[0xff9])-> value))), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX64);

}







void test_executionInstruction_given_0x2422_expect_addwf_called_and_access_to_0x22_with_result_stored_in_wreg(void)

{



  uint8_t machineCode[] = {0x22, 0x24, 0x00, 0xff};



  fileRegisters[0xfe8] = 0x39;



  fileRegisters[0x22] = 0x6B;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[(((_21BitInteger*)&fileRegisters[0xff9])-> value) = 0x0002]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executionIntruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x6B)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0x22])), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x39 + 0x6B)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfe8])), (

 ((void *)0)

 ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((1 << 3) | (1 << 4) | (1 << 1))), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfd8])), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0002 + 2)), (UNITY_INT64)(((((_21BitInteger*)&fileRegisters[0xff9])-> value))), (

 ((void *)0)

 ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX64);

}

void test_executeInstruction_given_6A2DH_expect_clrf_called_and_access_to_2DH_to_clear_the_data_stored(void) {



  uint8_t machineCode[] = {0x2D, 0x6B, 0x00, 0xff};



  fileRegisters[0xfe8] = 0x1C;



  fileRegisters[0x2D] = 0x7B;

  fileRegisters[0x12D] = 0x87;

  fileRegisters[0xF2D] = 0x55;



  fileRegisters[0xfd8] = 0x00;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[(((_21BitInteger*)&fileRegisters[0xff9])-> value) = 0x0100]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executionIntruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x00)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0x2D])), (

 ((void *)0)

 ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x87)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0x12D])), (

 ((void *)0)

 ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x55)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xF2D])), (

 ((void *)0)

 ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x1C)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfe8])), (

 ((void *)0)

 ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((1 << 2))), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfd8])), (

 ((void *)0)

 ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0100 + 2)), (UNITY_INT64)(((((_21BitInteger*)&fileRegisters[0xff9])-> value))), (

 ((void *)0)

 ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX64);

}

void test_executeInstruction_given_2A12H_expect_incf_called_and_access_to_12H_with_the_result_stored_in_fileRegister(void) {



  uint8_t machineCode[] = {0x12, 0x28, 0x00, 0xff};



  fileRegisters[0xfe8] = 0x22;



  fileRegisters[0x12] = 0xF4;

  fileRegisters[0x112] = 0x00;

  fileRegisters[0xA12] = 0x00;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[(((_21BitInteger*)&fileRegisters[0xff9])-> value) = 0x0200]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  fileRegisters[0xfd8] = 0x00;



  executionIntruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0xF4 + 1)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0x12])), (

 ((void *)0)

 ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x22)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfe8])), (

 ((void *)0)

 ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((1 << 0) | (1 << 1) | (1 << 2))), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfd8])), (

 ((void *)0)

 ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0200 + 2)), (UNITY_INT64)(((((_21BitInteger*)&fileRegisters[0xff9])-> value))), (

 ((void *)0)

 ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX64);

}







void test_executeInstruction_given_05DDH_expect_decf_called_and_access_to_FDDH_with_the_result_stored_in_wreg(void) {



  uint8_t machineCode[] = {0xDD, 0x05, 0x00, 0xff};



  fileRegisters[0xfe8] = 0xA3;



  fileRegisters[0xDD] = 0x00;

  fileRegisters[0x2DD] = 0x00;

  fileRegisters[0xFDD] = 0x99;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[(((_21BitInteger*)&fileRegisters[0xff9])-> value) = 0x0300]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



 executionIntruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x99)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xFDD])), (

 ((void *)0)

 ), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x99 - 1)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfe8])), (

 ((void *)0)

 ), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((1 << 4) | (1 << 0) | (1 << 1))), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfd8])), (

 ((void *)0)

 ), (UNITY_UINT)(138), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0300 + 2)), (UNITY_INT64)(((((_21BitInteger*)&fileRegisters[0xff9])-> value))), (

 ((void *)0)

 ), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_HEX64);

}
