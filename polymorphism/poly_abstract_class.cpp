#include <iostream>
// Dynamic memory management library
#include <memory>

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

    // Wild pointer
    basicOperations *baseOp2;
    {
        // Base class pointer to derived class object in heap
        baseOp2 = new addOperation();
        add_result = baseOp2->arithmetic_operation(-10,5);
        cout << "Base class pointer to derived class object in heap" << endl;
        cout << "Result: " << add_result << endl;
    }

    add_result = baseOp2->arithmetic_operation(-10,5);
    cout << "Result outside the scope of memory allocation: " << add_result << endl;

    // We will have memory leak if not deleted manually
    delete baseOp2;

    // Note: Will get segmentation fault (Core dumped) since we have freed the dynamic memory allocation
    // baseOp2 doesn't point to anything after freeing memory - dangling pointer
    // add_result = baseOp2->arithmetic_operation(-10,5);

    // Base class pointer (smart pointer) to derived class object in heap with unique pointer
    // Normal initialization with unique pointer - but we split it to understand the use of scope in smart pointers
    // unique_ptr<basicOperations> addOp_uPtr(new addOperation());
    unique_ptr<basicOperations> addOp_uPtr;
    {
		    addOp_uPtr = unique_ptr<addOperation>(new addOperation());
        {
			      add_result = addOp_uPtr->arithmetic_operation(50,40);
						cout << "Result of unique pointer 1: " << add_result << endl;
        }
				// Forcefully freeing memory
				//addOp_uPtr.reset();
    }
		// It should throw segmentation fault here, since the memory should have been automatically freed after the scope ended.
		// To be continued...
		add_result = addOp_uPtr->arithmetic_operation(50,40);
		cout << "Result of unique pointer 1 outside the scope: " << add_result << endl;

    return 0;
}