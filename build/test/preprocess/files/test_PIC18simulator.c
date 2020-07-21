#include "build/temp/_test_PIC18simulator.c"
#include "src/_testHelper.h"
#include "src/PIC18simulator.h"
#include "C:/Ruby25-x64/lib/ruby/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


extern uint8_t fileRegisters[];



void setUp(void){}

void tearDown(void){}









void test_executionInstruction_given_0x2645_expect_addwf_called(void) {



  uint8_t machineCode[] = {0x45, 0x26, 0x00, 0xff};



  fileRegisters[0xfe8] = 0x23;



  fileRegisters[0x45] = 0x56;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[(((_21BitInteger*)&fileRegisters[0xff9])-> value) = 0xabce]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);





  executionInstruction();





  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x79)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0x45])), (

 ((void *)0)

 ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x23)), (UNITY_INT)(UNITY_INT8 )((fileRegisters[0xfe8])), (

 ((void *)0)

 ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_HEX8);

}
