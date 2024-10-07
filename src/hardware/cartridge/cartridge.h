#include "../util/util.h"

#define RAM_SIZE 0x8000
#define ROM_SIZE 0x200000

#define RAM_LINES RAM_SIZE >> 3
#define ROM_LINES ROM_SIZE >> 3

typedef u8[RAM_LINES] MBC1_Ram;
typedef u8[ROM_LINES] MBC1_Rom;

MBC1_Ram Ram;
MBC1_Rom Rom;

