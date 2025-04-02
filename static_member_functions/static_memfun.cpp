#include "static_memfun.hpp"

int static_memfun::a_ = 0;

// Cannot assign value for static data member (a_), since static members are not part of objects/instances
static_memfun::static_memfun(int b) 
    : b_{b}
{
    std::cout << "b_ initialized: " << b_ << std::endl;
    std::cout << std::endl;
}

void static_memfun::public_non_static_interface(int a)
{
    std::cout << "static_memfun::public_non_static_interface()" << std::endl
        << "Can call other public (static, nonstatic) and private (static, nonstatic) functions, and (static, nonstatic) data members." << std::endl;

    a_ = a;

    std::cout << "Static data member a_: " << a_ << std::endl
        << "Non static data member b_: " << b_ << std::endl;

    std::cout << std::endl;

    public_static_fun();

    // OK
    // private_static_fun();

    // OK
    private_non_static_fun();

    // OK with static_memfun or static_memfun& return type
    // return *this;
}

void static_memfun::public_static_fun(void)
{
    std::cout << "static_memfun::public_static_fun()" << std::endl
        << "This function doesn't have *this pointer since it is not part of any object." << std::endl
        << "Cannot access nonstatic data member, can only access static data member." << std::endl
        << "This function can be called either by Class Name :: Function name or object.Function name "
         "or from some other public function" << std::endl;

    std::cout << "Static data member a_ has value: " << a_ << std::endl;

    std::cout << std::endl;

    // This will throw compiler error
    // std::cout << "Non static data member b_ has value: " << b_ << std::endl;

    // This will throw compiler error
    // public_non_static_interface(10);

    // NOT OK
    // return *this;
}

void static_memfun::private_non_static_fun(void)
{
    std::cout << "static_memfun::private_non_static_fun()" << std::endl
        << "Can call other private (static, non static) functions and private (static, nonstatic) data members." << std::endl;

    std::cout << "Static data member a_: " << a_ << std::endl
        << "Non static data member b_: " << b_ << std::endl;

    std::cout << std::endl;

    // OK
    private_static_fun();
}

void static_memfun::private_static_fun(void)
{
    std::cout << "static_memfun::private_static_fun()" << std::endl
        << "This function doesn't have *this pointer since it is not part of any object." << std::endl
        << "Cannot access nonstatic data member or member function, can only access static members." << std::endl
        << "This can be called by all the private (static, non static) and public (static, non static) functions." << std::endl;

    std::cout << "Static data member a_: " << a_ << std::endl;

    std::cout << std::endl;

    // This will throw compiler error
    // std::cout << "Non-static data member b_: " << b_ << std::endl;

    // NOT OK, cannot call nonstatic member function
    // private_non_static_fun();
}