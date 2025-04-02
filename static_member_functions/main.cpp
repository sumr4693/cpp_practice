#include <iostream>

#include "static_memfun.hpp"

int main()
{
    static_memfun memfun {10};

    memfun.public_non_static_interface(5);

    // Calling public static function through an object works
    memfun.public_static_fun();

    return 0;
}