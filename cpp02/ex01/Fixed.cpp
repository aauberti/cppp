#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const raw) {
    value = raw << fractionalBits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const raw) {
    value = roundf(raw * (1 << fractionalBits));
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) { 
        value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n"; 
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
