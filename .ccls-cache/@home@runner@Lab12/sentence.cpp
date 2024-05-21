#include "sentence.h"

#include <iostream>
#include <string>

using namespace std;

void inputData(string &Sentence) {
    cout << "Введіть речення: ";
    getline(cin, Sentence); // Отримання речення з cin
}

int CountCharA(const string &Sentence) {
    size_t pos = 0; // Змінна для позиції символу 'a'
    int k = 0; // Кількість символів 'a'

    char ch = 'a'; // Символ, який шукаємо

    while ((pos = Sentence.find(ch, pos)) != -1) {
        k++; // Збільшуємо лічильник
        pos++; // Перехід до наступної позиції
    }

    return k; // Повертаємо кількість символів 'a'
}

void displayResult(const string &Sentence) {
    cout << "Результат: " << Sentence << endl; // Виведення речення
}