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
#include "validation_1.0.h"

using namespace std;

//
// Лабораторная работа №1
// "Классы, объекты и отношения между ними"
//
// Классы: питомец, миска, еда, подстилка.
// Мой питомец: улитка.
//


std::string validateInput(const std::string &prompt) {
    std::string validChars = "abcdefABCDEF0123456789";
    std::string userInput;
    bool isValid = false;

    do {
        std::cout << ">>>" << prompt;
        std::cin >> userInput;

        // Проверяем, содержит ли введенное значение только допустимые символы
        isValid = true;
        for (char c: userInput) {
            if (validChars.find(std::tolower(c)) == std::string::npos) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            std::cout << ">>>\tWRONG INPUT!\n>>>\tRETRY!" << std::endl;
            std::cin.clear(); // очистить флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистить буфер ввода
        }
    } while (!isValid);

    return userInput;
}


class Food {
    friend class Snail;

    friend class Bowl;

private:
    mutable std::string food_name;
    mutable bool food_status; // Новая или испорченая.

public:
    // Функции инициализации
    Food(std::string fn, bool fs) {
        food_name = fn;
        food_status = fs;
        std::cout << ">>> Food initialised." << std::endl;
        PrintFoodInfo();
    }

    Food(std::string fn) : Food(fn, true) {}

    Food() : Food("Grass", true) {}

    // Конструктор копирования
    Food(const Food &f) {
        food_name = f.food_name;
        food_status = f.food_status;
    }

    // Функции вывода информации
    void PrintFoodInfo() const {
        std::cout << "Food name: " << food_name << std::endl;
        std::cout << "Status (1 - fresh, 0 - expired): " << food_status << std::endl;
    }

    // Функции изменения переменных
    void SetFoodName(std::string fn) {
        food_name = fn;
    }

    void SetFoodStatus(bool fs) {
        if (fs == 1 || fs == 0)
            food_status = fs;
    }
};


class Bedding {
    friend class Snail;

private:
    std::string bedding_material;
    mutable bool bedding_status; // Грязная или чистая.

public:
    // Функции инициализации
    Bedding(std::string bm, bool bs) {
        bedding_material = bm;
        bedding_status = bs;
        std::cout << ">>> Bedding Initialized." << std::endl;
        PrintBeddingInfo();
    }

    Bedding(std::string bm) : Bedding(bm, true) {}

    Bedding(bool bs) : Bedding("Grass", bs) {}

    Bedding() : Bedding("Grass", true) {}

    // Конструктор копирования
    Bedding(const Bedding &b) {
        bedding_material = b.bedding_material;
        bedding_status = b.bedding_status;
    }

    // Функции вывода информации
    void PrintBeddingInfo() const {
        std::cout << "Bedding Material: " << bedding_material << std::endl;
        std::cout << "Bedding status (1 - fresh, 0 - dirty): " << bedding_status << std::endl;
    }
};


class Bowl {
    friend class Snail;

private:
    std::string nametag; // Имя на мисочке
    mutable std::string food_type;
    mutable unsigned food_amount; // Кол-во еды в граммах

public:
    // Функции инициализации
    Bowl(std::string nt, std::string ft, unsigned fa) {
        nametag = nt;
        food_type = ft;
        food_amount = fa;
        std::cout << ">>> Bowl initialised." << std::endl;
        PrintBowlInfo();
    }

    Bowl(std::string nt, std::string ft) : Bowl(nt, ft, 0) {}

    Bowl(std::string nt) : Bowl(nt, "Nothing", 0) {}

    Bowl() : Bowl("Empty", "Nothing", 0) {}

    // Конструктор копирования
    Bowl(const Bowl &b) {
        nametag = b.nametag;
        food_type = b.food_type;
        food_amount = b.food_amount;
    }

    // Функции вывода информации
    void PrintBowlInfo() const {
        std::cout << "Nametag: " << nametag << std::endl;
        std::cout << "Food type: " << food_type << std::endl;
        std::cout << "Food amount (gramm): " << food_amount << std::endl;
    }

    // Функции изменения переменных
    void SetNametag(std::string nt) {
        nametag = nt;
    }

    void SetFoodType(std::string ft) {
        food_type = ft;
    }

    void SetFoodAmount(unsigned fa) {
        if (fa > 0 && fa < 1000)
            food_amount = fa;
    }
};


class Snail {
private:
    std::string name;
    std::string type; // Порода улитки
    std::string color;
    bool rakhit;
    mutable unsigned age;
    mutable unsigned hunger = 50;
    mutable unsigned thirst = 50;
    mutable unsigned happiness = 50;

public:
    // Функции инициализации
    Snail(std::string s_name, unsigned s_age, std::string s_type, std::string s_color, bool s_rakhit) {
        name = s_name;
        type = s_type;
        color = s_color;
        rakhit = s_rakhit;
        age = s_age;
        std::cout << ">>> Snail " << name << " has been created." << std::endl;
        PrintSnailInfo();
    }

    Snail(std::string s_name, unsigned s_age, std::string s_type, std::string s_color) : Snail(s_name, s_age, s_type,
                                                                                               s_color, false) {}

    Snail(std::string s_name, unsigned s_age, std::string s_color) : Snail(s_name, s_age, "Undefined", s_color,
                                                                           false) {}

    Snail(std::string s_name, unsigned s_age) : Snail(s_name, s_age, "Undefined", "Undefined", false) {}

    Snail(std::string s_name) : Snail(s_name, 1, "Undefined", "Undefined", false) {}

    Snail() : Snail("Snail", 1, "Lake", "Brown", false) {}

    // Конструктор копирования
    Snail(const Snail &s) {
        name = s.name;
        type = s.type;
        color = s.color;
        rakhit = s.rakhit;
        age = s.age;
    }

    // Фукнции установки параметров.
    void SetName(std::string n) {
        name = n;
    }

    void SetAge(unsigned a) {
        if (a > 0 && a < 10)
            age = a;
    }

    void SetType(std::string t) {
        type = t;
    }

    void SetColor(std::string c) {
        color = c;
    }

    void SetRakhit(bool r) {
        if (r == 0 || r == 1)
            rakhit = r;

    }

    // Функции вывода информации
    void PrintSnailInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Rakhit: " << rakhit << std::endl;
        std::cout << "Hunger: " << hunger << std::endl;
        std::cout << "Thirst: " << thirst << std::endl;
        std::cout << "Happiness: " << happiness << std::endl;
    }

    // Функции получения значений переменных
    std::string GetName() const {
        return name;
    }

    unsigned GetAge() const {
        return age;
    }

    std::string GetType() const {
        return type;
    }

    std::string GetColor() const {
        return color;
    }

    bool GetRakhit() const {
        return rakhit;
    }

    unsigned GetHunger() const {
        return hunger;
    }


    unsigned GetThirst() const {
        return thirst;
    }

    unsigned GetHappiness() const {
        return happiness;
    }

    // Функции изменения переменных
    void FeedSnail() const {
        if (hunger <= 90) {
            hunger += 10;
        } else {
            hunger = 100;
        }
    }

    void WaterSnail() const {
        if (thirst <= 90) {
            thirst = thirst + 10;
        } else {
            thirst = 100;
        }
    }

    void PlaySnail() const {
        if (happiness <= 90) {
            happiness = happiness + 10;
        } else {
            happiness = 100;
        }
    }

    void ChangeBadding() {}

    void FillBowl() {}

    void EmptyBowl() {}
};


//
// Лабораторная работа №2
// "Иерархия классов"
//
// Матрица шестнадцатиричных чисел размера 2х2
//


class hexMatrix {
protected:
    std::string matrix[2][2];

public:
    hexMatrix() {
        matrix[0][0] = "0";
        matrix[0][1] = "0";
        matrix[1][0] = "0";
        matrix[1][1] = "0";
    }

    hexMatrix(const std::string &a, const std::string &b, const std::string &c, const std::string &d) {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    void printMatrix() const {
        std::cout << "Matrix:\n";
        std::cout << matrix[0][0] << " " << matrix[0][1] << std::endl;
        std::cout << matrix[1][0] << " " << matrix[1][1] << std::endl;
    }

    virtual void readNumber() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << "Enter a hexadecimal number: ";
                std::cin >> matrix[i][j];


                while (!isValidHex(matrix[i][j])) {
                    std::cout
                            << "Wrong! Enter a hexadecimal number: ";
                    std::cin >> matrix[i][j];
                }
            }
        }
    }

    hexMatrix operator+(const hexMatrix &other) const {
        hexMatrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.matrix[i][j] = addHex(matrix[i][j], other.matrix[i][j]);
            }
        }
        return result;
    }

    // Subtraction
    hexMatrix operator-(const hexMatrix &other) const {
        hexMatrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.matrix[i][j] = subtractHex(matrix[i][j], other.matrix[i][j]);
            }
        }
        return result;
    }

    hexMatrix operator*(const hexMatrix &other) const {
        hexMatrix result;
        result.matrix[0][0] = addHex(multiplyHex(matrix[0][0], other.matrix[0][0]),
                                     multiplyHex(matrix[0][1], other.matrix[1][0]));
        result.matrix[0][1] = addHex(multiplyHex(matrix[0][0], other.matrix[0][1]),
                                     multiplyHex(matrix[0][1], other.matrix[1][1]));
        result.matrix[1][0] = addHex(multiplyHex(matrix[1][0], other.matrix[0][0]),
                                     multiplyHex(matrix[1][1], other.matrix[1][0]));
        result.matrix[1][1] = addHex(multiplyHex(matrix[1][0], other.matrix[0][1]),
                                     multiplyHex(matrix[1][1], other.matrix[1][1]));
        return result;
    }

protected:
    bool isValidHex(const std::string &str) const {
        return !str.empty() &&
               std::all_of(str.begin(), str.end(), [](char c) { return std::isxdigit(static_cast<unsigned char>(c)); });
    }


    std::string addHex(const std::string &a, const std::string &b) const {
        std::string result;


        int carry = 0;
        int len_a = a.size();
        int len_b = b.size();
        int max_len = std::max(len_a, len_b);


        for (int i = 0; i < max_len; ++i) {
            int val_a = (i < len_a) ? hexCharToInt(a[len_a - 1 - i]) : 0;
            int val_b = (i < len_b) ? hexCharToInt(b[len_b - 1 - i]) : 0;


            int sum = val_a + val_b + carry;
            carry = sum / 16;
            sum %= 16;


            result.insert(result.begin(), intToHexChar(sum));
        }


        if (carry > 0) {
            result.insert(result.begin(), intToHexChar(carry));
        }


        return result;
    }


    int hexCharToInt(char c) const {
        if (isdigit(c)) {
            return c - '0';
        } else {
            return toupper(c) - 'A' + 10;
        }
    }


    char intToHexChar(int val) const {
        if (val >= 0 && val <= 9) {
            return '0' + val;
        } else {
            return 'A' + (val - 10);
        }
    }


    std::string subtractHex(const std::string &a, const std::string &b) const {
        std::string temp;
        std::string num1 = a;
        std::string num2 = b;
        if (a < b) {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        std::string result;
        int borrow = 0;
        int len_a = num1.size();
        int len_b = num2.size();
        int max_len = std::max(len_a, len_b);


        for (int i = 0; i < max_len; ++i) {
            int val_a = (i < len_a) ? hexCharToInt(num1[len_a - 1 - i]) : 0;
            int val_b = (i < len_b) ? hexCharToInt(num2[len_b - 1 - i]) : 0;
            int diff = val_a - val_b - borrow;
            if (diff < 0) {
                diff += 16;
                borrow = 1;
            } else {
                borrow = 0;
            }


            result.insert(result.begin(), intToHexChar(diff));
        }
        if (borrow == 1) {
            result.insert(result.begin(), '-');
        }


        // Удаляем ведущие нули из результата
        result.erase(0, result.find_first_not_of('0'));


        return result.empty() ? "0" : result;
    }


    std::string multiplyHex(const std::string &a, const std::string &b) const {
        if (a == "0" || b == "0") {
            return "0";
        }
        std::string result = "0";
        // Проходимся по каждой цифре числа b
        for (int i = b.size() - 1; i >= 0; --i) {
            std::string partialResult;
            int carry = 0;
            for (int j = 0; j < (b.size() - 1 - i); ++j) {
                partialResult += "0";
            }


            int digit_b = hexCharToInt(b[i]);
            for (int j = a.size() - 1; j >= 0; --j) {
                int digit_a = hexCharToInt(a[j]);
                int product = digit_a * digit_b + carry;
                partialResult.insert(partialResult.begin(), intToHexChar(product % 16));
                carry = product / 16;
            }
            if (carry > 0) {
                partialResult.insert(partialResult.begin(), intToHexChar(carry));
            }
            result = addHex(result, partialResult);
        }


        return result;
    }
};

class longHexMatrix : public hexMatrix
{
public:
    longHexMatrix() : hexMatrix() {}


    void readNumber() override
    {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << "Enter a hexadecimal number: ";
                std::cin >> matrix[i][j];


                while (!isValidHex(matrix[i][j])) {
                    std::cout
                            << "Wrong! Enter a hexadecimal number: ";
                    std::cin >> matrix[i][j];
                }
            }
        }
    }
};


int main(int argc, const char *argv[]) {
    setlocale(LC_ALL, "Russian");
//    // Лабораторная работа №1
//    valInput("Можно вводить только 1 и 0.");
//    std::string name;
//    name = valOnlyChar("ENTER SNAIL NAME\n>>>\t");
//    Food eda;
//    Bedding lezhanka;
//    Bowl kashka;
//    Snail chertopoloh(name);
//    chertopoloh.PrintSnailInfo();
//    // Лабораторная работа №2
//     Ввод и вывод двух этих несчастных матриц
//    BigNumber bigNumber1;
//    std::cout << "Enter Matrix:" << std::endl;
//    bigNumber1.readMatrix();
//    std::cout << "Matrix:" << std::endl;
//    bigNumber1.displayNumber();
    //Лабораторная работа №2
    hexMatrix mat1, mat2;
    mat1.readNumber();
    mat2.readNumber();
    mat1.printMatrix();
    mat2.printMatrix();
    // Лабораторная работа №3
    hexMatrix sum = mat1 + mat2;
    hexMatrix diff = mat1 - mat2;
    hexMatrix product = mat1 * mat2;
    std::cout << "Sum:\n";
    sum.printMatrix();
    std::cout << "Difference:\n";
    diff.printMatrix();
    std::cout << "Product:\n";
    product.printMatrix();
    return 0;
}
