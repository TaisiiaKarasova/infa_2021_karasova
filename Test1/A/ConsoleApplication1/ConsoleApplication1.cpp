#include <iostream>

int main()
{
    int a;

    std::cin >> a;
    
    std::cout << a / 100 + (a % 100) / 10 + (a % 100) % 10 << '\n';
}

