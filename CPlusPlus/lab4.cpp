#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>


class HexMatrix {
protected:
    std::string matrix11;
    std::string matrix12;
    std::string matrix21;
    std::string matrix22;


public:
    HexMatrix() : matrix11("0"), matrix12("0"), matrix21("0"), matrix22("0") {}

    HexMatrix(const std::string &a, const std::string &b,
              const std::string &c, const std::string &d) {
        matrix11 = a;
        matrix12 = b;
        matrix21 = c;
        matrix22 = d;
    }


    void printMatrix() const {
        std::cout << ">>> 2x2 hexadecimal matrix:" << std::endl;
        std::cout << matrix11 << " " << matrix12 << std::endl;
        std::cout << matrix21 << " " << matrix22 << std::endl;
    }


    void readMatrix() {
        std::cout
                << ">>> [1][1]: Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
        std::cin >> matrix11;
        while (!isValidHex(matrix11)) {
            std::cout
                    << ">>> [1][1]: Wrong format. Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
            std::cin >> matrix11;
        }
        std::cout
                << ">>> [1][2]: Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
        std::cin >> matrix12;
        while (!isValidHex(matrix12)) {
            std::cout
                    << ">>> [1][2]: Wrong format. Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
            std::cin >> matrix12;
        }
        std::cout
                << ">>> [2][1]: Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
        std::cin >> matrix21;
        while (!isValidHex(matrix21)) {
            std::cout
                    << ">>> [2][1]: Wrong format. Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
            std::cin >> matrix21;
        }
        std::cout
                << ">>> [2][2]: Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
        std::cin >> matrix22;
        while (!isValidHex(matrix22)) {
            std::cout
                    << ">>> [2][2]: Wrong format. Enter the valid number in hexadecimal format (arbitrary length) (case is not taken into account): ";
            std::cin >> matrix22;
        }
    }


    HexMatrix &operator=(const HexMatrix &other) {
        if (this != &other) {
            matrix11 = other.matrix11;
            matrix12 = other.matrix12;
            matrix21 = other.matrix21;
            matrix22 = other.matrix22;
        }
        return *this;
    }


    HexMatrix operator+(const HexMatrix &other) const {
        return HexMatrix(addHex(matrix11, other.matrix11), addHex(matrix12, other.matrix12),
                         addHex(matrix21, other.matrix21), addHex(matrix22, other.matrix22));
    }


    HexMatrix operator-(const HexMatrix &other) const {
        return HexMatrix(subtractHex(matrix11, other.matrix11), subtractHex(matrix12, other.matrix12),
                         subtractHex(matrix21, other.matrix21), subtractHex(matrix22, other.matrix22));
    }


    HexMatrix operator*(const HexMatrix &other) const {
        std::string res111 = multiplyHex(matrix11, other.matrix11);
        std::string res112 = multiplyHex(matrix12, other.matrix21);
        std::string result11 = addHex(res111, res112);

        std::string res121 = multiplyHex(matrix11, other.matrix12);
        std::string res122 = multiplyHex(matrix12, other.matrix22);
        std::string result12 = addHex(res121, res122);

        std::string res211 = multiplyHex(matrix21, other.matrix11);
        std::string res212 = multiplyHex(matrix22, other.matrix12);
        std::string result21 = addHex(res211, res212);

        std::string res221 = multiplyHex(matrix21, other.matrix12);
        std::string res222 = multiplyHex(matrix22, other.matrix22);
        std::string result22 = addHex(res221, res222);


        return HexMatrix(result11, result12, result21, result22);
    }


//    HexMatrix operator/(const HexMatrix &other) const {
//        // Проверяем определители
//        if (isValidDet(other.matrix11, other.matrix12, other.matrix21, other.matrix22)) {
//            // Находим алгебраические дополнения
//            std::string a11 = matrix22;
//            std::string a12 = matrix21;
//            std::string a21 = matrix12;
//            std::string a22 = matrix11;
//
//
//
//            // Вычисляем часть результата - действительную часть числа
//            std::string quotientReal = divideHex(numerator.realPart, denominator);
//            std::string remainderReal = moduloHex(numerator.realPart, denominator);
//
//
//            // Вычисляем часть результата - мнимую часть числа
//            std::string quotientImaginary = divideHex(numerator.imaginaryPart, denominator);
//            std::string remainderImaginary = moduloHex(numerator.imaginaryPart, denominator);
//        }
//        else {
//            std::cout << "Division is impossible." << std::endl;
//        }
//    }


protected:
    bool isValidHex(const std::string &str) const {
        return !str.empty() &&
               std::all_of(str.begin(), str.end(), [](char c) { return std::isxdigit(static_cast<unsigned char>(c)); });
    }


    bool isValidDet(const std::string &a, const std::string &b, const std::string &c, const std::string &d) const {
        std::string det = subtractHex(multiplyHex(a, d), multiplyHex(b, c));
        return !(det == "0");
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


int main() {
    HexMatrix matrix1, matrix2;
    matrix1.readMatrix();
    matrix2.readMatrix();
    HexMatrix sum = matrix1 + matrix2;
    HexMatrix diff = matrix1 - matrix2;
    HexMatrix product = matrix1 * matrix2;
    // HexComplexNumber quotient = num1 / num2;
    std::cout << "Sum: ";
    sum.printMatrix();
    std::cout << "Difference: ";
    diff.printMatrix();
    std::cout << "Product: ";
    product.printMatrix();
    // std::cout << "Частное: "; quotient.printNumber();
    return 0;
}
