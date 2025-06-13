#include <iostream>
#include <string>

class Secret;

class SecretAccess {
public:
    void printSecret(const Secret& s) const;
};

class Secret {
private:
    std::string data;
public:
    Secret(const std::string& d) : data(d) {}
    friend class SecretAccess;
};

void SecretAccess::printSecret(const Secret& s) const {
    std::cout << "Секретные данные: " << s.data << std::endl;
}

int main() {
    Secret secret("Пароль123");
    SecretAccess access;
    access.printSecret(secret);
    return 0;
}
