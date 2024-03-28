#include <iostream>
#include <string>
#include <cmath>

// Hexadecimal Matrix class
class HexMatrix {
private:
    std::string matrix[2][2];

public:
    HexMatrix() {}

    HexMatrix(const std::string& a, const std::string& b,
              const std::string& c, const std::string& d) {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    // Getters and setters
    std::string get(int row, int col) const {
        return matrix[row][col];
    }

    void set(int row, int col, const std::string& value) {
        matrix[row][col] = value;
    }
};

// Function to convert a hexadecimal string to its decimal equivalent string
std::string hexToDecimal(const std::string& hexString) {
    int decimalValue = 0;
    int hexStringLength = hexString.length();

    // Start from the least significant digit (rightmost) and move towards the most significant digit
    for (int i = hexStringLength - 1; i >= 0; --i) {
        int digitValue = 0;
        if (hexString[i] >= '0' && hexString[i] <= '9') {
            digitValue = hexString[i] - '0';
        } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            digitValue = hexString[i] - 'A' + 10;
        } else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
            digitValue = hexString[i] - 'a' + 10;
        }
        decimalValue += digitValue * pow(16, hexStringLength - 1 - i);
    }

    return std::to_string(decimalValue);
}

// Function to calculate cotangent
double cotangent(double angle) {
    return 1.0 / tan(angle);
}

// Function to read a hexadecimal matrix from the console
HexMatrix readMatrixFromConsole() {
    std::string a, b, c, d;
    std::cout << "Enter the elements of the 2x2 matrix in hexadecimal form:" << std::endl;
    std::cout << "a: "; std::cin >> a;
    std::cout << "b: "; std::cin >> b;
    std::cout << "c: "; std::cin >> c;
    std::cout << "d: "; std::cin >> d;
    return HexMatrix(a, b, c, d);
}

// Function to print the elements of a matrix
void printMatrix(const HexMatrix& matrix) {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

// Function to process the matrix
void processMatrix(const HexMatrix& matrix) {
    HexMatrix cotMatrix;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::string decimalValue = hexToDecimal(matrix.get(i, j));
            double cotValue = cotangent(std::stod(decimalValue));
            cotMatrix.set(i, j, std::to_string(cotValue));
        }
    }

    // Output cotangent matrix
    std::cout << "Cotangent Matrix:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << cotMatrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    HexMatrix hexMatrix = readMatrixFromConsole();
    printMatrix(hexMatrix);
    processMatrix(hexMatrix);
    return 0;
}
