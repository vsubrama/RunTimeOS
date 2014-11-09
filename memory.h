#ifndef MEMORY_H_
#define MEMORY_H_
#include "types.h"
typedef enum {
  cheney_start = 1,
  cheney_middle = 0
} cheney_collector_mode;
void memory_init(void);
void* malloc(natural8_t length);
void garbageCollector(void* root);
#endif