#include "allocs.h"

/**
 * Add comments in Doxygen style
 */
uint32_t* create_uint32_malloc(uint8_t units)
{
    uint32_t *m_ptr = (uint32_t*) malloc(units * sizeof(uint32_t));

    return m_ptr;
}

uint32_t* create_uint32_calloc(uint8_t units)
{
    uint32_t *c_ptr = (uint32_t*) calloc(units, sizeof(uint32_t));

    return (uint32_t *const) c_ptr;
}

bool free_uint32_memory(uint32_t* ptr)
{
    bool status = false;

    /* Freeing alone makes it a dangling pointer, therefore need to assign NULL after freeing */
    free(ptr);
    ptr = NULL;

    if (ptr == NULL)
    {
        status = true;
    }

    return status;
}

void write_data_to_memory(uint32_t *const ptr, uint32_t const *const data_ptr, uint8_t data_blocks, DATA_WRITE_METHOD_t write_method_t)
{
    assert(ptr != NULL && data_ptr != NULL);

    printf("Writing data to memory block\n");

    if (write_method_t == e_ASSIGN_METHOD)
    {
        for (uint8_t i = 0; i < data_blocks; i++)
        {
            /* &x[1] is equivalent to x+1 and x[1] is equivalent to *(x+1) */
            ptr[i] = data_ptr[i];
            printf("%u ", ptr[i]);
        }
        printf("\n");
    }
    else if (write_method_t == e_COPY_METHOD)
    {
        uint8_t no_of_bytes = sizeof(uint32_t) * data_blocks;
        memcpy(ptr, data_ptr, no_of_bytes);
    }
}

void write_bytes_to_memory(uint8_t *const ptr, uint32_t const *const data_ptr, uint8_t data_blocks)
{
    assert(ptr != NULL && data_ptr != NULL);

    printf("Converting data to bytes\n");
    size_t no_of_bytes = sizeof(uint32_t) * data_blocks;
    memcpy(ptr, data_ptr, no_of_bytes);
}

void read_data_from_memory(uint32_t *const ptr, uint8_t data_blocks)
{
    assert(ptr != NULL);

    printf("Reading data from memory block:\n");
    for (uint8_t i = 0; i < data_blocks; i++)
    {
        printf("%u ", ptr[i]);
    }
    printf("\n");
}

void read_bytes_from_memory(uint8_t *const ptr, uint8_t no_of_bytes)
{
    assert(ptr != NULL);

    printf("Reading bytes from memory block:\n");
    for (uint8_t i = 0; i < no_of_bytes; i++)
    {
        printf("%u ", ptr[i]);
    }
    printf("\n");
}

ENDIANS_t get_endian_type(uint32_t *const ptr)
{
    uint8_t* ptr_to_data = (uint8_t*) ptr;
    uint8_t ls_byte, ms_byte;

    ENDIANS_t endian_t = e_INVALID;

    ls_byte = (uint8_t) (ptr[0] & PASS_LS_BYTE);
    ms_byte = (uint8_t) ((ptr[0] & PASS_MS_BYTE) >> 24);

    printf("Raw data: %04x\n", ptr[0]);
    printf("data[0]: %01x, data[3]: %01x, ls_byte: %01x, ms_byte: %01x\n", ptr_to_data[0], ptr_to_data[3], ls_byte, ms_byte);

    if (ptr_to_data[0] == ls_byte)
    {
        endian_t = e_LITTLE_ENDIAN;
    }
    else if (ptr_to_data[0] == ms_byte)
    {
        endian_t = e_BIG_ENDIAN;
    }

    return endian_t;
}

const char* check_endian(void)
{
    uint32_t value = 1;

    uint8_t* ptr = (uint8_t*) &value;

    if (ptr[0] == value)
    {
        return "Little Endian";
    }
    else if (ptr[3] == value)
    {
        return "Big Endian";
    }
}

void convert_to_little_or_big_endian(uint32_t *const ptr)
{
    uint32_t temp = *ptr;

    printf("Before swapping: %04x\n", *ptr);

    *ptr = (((temp >> 24) & 0x000000ff) |
            ((temp >> 8) & 0x0000ff00) |
            ((temp << 8) & 0x00ff0000) |
            ((temp << 24) & 0xff000000));

    printf("After swapping: %04x\n", *ptr);
}

uint32_t convert_endian_using_builtin(uint32_t value)
{
    return __builtin_bswap32(value);
}