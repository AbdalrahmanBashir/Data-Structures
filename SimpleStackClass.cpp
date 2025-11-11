// SimpleStackClass.cpp
// Simple stack implementation with dynamic array.

#include <iostream>
#include <iomanip>
#include <stdexcept>  // for std::overflow_error, std::underflow_error

class stackType
{
public:
    stackType(int num = 20);   // default size = 20
    ~stackType();

    void push(int item);        // add item to stack
    int pop();                  // remove and return top item
    int peek() const;           // return top item without removing

private:
    int* stack;                 // dynamic array to hold elements
    int stackSize;              // maximum stack size
    int top = -1;               // index of top element, -1 means empty
};

stackType::stackType(int num)
{
    stack = new int[num];       // allocate memory
    stackSize = num;
}

stackType::~stackType()
{
    delete[] stack;             // free memory
    stack = nullptr;            // avoid dangling pointer
}

void stackType::push(int item)
{
    if (top >= stackSize - 1) {
        throw std::overflow_error("Stack overflow: cannot push more items.");
    }
    stack[++top] = item;
}

int stackType::pop()
{
    if (top < 0) {
        throw std::underflow_error("Stack underflow: no items to pop.");
    }
    return stack[top--];
}

int stackType::peek() const
{
    if (top < 0) {
        throw std::underflow_error("Stack underflow: stack is empty.");
    }
    return stack[top];
}

int main()
{
    stackType newStack;

    // Push a few sample items onto the stack
    newStack.push(457);
    newStack.push(-1);
    newStack.push(2387);
    newStack.push(73);
    newStack.push(19);
    newStack.push(699);
    newStack.push(4);

    // Pop and print all items
    try {
        for (int i = 0; i < 7; ++i) {
            std::cout << std::setw(8) << newStack.pop() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nAll items popped.\n";

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
