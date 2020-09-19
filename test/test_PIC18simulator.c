#include "unity.h"
#include "PIC18simulator.h"
#include "_testHelper.h"

extern uint8_t fileRegisters[];

void setUp(void){}
void tearDown(void){}


//-------------------------TEST OPERANDS----------------------------------
/*
Direction     (d):  0 ==> WREG, 1 ==> file register
Bank          (a):  0 ==> ACCESS Bank, 1 ==> BANKED 
File Register (f):  range from 0 to 255
*/

// 0010 01da ffff ffff
//addwf 0x45, f, ACCESS ==> 0010 0110 0110 0111 (0x2645)
void test_executionInstruction_given_0x2645_expect_addwf_called_and_access_to_0x45_with_result_stored_in_fileRegister(void) 
{
  //Setup the text fixture
  uint8_t machineCode[] = {0x45, 0x26, 0x00, 0xff};
  //set wreg
  wreg = 0x23;
  //Set content of target file register 
  fileRegisters[0x45] = 0x56;
  //Copy instruction to code memory
  copyCodeToCodeMemory(machineCode, pc = 0x0001);
  //Run the code under test 
  executionIntruction();
  //test output
  TEST_ASSERT_EQUAL_HEX8(0x79, fileRegisters[0x45]);
  TEST_ASSERT_EQUAL_HEX8(0x23, wreg);
  TEST_ASSERT_EQUAL_PTR(0x0001 + 2, pc);
}

// 0010 01da ffff ffff
//addwf 0x22, w, ACCESS ==> 0010 0100 0010 0010 (0x2422)
void test_executionInstruction_given_0x2422_expect_addwf_called_and_access_to_0x22_with_result_stored_in_wreg(void) 
{
  //Setup the text fixture
  uint8_t machineCode[] = {0x22, 0x24, 0x00, 0xff};
  //set wreg
  wreg = 0x39;
  //Set content of target file register 
  fileRegisters[0x22] = 0x6B;
  //Copy instruction to code memory
  copyCodeToCodeMemory(machineCode, pc = 0x0002);
  //Run the code under test 
  executionIntruction();
  //test output
  TEST_ASSERT_EQUAL_HEX8(0x6B, fileRegisters[0x22]);
  TEST_ASSERT_EQUAL_HEX8(0x39 + 0x6B, wreg);
  TEST_ASSERT_EQUAL_HEX8(STATUS_OV | STATUS_N | STATUS_DC, status);
  TEST_ASSERT_EQUAL_PTR(0x0002 + 2, pc);
}

/*
Bank          (a):    0 ==> ACCESS BANK, 1 ==> BANKED
File Register (f):    range from 0 to 255
*/

//  0110 101a ffff ffff
//clrf   0x2D, ACCESS   ==> 0110 1010 0010 1101(0x6A2D)
void test_executeInstruction_given_6A2DH_expect_clrf_called_and_access_to_2DH_to_clear_the_data_stored(void) {
  //Setup test fixture
  uint8_t machineCode[] = {0x2D, 0x6B, 0x00, 0xff};
  //Set WREG
  wreg = 0x1C;
  //Set content of target file reg
  fileRegisters[0x2D]  = 0x7B;
  fileRegisters[0x12D] = 0x87;
  fileRegisters[0xF2D] = 0x55;
  //Clear the status register for testing
  status = 0x00;
  //Copy instructions to the code memory
  copyCodeToCodeMemory(machineCode, pc = 0x0100);
  //Run the code under test
  executionIntruction();
  //Verify the code has expected output
  TEST_ASSERT_EQUAL_HEX8(0x00, fileRegisters[0x2D]);
  TEST_ASSERT_EQUAL_HEX8(0x87, fileRegisters[0x12D]);       
  TEST_ASSERT_EQUAL_HEX8(0x55, fileRegisters[0xF2D]);
  TEST_ASSERT_EQUAL_HEX8(0x1C, wreg);                      
  TEST_ASSERT_EQUAL_HEX8(STATUS_Z, status);
  TEST_ASSERT_EQUAL_PTR(0x0100 + 2, pc);
}

/*
Direction     (d):    0 ==> WREG , 1 ==> file register
Bank          (a):    0 ==> ACCESS BANK, 1 ==> BANKED
File Register (f):    range from 0 to 255
*/

//  0010 10da ffff ffff
//incf   0x12, f, ACCESS   ==> 0010 1010 0001 0010(0x2A12)
void test_executeInstruction_given_2A12H_expect_incf_called_and_access_to_12H_with_the_result_stored_in_fileRegister(void) {
  //Setup test fixture
  uint8_t machineCode[] = {0x12, 0x28, 0x00, 0xff};
  //Set WREG
  wreg = 0x22;
  //Set content of target file reg
  fileRegisters[0x12]  = 0xF4;
  fileRegisters[0x112] = 0x00;
  fileRegisters[0xA12] = 0x00;
  //Copy instructions to the code memory
  copyCodeToCodeMemory(machineCode, pc = 0x0200);
  //Clear the status register for testing
  status = 0x00;
  //Run the code under test
  executionIntruction();
  //Verify the code has expected output
  TEST_ASSERT_EQUAL_HEX8(0xF4 + 1, fileRegisters[0x12]);
  TEST_ASSERT_EQUAL_HEX8(0x22, wreg);
  TEST_ASSERT_EQUAL_HEX8(STATUS_C | STATUS_DC | STATUS_Z, status);
  TEST_ASSERT_EQUAL_PTR(0x0200 + 2, pc);
}

//  0000 01da ffff ffff
//decf   0xDD, w, ACCESS   ==> 0000 0101 1101 1101(0x05DD)
void test_executeInstruction_given_05DDH_expect_decf_called_and_access_to_FDDH_with_the_result_stored_in_wreg(void) {
  //Setup test fixture
  uint8_t machineCode[] = {0xDD, 0x05, 0x00, 0xff};
  //Set WREG
  wreg = 0xA3;
  //Set content of target file reg
  fileRegisters[0xDD]  = 0x00;
  fileRegisters[0x2DD] = 0x00;
  fileRegisters[0xFDD] = 0x99;
  //Copy instructions to the code memory
  copyCodeToCodeMemory(machineCode, pc = 0x0300);
  //Run the code under test
 executionIntruction();
  //Verify the code has expected output
  TEST_ASSERT_EQUAL_HEX8(0x99, fileRegisters[0xFDD]);
  TEST_ASSERT_EQUAL_HEX8(0x99 - 1, wreg);
  TEST_ASSERT_EQUAL_HEX8(STATUS_N | STATUS_C | STATUS_DC, status);
  TEST_ASSERT_EQUAL_PTR(0x0300 + 2, pc);
}



