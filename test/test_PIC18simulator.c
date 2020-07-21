#include "unity.h"
#include "PIC18simulator.h"
#include "_testHelper.h"

extern uint8_t fileRegisters[];

void setUp(void){}
void tearDown(void){}



//addwf 0x45, f, ACCESS ==> 0010 0110 0110 0111 (0x2645)
void test_executionInstruction_given_0x2645_expect_addwf_called(void) {
  //Setup the text fixture
  uint8_t machineCode[] = {0x45, 0x26, 0x00, 0xff};
  //set wreg
  wreg = 0x23;
  //Set content of target file register 
  fileRegisters[0x45] = 0x56;
  //Copy instruction to code memory
  copyCodeToCodeMemory(machineCode, pc = 0xabce);
  
  //Run the code under test 
  executionInstruction();
  
  //Verify the code has expected output
  TEST_ASSERT_EQUAL_HEX8(0x79, fileRegisters[0x45]);
  TEST_ASSERT_EQUAL_HEX8(0x23, wreg);
}




