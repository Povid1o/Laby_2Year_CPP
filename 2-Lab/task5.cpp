#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]){
    int userNum {};
    int lengthOfResult{};
    vector<int> result {0};

    cout << "Введите число: ";
    cin >> userNum;

        for(int i = userNum; i >= 1; i = i / 2)
    {
        result.push_back(i % 2);
        lengthOfResult++;
    }

    cout << userNum << " в двоичной форме: ";
    
    for(int i = lengthOfResult; i > 0; i--)
    {
        cout << result[i];
    }

}