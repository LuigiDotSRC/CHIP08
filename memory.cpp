#include <stdint.h> 
#include <iostream>
#include <stdlib.h>
#include <cstring> 

unsigned char memory[4096]; // 4K mem 2^12

unsigned char read(uint16_t address_bits) {
  if (address_bits < 4096) {
    return memory[address_bits];
  } else {
    return 0; // HANDLE ERR
  }
}

void write(uint16_t address_bits, const unsigned char data[], size_t data_length) {
  if (address_bits < 4096 && address_bits + data_length <= 4096) {  
    for (size_t i = 0; i < data_length; ++i) {
      memory[address_bits + i] = data[i];
    }
  }
  // ELSE: HANDLE ERR
}

void init() {
  memset(memory, 0, sizeof(memory));
}

void dumpMemory() {
  for (size_t i = 0; i < 4096; ++i) {
    printf("%02X ", memory[i]); 
    if (i % 16 == 15) printf("\n"); 
  }
}
