#include "memory.h"
#include "print.h"

unsigned int* mem_start,mem_end;

void memory_init(void)
{
	natural16_t total;
    natural8_t lowmem, highmem;
    write_port(0x70, 0x30);
    lowmem = read_port(0x71);
    write_port(0x70, 0x31);
    highmem = read_port(0x71);
    total = lowmem | highmem << 8;
    mem_start=(natural8_t*)lowmem;
    mem_end=(natural16_t*)highmem;
}

void* malloc(natural8_t length)
{	
	natural8_t* memory_address = mem_start;
 	mem_start = mem_start + length;
 	return memory_address;
} 