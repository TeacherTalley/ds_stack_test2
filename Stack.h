#include "LinkedList.h"
#include <iostream>

/**
 * @brief A stack data structure implemented using a linked list.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class Stack {
public:
    /**
     * @brief Checks if the stack is empty.
     * 
     * @return true if the stack is empty, false otherwise.
     */
    bool empty() const {
        return list.empty();
    }

    /**
     * @brief Clears the stack, removing all elements.
     */
    void clear() {
        list.clear();
    }

    /**
     * @brief Returns the number of elements in the stack.
     * 
     * @return The number of elements in the stack.
     */
    size_t size() const {
        return list.size();
    }

    /**
     * @brief Pushes an element onto the top of the stack.
     * 
     * @param value The value to be pushed onto the stack.
     */
    void push(const T& value) {
        list.push_back(value);
    }

    /**
     * @brief Removes the element at the top of the stack.
     */
    T pop() {
        T value = list.back();
        list.pop_back();
        return value;
    }

    /**
     * @brief Returns the element at the top of the stack.
     * 
     * @return The element at the top of the stack.
     */
    T top() {
        return list.back();
    }

private:
    LinkedList<T> list; // The linked list used to store the elements of the stack.
};
