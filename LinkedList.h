#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    /**
     * @brief Default constructor for LinkedList class.
     */
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    /**
     * @brief Checks if the linked list is empty.
     * @return True if the linked list is empty, false otherwise.
     */
    bool empty() const {
        return count == 0;
    }

    /**
     * @brief Clears the linked list by deleting all nodes.
     */
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }

    /**
     * @brief Returns the size of the linked list.
     * @return The number of elements in the linked list.
     */
    int size() const {
        return count;
    }

    /**
     * @brief Adds a new element to the end of the linked list.
     * @param value The value to be added.
     */
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        count++;
    }

    /**
     * @brief Removes the last element from the linked list.
     */
    void pop_back() {
        if (empty()) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        count--;
    }

    /**
     * @brief Removes the first element from the linked list.
     */
    void pop_front() {
        if (empty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    
    /**
     * @brief Adds a new element to the beginning of the linked list.
     * @param value The value to be added.
     */
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            tail = newNode;
        }
        newNode->next = head;
        head = newNode;
        count++;
    }

    /**
     * @brief Inserts a new element at the specified index in the linked list.
     * @param index The index at which the value should be inserted.
     * @param value The value to be inserted.
     */
    void insert(int index, const T& value) {
        if (index < 0 || index > count) {
            return;
        }
        if (index == count) {
            push_back(value);
            return;
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    /**
     * @brief Removes the element at the specified index from the linked list.
     * @param index The index of the element to be removed.
     */
    void erase(int index) {
        if (index < 0 || index >= count) {
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            if (index == count - 1) {
                tail = temp;
            }
        }
        count--;
    }

    /**
     * @brief Returns the value of the first element in the linked list.
     * @return The value of the first element.
     * @throws std::out_of_range if the linked list is empty.
     */
    T front() const {
        if (empty()) {
            throw std::out_of_range("LinkedList is empty");
        }
        return head->data;
    }

    /**
     * @brief Returns the value of the last element in the linked list.
     * @return The value of the last element.
     * @throws std::out_of_range if the linked list is empty.
     */
    T back() const {
        if (empty()) {
            throw std::out_of_range("LinkedList is empty");
        }
        return tail->data;
    }

    /**
     * @brief Prints the elements of the linked list.
     */
    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

