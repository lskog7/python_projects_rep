//
//  Created by Tema on 21.02.2024. (v1.0)
//

#ifndef MAIN_PROJECT_VALIDATION_1_0_H
#define MAIN_PROJECT_VALIDATION_1_0_H


//
//  Данная библиотека предназначена для проверки
//  ввода пользователя в вашей программе.
//
//  Для получения справки о том, какие есть команды и как ими пользоваться
//  используйте функцию valHelp().
//


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <conio.h>


using namespace std;


//  Макрос для вывода выражений или переменных.
#define PrintExpression(Expression)\
     std::cout << "{" #Expression "}: " << (Expression) <<\
            std::endl;


//  Справка по функциям.
std::string valHelp();

//  Только английские буквы (заглавные и строчные).
std::string valOnlyChar(const std::string &prompt);

//  Только цифры.
std::string valOnlyDigits(const std::string &prompt);

//  Ввод допустимых символов для следующей функции.
std::string valValidSymbol();

//  Только то, что было введено в validSymbols.
std::string valInput();


std::string valHelp() {
    int inp = 1;

    std::cout << ">>>\tList of functions:" << std::endl;
    std::cout << ">" << std::endl;
    std::cout << ">>>\t1. valHelp() - basic information about the library. (current)" << std::endl;
    std::cout << ">" << std::endl;
    std::cout
            << ">>>\t2. valOnlyChar('prompt') - user can only enter letters of English alphabet.\n>>>\tTypes '>>>    Your prompt' in console."
            << std::endl;
    std::cout << ">" << std::endl;
    std::cout << ">>>\t3. valOnlyDigits('prompt') - user can only enter digits." << std::endl;
    std::cout << ">" << std::endl;
    std::cout
            << ">>>\t4. valInput('prompt') - user can only enter symbols that are presented in validChars (string).\n>>>\tTypes '>>>    Your prompt' in console.\n>>>\tvalidChars is made with valValidSymbol()."
            << std::endl;
    std::cout << ">" << std::endl;
    std::cout
            << ">>>\t5. valValidSymbol() - function to enter a list (string) of valid symbols which will affect valInput() function.\n>>>\tTypes '>>>    Your prompt' in console.\n>>>\tUnrecommended to use manually."
            << std::endl;
    std::cout << ">" << std::endl;
    std::cout << ">>>\t6. PrintExpression(expression) - macro to output expressions like: {expression/result}."
              << std::endl;

    //
    // Пока не допилил для CLion. В обычной консоли можно раскомментить. Должно работать.
    //

//    std::cout << ">>>\tEnter 0 to clear console.\n>>>";
//    do
//    {
//        std::cin >> inp;
//        if (inp == 0)
//        {
//            system("cls");
//            std::cout << ">>>\tConsole cleared!" << std::endl;
//        }
//    }
//    while (inp != 0);
}

// Проверка на соответствие заданным значениям
std::string valInput(const std::string &prompt) {
    
    std::string validChars = valValidSymbol();
    std::string userInput;
    bool isValid = false;
    string input;

    do {
        std::cout << ">>>" << prompt;
        std::cin >> input;

        // Проверяем, содержит ли введенное значение только допустимые символы
        isValid = true;
        for (char c: input) {
            if (validChars.find(toupper(c)) == std::string::npos) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            std::cout << ">>>\tWRONG INPUT!\n>>>\tRETRY!" << std::endl;
        }
    } while (!isValid);

    return input;
}

// Функция проверки ввода на наличие только цифр
string valOnlyDigits(const std::string &prompt) {
    std::string userInput;
    bool onlyDigits = true;

    do {
        std::cout << ">>>\t" << prompt;
        std::cin >> userInput;

        for (char c: userInput) {
            if (!isdigit(c)) {
                onlyDigits = false;
                break;
            }
        }

        if (!onlyDigits) {
            std::cout << ">>>\tWRONG INPUT!\n>>>\tYou can only enter digits." << std::endl;
        }
    } while (!onlyDigits);

    return userInput;
}

// Функция для проверки ввода на содержание только букв
std::string valOnlyChar(const std::string &prompt) {
    std::string userInput;
    bool isValid = false;

    do {
        std::cout << ">>>\t" << prompt;
        std::cin >> userInput;

        // Проверяем, содержит ли введенное значение только строчные и заглавные английские буквы и цифры
        isValid = true;
        for (char c: userInput) {
            if (!isalnum(c) || !isalpha(c)) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            std::cout << ">>>\tWRONG INPUT!\tYou can only enter digits and latin letters!" << std::endl;
        }
    } while (!isValid);

    return userInput;
}


std::string valValidSymbol() {
    std::string vs;

    std::cout << ">>>\tEnter a line of valid symbols.\n>>> ";
    std::cin >> vs;
    std::cout << ">>>\tValid symbols are: " << vs << std::endl;
    return vs;
}


#endif //MAIN_PROJECT_VALIDATION_1_0_H
