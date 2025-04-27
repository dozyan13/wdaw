#include <iostream>
#include <numeric> 
using namespace std;

class Fraction {
private:
    int n;   // Чисельник
    int d;

    void simple() {
        int gcd = (n, d);
        n /= gcd;
        d /= gcd;
        if (d < 0) { // Нормалізація знака
            n = -n;
            d = -d;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            throw std::invalid_argument("Неиожна щоб число було нулем.");
        }
        n = num;
        d = denom;
        simple();
    }

    void setValues(int num, int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Неиожна щоб число було нулем.");
        }
        n = num;
        d = denom;
        simple();
    }

    Fraction add(const Fraction& other) const {
        int num = n * other.d + other.n * d;
        int denom = d * other.d;
        return Fraction(num, denom);
    }

    Fraction subtract(const Fraction& other) const {
        int num = n * other.d - other.n * d;
        int denom = d * other.d;
        return Fraction(num, denom);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(n * other.n, d * other.d);
    }

    Fraction divide(const Fraction& other) const {
        return Fraction(n * other.d, d * other.n);
    }

    void display() const {
        cout << n << "/" << d << std::endl;
    }
};

// Приклад використання
int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    cout << "Додавання: "; f1.add(f2).display();
    cout << "Віднімання: "; f1.subtract(f2).display();
    cout << "Множення: "; f1.multiply(f2).display();
    cout << "Ділення: "; f1.divide(f2).display();

    return 0;
}