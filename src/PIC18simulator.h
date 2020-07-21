#ifndef PIC18SIMULATOR_H
#define PIC18SIMULATOR_H
#include <stdint.h>

typedef struct _21BitInteger _21BitInteger;
struct _21BitInteger {
  int value:21;
};



#define wreg      fileRegisters[0xfe8]
#define bsr       fileRegisters[0xfe0]
#define status    fileRegisters[0xfd8]
#define pc        (((_21BitInteger*)&fileRegisters[0xff9])-> value)

#define STATUS_N  (1 << 4)
#define STATUS_OV (1 << 3)
#define STATUS_Z  (1 << 2)
#define STATUS_DC (1 << 1)
#define STATUS_C  (1 << 0)
#define SET_ALL_STATUS_FLAGS (                \
                               STATUS_N  |    \
                               STATUS_OV |    \
                               STATUS_Z  |    \
                               STATUS_DC |    \
                               STATUS_C       \
                               )


extern uint8_t fileRegisters[];
extern uint8_t codeMemory[];
//instructionExecutor is a pointer to function taking in 
typedef void (*instructionExecutor)(void);

int computeFileregAddress(int address, int bankType);
int8_t add(int val1, int val2);



void executionInstruction();
void addwf();

  
#endif // PIC18SIMULATOR_H
