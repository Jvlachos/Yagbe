#include "stdint.h"
#include "util.h"
#define REG_LO_MASK 0xFF
static inline  u16 bit_concat(u8 a,u8 b){
  return (u16)(((u16) a << 8) | b);
}

static inline void set_bit8(u8 *bits,u8 which){
  *bits |= (1 << which);
}

static inline void set_bit16(u16 *bits,u8 which){
  *bits |= (1 << which);
}

