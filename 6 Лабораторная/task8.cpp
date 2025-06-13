#include <iostream>

class DynamicArray {
private:
    int* data;
    size_t size;
public:
    DynamicArray(size_t n) : size(n) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) data[i] = 0;
    }
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }
    ~DynamicArray() {
        delete[] data;
    }
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }
    int& operator[](size_t idx) { return data[idx]; }
    const int& operator[](size_t idx) const { return data[idx]; }
    size_t getSize() const { return size; }
};

int main() {
    DynamicArray arr1(3);
    arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
    DynamicArray arr2(1);
    arr2 = arr1;
    arr2[0] = 99;
    std::cout << "arr1[0]: " << arr1[0] << ", arr2[0]: " << arr2[0] << std::endl;
    return 0;
}
