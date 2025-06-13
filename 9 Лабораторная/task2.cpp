#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>


size_t getStringLength(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wide = converter.from_bytes(str);
    return wide.length();
}

int main() {
    std::list<std::string> months = {
        "Январь",
        "Февраль",
        "Март",
        "Апрель",
        "Май",
        "Июнь",
        "Июль",
        "Август",
        "Сентябрь",
        "Октябрь",
        "Ноябрь",
        "Декабрь"
    };

    std::cout << "Исходный список месяцев:" << std::endl;
    for (const auto& month : months) {
        std::cout << month << " (" << getStringLength(month) << " символов)" << std::endl;
    }

    months.remove_if([](const std::string& str) {
        return getStringLength(str) < 5;
    });

    std::cout << "\nСписок после удаления строк короче 5 символов:" << std::endl;
    for (const auto& month : months) {
        std::cout << month << " (" << getStringLength(month) << " символов)" << std::endl;
    }

    return 0;
}
