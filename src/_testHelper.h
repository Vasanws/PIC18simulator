#ifndef _TESTHELPER_H
#define _TESTHELPER_H



//The srcArray must be an array of char and codeAddress is the offset
//of PIC18 code memory space
#define copyCodeToCodeMemory(srcArray, codeAddr)               \
                                                                \
  do{                                                           \
    int i;                                                      \
    unsigned char *dst = (unsigned char *)&codeMemory[codeAddr];\
    for(i = 0; i < sizeof(srcArray); i++){                      \
      dst[i] = (srcArray)[i];                                   \
    }                                                           \
  }while(0)
    

#endif // _TESTHELPER_H
