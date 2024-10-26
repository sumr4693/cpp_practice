#include <iostream>

using namespace std;

// Abstract (base) class - at least one pure virtual function
class basicOperations {

  public:
    // Default constructor
    basicOperations () {
        cout << "Basic operations base class instance created" << endl;
    }

    // Pure virtual function
    virtual int arithmetic_operation(int a, int b) = 0;
};

class addOperation : public basicOperations {

  private:
    int operand_a, operand_b, result;

  public:
    // Default constructor
    addOperation() {
        cout << "Add operation derived class default constructor" << endl;
    }

    // Constructor overloading
    // Parameterized constructor
    addOperation(int a, int b)
        : operand_a(a), operand_b(b) {
        cout << "Add operation derived class instantiated with parameters" << endl;
        cout << "operand_a: " << operand_a << endl;
        cout << "operand_b: " << operand_b << endl;
    }

    // Polymorphism - Overriding pure virtual function from base class in derived class
    int arithmetic_operation(int a, int b) override {
        operand_a = a;
        operand_b = b;

        result = operand_a + operand_b;

        return result;
    }

    void show_operandA()
    {
        cout << "Operand A: " << operand_a << endl;
    }

    void show_operandB()
    {
        cout << "Operand B: " << operand_b << endl;
    }

    void show_result()
    {
        cout << "Result: " << result << endl;
    }
};

int main()
{
    int add_result;

    // Note: Abstract base class cannot have object. Will get compile time error.
    //basicOperations baseOp;

    // Though abstract class cannot have any object, it can have pointer - Base class pointer
    basicOperations *baseOp;

    // Derived class objects
    addOperation addOp; //Allocated in stack portion of RAM
    addOperation addOp_param(5, 6); //Stack portion of RAM

    add_result = addOp_param.arithmetic_operation(5,6);

    cout << "Add result: " << add_result << endl;

    // Base class pointer to Derived class object
    baseOp = &addOp_param;

    add_result = baseOp->arithmetic_operation(7,11);

    cout << "New result: " << add_result << endl;

    // Checking that the variables in derived class are modified using base class pointer from the above step
    addOp_param.show_operandA();
    addOp_param.show_operandB();
    addOp_param.show_result();

    // Accessing the same above "show" functions (not part of base class) from base class pointer
    // Note: Since they are not part of base class, they cannot be called using base class pointer. Will get compile time error.
    // baseOp->show_operandA();
    // baseOp->show_operandB();
    // baseOp->show_result();

    //TODO: base class pointer to derived class object in heap
    //TODO: base class pointer (smart pointer) to derived class object in heap

    return 0;
}