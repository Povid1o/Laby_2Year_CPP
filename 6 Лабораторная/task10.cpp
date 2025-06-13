#include <iostream>

class Matrix {
private:
    double data[2][2];
public:
    Matrix() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0;
    }
    Matrix(double a, double b, double c, double d) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }
    Matrix operator+(const Matrix& other) const {
        return Matrix(
            data[0][0] + other.data[0][0], data[0][1] + other.data[0][1],
            data[1][0] + other.data[1][0], data[1][1] + other.data[1][1]
        );
    }

    Matrix operator*(const Matrix& other) const {
        return Matrix(
            data[0][0]*other.data[0][0] + data[0][1]*other.data[1][0],
            data[0][0]*other.data[0][1] + data[0][1]*other.data[1][1],
            data[1][0]*other.data[0][0] + data[1][1]*other.data[1][0],
            data[1][0]*other.data[0][1] + data[1][1]*other.data[1][1]
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        os << "[" << m.data[0][0] << ", " << m.data[0][1] << "]\n"
           << "[" << m.data[1][0] << ", " << m.data[1][1] << "]";
        return os;
    }

    double& operator()(int row, int col) {
        return data[row][col];
    }
    const double& operator()(int row, int col) const {
        return data[row][col];
    }
};

int main() {
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);
    Matrix sum = m1 + m2;
    Matrix prod = m1 * m2;
    std::cout << "m1:\n" << m1 << std::endl;
    std::cout << "m2:\n" << m2 << std::endl;
    std::cout << "Сумма:\n" << sum << std::endl;
    std::cout << "Произведение:\n" << prod << std::endl;
    std::cout << "Элемент (1,0) в m1: " << m1(1,0) << std::endl;
    m1(1,0) = 42;
    std::cout << "m1 после изменения:\n" << m1 << std::endl;
    return 0;
}
