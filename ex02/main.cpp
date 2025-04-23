#include <iostream>
#include <list>
#include "MutantStack.hpp"

int subject_test_list()
{
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> s(lst);
    
    return 0;
}

void subject_test_mutant()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
}

void my_test() {
    std::cout << "===== MY TEST =====" << std::endl;
    
    MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);
    
    std::cout << "Top: " << ms.top() << std::endl;
    std::cout << "Size: " << ms.size() << std::endl;
    
    std::cout << "Elements: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        *it += 5;
    }
    
    std::cout << "Modified elements: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "New top: " << ms.top() << std::endl;
    ms.pop();
    std::cout << "Top after pop: " << ms.top() << std::endl;
    std::cout << "Size after pop: " << ms.size() << std::endl;
    std::cout << std::endl;
}

int main()
{
    subject_test_list();
    subject_test_mutant();
    my_test();
    return 0;
}