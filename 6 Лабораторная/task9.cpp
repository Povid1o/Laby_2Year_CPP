#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;
public:
    String(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    ~String() {
        delete[] data;
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }
    char& operator[](size_t idx) {
        return data[idx];
    }
    const char& operator[](size_t idx) const {
        return data[idx];
    }
    const char* c_str() const { return data; }
};

int main() {
    String s("Hello");
    std::cout << "Исходная строка: " << s.c_str() << std::endl;
    s[0] = 'h';
    std::cout << "После изменения: " << s.c_str() << std::endl;
    char ch = s[1];
    std::cout << "Второй символ: " << ch << std::endl;
    return 0;
}
