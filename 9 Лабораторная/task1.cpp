#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


bool compareCities(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {

    if (a.second != b.second) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main() {

    std::vector<std::pair<std::string, int>> cities = {
        {"Москва", 12678079},
        {"Санкт-Петербург", 5398064},
        {"Новосибирск", 1625631},
        {"Екатеринбург", 1493749},
        {"Казань", 1257391},
        {"Нижний Новгород", 1252236},
        {"Челябинск", 1189525},
        {"Самара", 1156659},
        {"Омск", 1154000},
        {"Ростов-на-Дону", 1137704}
    };


    std::cout << "Исходный список городов:" << std::endl;
    for (const auto& city : cities) {
        std::cout << city.first << ": " << city.second << " чел." << std::endl;
    }

    std::sort(cities.begin(), cities.end(), compareCities);


    std::cout << "\nОтсортированный список городов:" << std::endl;
    for (const auto& city : cities) {
        std::cout << city.first << ": " << city.second << " чел." << std::endl;
    }

    return 0;
}
