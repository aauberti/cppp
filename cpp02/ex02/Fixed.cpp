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

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long temp = (long long)this->getRawBits() * other.getRawBits();
    result.setRawBits((int)(temp >> fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other.getRawBits() == 0) {
        std::cerr << "Error, Div with 0" << std::endl;
        return result;
    }
    long long temp = (long long)this->getRawBits() << fractionalBits;
    result.setRawBits((int)(temp / other.getRawBits()));
    return result;
}

Fixed& Fixed::operator++() {
    this->value += 1;
    return *this;
}

Fixed& Fixed::operator--() {
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old(*this);
    ++(*this);
    return old;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    --(*this);
    return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return a;
    }
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return a;
    }
    return b;
}