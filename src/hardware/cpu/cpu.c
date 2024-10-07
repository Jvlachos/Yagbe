#include "../include/cpu.h"
#include "stdio.h"
#include "../util/bits.h"

void access(){
  instruction_t ins = instruction_set[0];
  printf("%s\n",ins.instr_str);
}


u8 FetchNextInstrByte(cpu_t *cpu){
  u16 pc = read16(cpu->PC);
  //memory read here (instr mem)!
  set16(&cpu->PC,pc++);
  //return memory read0 
}

u8 read8(reg_t reg,u8 sel){
  return sel == 0 ? reg.hi : reg.lo; 
}

u16 read16(reg_t reg){
  return bit_concat(reg.hi,reg.lo); 
}


void set16(reg_t* reg,u16 val){
  reg->hi = (val >> 8) & REG_LO_MASK;
  reg->lo = val & REG_LO_MASK;
}

void set8(reg_t* reg,u8 val,u8 sel){
   reg->hi = sel == 0 ? val : 0;
   reg->lo = sel == 1 ? val : 0;
}
