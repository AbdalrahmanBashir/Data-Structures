#include <iostream>
#include <memory>

class Node {
private:
   int data; // The data stored in the node
   std::shared_ptr<Node> next; // Smart pointer pointing to the next node
public:
   // Constructor: initializes data and sets next to nullptr
   Node(int value) : data(value), next(nullptr){}
   int getData() const { return data; } // Getter for data
   void setData(int value) { data = value; } // Setter for data
   // Getter for next, returns a shared pointer to the next node
   std::shared_ptr<Node> getNext() const { return next; }
   // Setter for next, connects this node to the next node
   void setNext(const std::shared_ptr<Node>& nextNode){ next = nextNode; }
};


class SingleLinkedList {
private:
   std::shared_ptr<Node> head; // Smart pointer pointing to the the first node in the list the head
   size_t size;                // Keeps track of the number of nodes in the list

public:
   // Constructor: initializes head to nullptr and size to 0
   SingleLinkedList() : head(nullptr), size(0){}

   void append(int value) 
   {
      // Create a new node with the given value
      auto newNode = std::make_shared<Node>(value);
      if(!head) // If the list is empty, set head to the new node
      {
         head = newNode; // Set head to the new node
      } 
      else {
               auto current = head; // Start from the head
               // Traverse to the end of the list
               while (current->getNext()) // While there is a next node
               {
                     current = current->getNext(); // Move to the next node
               }
               current->setNext(newNode);  // Link the last node to the new node
            }
       // Increment the size of the list
       ++size;
   }

   // Prepend a new node with the given value at the beginning of the list
   void prepend(int value) 
   {
      // Create a new node with the given value
        auto newNode = std::make_shared<Node>(value); 
        newNode->setNext(head); // Link the new node to the current head
        head = newNode; // Update head to point to the new node
        ++size;  // Increment the size of the list
   }

   void remove(int value) 
   {
         if(!head) return;  // If the list is empty, nothing to remove
         
         if(head->getData() == value) // If the head node is to be removed
         {
            head = head->getNext(); // Update head to the next node
            --size;
            return;
         }

         auto current = head; // Start from the head
         // Traverse the list to find the node before the one to be removed

         while (current->getNext() && current->getNext()->getData() != value)
         {
            current = current->getNext(); // Move to the next node
         }

         // If the node to be removed is found
         if (current->getNext())
         {
            // Bypass the node to be removed
            current->setNext(current->getNext()->getNext());

            --size; // Decrement the size of the list
         }
   }

   size_t getSize() { return size;} // Returns the current size of the list

   void printList() const 
   {
      // Traverse the list and print each node's data
        auto current = head; // Start from the head
        while (current)
        {
           std::cout << current->getData() << " -> ";
           current = current->getNext();
        }

        std::cout <<  std::endl;
   }
   
   bool isEmpty() { return size == 0; }

};


int main(){

  SingleLinkedList list;
  list.append(10);
  list.append(20);
  list.append(30);
  list.prepend(5);
  std::cout << "Linked List: " << std::endl;
  list.printList();
  std::cout << "Size:  "  << list.getSize() << std::endl;
  std::cout << "Removing 20...." << std::endl;
  list.remove(20);
  list.printList();
  std::cout << "Size after rmovel: " << list.getSize() << std::endl;
  return 0;
}


