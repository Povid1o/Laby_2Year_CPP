#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main(int argc, const char * argv[]) {
    string input;
    int vowelCount = 0;
    
    cout << "Введите строку: ";
    getline(cin, input);

    for (char c : input) {
        if (isVowel(c)) {
            vowelCount++;
        }
    }
    
    cout << "Количество гласных букв в строке: " << vowelCount << endl;
    
    return 0;
}