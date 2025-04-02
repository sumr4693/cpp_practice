#pragma once

#include <iostream>

class static_memfun
{
public:

    static_memfun() = delete;

    static_memfun(int b);

    // NOT OK
    // static static_memfun& public_static_fun(void);
    static void public_static_fun(void);

    // OK 
    // static_memfun& public_non_static_interface(int a); 
    void public_non_static_interface(int a);

private:

    static void private_static_fun(void);

    void private_non_static_fun(void);

    static int a_;
    int b_;
};

// class static_memfun
// {
// public:

//     static_memfun() = delete;

//     static_memfun(int b);

// private:

//     static int a_;
//     int b_;
// };