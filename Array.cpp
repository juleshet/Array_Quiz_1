#include <iostream>
#include <stdexcept>
#include "Array.h"

// Constructor: allocate array with given capacity
Array::Array(int capacity) : capacity_(capacity), size_(0) {
    data_ = new int[capacity_];
}

// Destructor: free allocated memory
Array::~Array() {
    delete[] data_;
}

// Add value at the end if there's space
bool Array::Add(int value) {
    if (size_ == capacity_) {
        return false;  // no space
    }

    data_[size_] = value;  // place value at end
    size_++;               // increase size
    return true;
}

// Insert value at specified index, shifting elements to the right
bool Array::InsertAt(int index, int value) {

    // Check if index is valid
    if (index < 0 || index > size_) {
        return false;
    }

    // Check if array is already full
    if (size_ == capacity_) {
        return false;
    }

    // Shift elements to the right starting from the end
    for (int i = size_; i > index; i--) {
        data_[i] = data_[i - 1];
    }

    // Insert the new value at the given index
    data_[index] = value;

    // Increase size
    size_++;

    return true;
}

// Delete element at index, shifting elements left
bool Array::DeleteAt(int index) {

    // Check if index is valid
    if (index < 0 || index >= size_) {
        return false;
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }

    // Reduce size
    size_--;

    return true;
}

// Update element at index
bool Array::UpdateAt(int index, int new_value) {

    // Check if index is valid
    if (index < 0 || index >= size_) {
        return false;
    }

    // Replace old value with new value
    data_[index] = new_value;

    return true;
}

// Print all elements
void Array::Print() const {
    if (size_ == 0) {
        std::cout << "[Empty]" << std::endl;
        return;
    }

    std::cout << "[ ";
    for (int i = 0; i < size_; i++) {
        std::cout << data_[i];
        if (i != size_ - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

// Get current size
int Array::Size() const {
    return size_;
}

// Get max capacity
int Array::Capacity() const {
    return capacity_;
}

// Get value at index or throw if invalid
int Array::GetAt(int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}