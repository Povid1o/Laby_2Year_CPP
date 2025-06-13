#include <iostream>
#include <map>
#include <string>


void findProduct(const std::map<std::string, int>& products, const std::string& name) {
    auto it = products.find(name);
    if (it != products.end()) {
        std::cout << "Товар '" << name << "' найден. Цена: " << it->second << " руб." << std::endl;
    } else {
        std::cout << "Товар '" << name << "' не найден." << std::endl;
    }
}

int main() {

    std::map<std::string, int> products = {
        {"Молоко", 89},
        {"Хлеб", 45},
        {"Сахар", 65},
        {"Масло", 120},
        {"Сыр", 350},
        {"Колбаса", 280},
        {"Яблоки", 150},
        {"Бананы", 130}
    };


    std::cout << "Список товаров:" << std::endl;
    for (const auto& [name, price] : products) {
        std::cout << name << ": " << price << " руб." << std::endl;
    }

    std::cout << "\nПоиск товаров:" << std::endl;
    

    findProduct(products, "Молоко");

    findProduct(products, "Шоколад");

 
    std::string searchName;
    while (true) {
        std::cout << "\nВведите название товара для поиска (или 'выход' для завершения): ";
        std::getline(std::cin, searchName);
        
        if (searchName == "выход") {
            break;
        }
        
        findProduct(products, searchName);
    }

    return 0;
}
