#include "../util/util.h"

typedef u8 ByteReg;
typedef u16 WordReg;

typedef struct {
  ByteReg hi;
  ByteReg lo;
} reg_t;

typedef enum{
  RUNNING = 0,
  HALTED  = 1
}CPU_STATE_T;

typedef struct{
  CPU_STATE_T state;
  reg_t AF,BC,DE,HL,SP,PC;
  u64 cycles;

} cpu_t;


typedef void (*opcode_ex)(cpu_t* cpu);
typedef struct{
  char* instr_str;
  opcode_ex op_ex;

} instruction_t;

extern const instruction_t instruction_set[256];
extern const instruction_t cb_instruction_set[256];

void set16(reg_t* reg,u16 val);
void set8(reg_t* reg,u8 val,u8 sel);
void cpu_cycle(cpu_t *cpu);
void access();
void FetchNextInstructionByte(cpu_t *cpu);
u16 read16(reg_t reg);
u8 read8(reg_t reg,u8 sel);

void dec(reg_t* reg);
void inc(reg_t* reg);
void add(reg_t* reg,u8 val);


