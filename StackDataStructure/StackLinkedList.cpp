#include <iostream>
#include <memory>

class StackNode {
private:
    int data; // The data stored in the stack node
    std::shared_ptr<StackNode> next; // Smart pointer pointing to the next stack node
public:
    // Constructor: initializes data and sets next to nullptr
    StackNode(int value) : data(value), next(nullptr) {}
    int getData() const { return data; } // Getter for data
    void setData(int value) { data = value; } // Setter for data
    // Getter for next, returns a shared pointer to the next stack node
    std::shared_ptr<StackNode> getNext() const { return next; }
    // Setter for next, connects this stack node to the next stack node
    void setNext(const std::shared_ptr<StackNode>& nextNode) { next = nextNode; }
};

class StackLinkedList {
private:
    std::shared_ptr<StackNode> top; // Smart pointer pointing to the top stack node
    size_t size;                    // Keeps track of the number of nodes in the stack
public:
    // Constructor: initializes top to nullptr and size to 0
    StackLinkedList() : top(nullptr), size(0) {}
    void push(int value) 
    {
        // Create a new stack node with the given value
        auto newNode = std::make_shared<StackNode>(value);
        newNode->setNext(top); // Link the new node to the current top
        top = newNode; // Update top to point to the new node
        ++size;  // Increment the size of the stack
    }
    void pop() 
    {
        if (!top) // If the stack is empty, do nothing
            return;
        top = top->getNext(); // Update top to the next node
        --size; // Decrement the size of the stack
    }
    int peek() const 
    {
        if (!top) // If the stack is empty, return -1 (or throw an exception)
            return -1;
        return top->getData(); // Return the data of the top node
    }
    size_t getSize() const { return size; } // Returns the current size of the stack
    bool isEmpty() const { return size == 0; } // Checks if the stack is empty
    void printStack() const 
    {
        // Traverse the stack and print each node's data
        auto current = top; // Start from the top
        while (current)
        {
            std::cout << current->getData() << " -> ";
            current = current->getNext();
        }
        std::cout << "nullptr" << std::endl; // Indicate the end of the stack
    }
};

int main() {
    StackLinkedList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Stack after pushes: " << std::endl;
    stack.printStack();
    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Size: " << stack.getSize() << std::endl;
    std::cout << "Popping top element..." << std::endl;
    stack.pop();
    stack.printStack();
    std::cout << "Top element after pop: " << stack.peek() << std::endl;
    std::cout << "Size after pop: " << stack.getSize() << std::endl;
    return 0;
}