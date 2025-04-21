#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Span {
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void addNumber(int num);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template<typename Iterator>
    void addRange(Iterator begin, Iterator end);

    unsigned int size() const;
    unsigned int maxSize() const;
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) > static_cast<long>(_maxSize - _numbers.size())) {
        throw std::out_of_range("Not enough space to add all elements from range");
    }
    
    _numbers.insert(_numbers.end(), begin, end);
}

#endif