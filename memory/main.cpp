#include <iostream>

#include "allocs.h"

#define MALLOC_SIZE 10U
#define CALLOC_SIZE 10U

int main()
{
    uint32_t* m_ptr = create_uint32_malloc((uint8_t) MALLOC_SIZE);
    uint32_t arr[MALLOC_SIZE] = {{0U}};
    bool status = false;
    DATA_WRITE_METHOD_t write_method_t = e_COPY_METHOD;

    for (uint8_t i = 0; i < MALLOC_SIZE; i++)
    {
        arr[i] = i * i;
    }

    write_data_to_memory((uint32_t *const) m_ptr, (uint32_t const *const) arr, MALLOC_SIZE, write_method_t);
    read_data_from_memory((uint32_t *const) m_ptr, MALLOC_SIZE);

    status = free_uint32_memory(m_ptr);
    printf("Status of freed m_ptr memory: %d\n", status);

    uint32_t raw_data = 0x12345678;
    ENDIANS_t endian_t = get_endian_type((uint32_t *const) &raw_data);

    printf("Endian type: %d\n", endian_t);

    /* Different types of string initialization */
    // char* str = "Hello";
    // char* str = {'H','e','l','l','o','\0'};
    // char str[] = "Hello";
    // char str[15] = "Hello";
    // char str[] = {'H','e','l','l','o','\0'};

    const char* str = check_endian();
    printf("Endianness - ");
    puts(str);

    convert_to_little_or_big_endian((uint32_t *const) &raw_data);

    printf("Convert endian using builtin: %04x\n", convert_endian_using_builtin(raw_data));

    return 0;
}