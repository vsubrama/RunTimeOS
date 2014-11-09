#include "memory.h"
#include "print.h"

natural8_t* mem_start,mem_end,mem_cheney_middle,mem_cheney_start;

void memory_init(void)
{
	natural16_t total;
    natural8_t lowmem, highmem;
    write_port(0x70, 0x30);
    lowmem = read_port(0x71);
    write_port(0x70, 0x31);
    highmem = read_port(0x71);
    total = lowmem | highmem << 8;
    mem_cheney_start=(natural8_t*)lowmem;
    mem_start = mem_cheney_start;
    mem_end=(natural16_t*)highmem;
    mem_cheney_middle = (natural16_t*)(total/2);
    //cheney_collector_mode mode = cheney_collector_mode.mem_cheney_start;
}

void* malloc(natural8_t length)
{	
	natural8_t* memory_address = mem_start;
 	mem_start = mem_start + length;
 	return memory_address;
}

void garbageCollector(void* root)
{
	/*if (root[0]!=0)
	{
		if (cheney_collector_mode == cheney_start)
		{
			cheney_collector_mode = cheney_middle;
			mem_start = mem_cheney_middle;
		}
		else
		{
			cheney_collector_mode = cheney_start;
			mem_start = mem_cheney_start;
		}
		move(&root);
	}*/
}
void* move(void* root)
{
	/*natural8_t number_of_objects = root[0];
	void* objectpointer = (void*)malloc(number_of_objects);
	for(natural8_t index = 1; index <= number_of_objects; index++)
	{
		objectpointer[ index - 1] = root[index];
	}
	natural8_t payload = root[index+1];
	natural16_t size_of_object = 1 + number_of_objects + 1 + payload;
	void* copypointer = (void*)malloc(size_of_object);
	for(natural8_t index = 0;index<size_of_object;index++)
	{
		copypointer[index] = root[index];
	}*/
}