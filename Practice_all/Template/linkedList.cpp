#include <iostream>                      // Include the input/output stream library for console operations
using namespace std;                     // Use the standard namespace to avoid prefixing std::

// Template class for a singly linked list
template <typename T>                   // Declare a template so the class can store any data type T
    class Node {                        // Define a Node class to represent each element in the linked list
        public:
            T data;                     // Data of type T stored in the node
            Node* next;                 // Pointer to the next node in the list
            Node(T d) : data(d), next(nullptr) {} // Constructor: initialize node with data and set next to nullptr
    };

// Template class for the linked list
template <typename T>                   // Declare a template so the class can store any data type T
    class LinkedList { 
        private:
            Node<T>* head;              // Pointer to the first node (head) of the list

        public:
            LinkedList() : head(nullptr) {} // Constructor: initialize head pointer to nullptr (empty list)
            ~LinkedList() {                 // Destructor: free memory when the list is destroyed
                Node<T>* current = head;    // Start from the head of the list
                while (current != nullptr) { // Traverse the list and delete each node
                    Node<T>* nextNode = current->next; // Store the next node
                    delete current;         // Delete the current node
                    current = nextNode;     // Move to the next node
                }
            }

            // Function to insert a new node at the front of the list
            void insertFront(T value) {
                Node<T>* newNode = new Node<T>(value); // Create a new node with the given value
                newNode->next = head;                  // Point new node's next to current head
                head = newNode;                        // Update head to point to the new node
            }

            // Function to display the elements of the list
            void display() { 
                Node<T>* temp = head;                  // Start from the head of the list
                cout << "List: ";                      // Print a header for the list
                while (temp != nullptr) {              // Traverse the list
                    cout << temp->data << " ";         // Print the data of the current node
                    temp = temp->next;                 // Move to the next node
                }
                cout << endl;                          // Print a newline at the end
            }

            // Function to search for a value in the list
            bool search(T value) {                     // Check if the list contains a value
                Node<T>* temp = head;                  // Start from the head of the list
                while (temp != nullptr) {              // Traverse the list
                    if (temp->data == value)           // If current node's data matches the value
                        return true;                   // Return true if found
                    temp = temp->next;                 // Move to the next node
                }
                return false;                          // Return false if value not found
            }

            // Function to delete a node with a specific value
            void deleteValue(T value) { 
                if (!head) return;                     // If the list is empty, do nothing
                if (head->data == value) {             // If the head node contains the value to be deleted
                    Node<T>* temp = head;              // Store the head node
                    head = head->next;                 // Update head to the next node
                    delete temp;                       // Delete the old head node
                    return;                            // Exit after deleting the head node
                }

                Node<T>* current = head;               // Start from the head of the list
                while (current->next && current->next->data != value) // Traverse until next node is null or matches value
                    current = current->next;           // Move to the next node

                if (current->next) {                   // If the next node is not null (value found)
                    Node<T>* temp = current->next;     // Store the node to be deleted
                    current->next = temp->next;        // Update current node's next to skip the node to be deleted
                    delete temp;                       // Delete the node that was found
                }
            }
        };

int main() {
    LinkedList<int> list;                              // Create a LinkedList object for integers

    list.insertFront(10);                              // Insert 10 at the front of the list
    list.insertFront(20);                              // Insert 20 at the front (list: 20 10)
    list.insertFront(30);                              // Insert 30 at the front (list: 30 20 10)
    list.display();                                    // Display the list: List: 30 20 10

    list.deleteValue(20);                              // Delete the node with value 20 (list: 30 10)
    list.display();                                    // Display the list: List: 30 10

    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl; // Search for 10
    cout << "Search 99: " << (list.search(99) ? "Found" : "Not Found") << endl; // Search for 99

    return 0;                                          // End of program
}
