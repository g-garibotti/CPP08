#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "--- Basic Test ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    std::cout << "\n--- Testing addRange ---" << std::endl;
    Span sp2 = Span(10);
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i * 10);
        
    sp2.addRange(v.begin(), v.end());
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    std::cout << "\n--- Testing exception ---" << std::endl;
    try {
        Span sp3 = Span(1);
        sp3.addNumber(42);
        sp3.addNumber(21);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}