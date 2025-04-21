#include "Span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}
Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}
Span::~Span() {}


Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full, cannot add more numbers");
    }
    _numbers.push_back(num);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::logic_error("Need at least 2 numbers to find a span");
    }

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::logic_error("Need at least 2 numbers to find a span");
    }

    std::vector<int>::const_iterator minElement = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxElement = std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(*maxElement - *minElement);
}

unsigned int Span::size() const {
    return _numbers.size();
}

unsigned int Span::maxSize() const {
    return _maxSize;
}
