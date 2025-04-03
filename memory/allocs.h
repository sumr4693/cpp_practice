#ifndef ALLOCS_H
#define ALLOCS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <memory.h>

#define PASS_LS_BYTE 0x000000ff
#define PASS_MS_BYTE 0xff000000

typedef enum
{
    e_ASSIGN_METHOD = 0,
    e_COPY_METHOD
} DATA_WRITE_METHOD_t;

typedef enum
{
    e_INVALID = 0,
    e_LITTLE_ENDIAN = 1,
    e_BIG_ENDIAN = 2
} ENDIANS_t;

uint32_t* create_uint32_malloc(uint8_t units);
uint32_t* create_uint32_calloc(uint8_t units);
bool free_uint32_memory(uint32_t* mem_ptr);

void write_data_to_memory(uint32_t *const ptr, uint32_t const *const data_ptr, uint8_t data_blocks, DATA_WRITE_METHOD_t write_method_t);
void write_bytes_to_memory(uint8_t *const ptr, uint32_t const *const data_ptr, uint8_t data_blocks);
void read_data_from_memory(uint32_t *const ptr, uint8_t no_of_bytes);
void read_bytes_from_memory(uint8_t *const ptr, uint8_t no_of_bytes);

ENDIANS_t get_endian_type(uint32_t *const ptr);
const char* check_endian(void);
void convert_to_little_or_big_endian(uint32_t *const ptr);
uint32_t convert_endian_using_builtin(uint32_t value);

/* TODO: Add all the different pointer plays */

#ifdef __cplusplus
}
#endif

#endif
