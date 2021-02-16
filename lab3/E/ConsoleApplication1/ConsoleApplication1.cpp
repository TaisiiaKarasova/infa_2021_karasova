#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int do_some_awesome_work(int* a, int* b)
{
    return (*a + *b);
}

int main()
{
    int c, d;
    cin >> c >> d;
    cout << do_some_awesome_work(&c, &d) << endl;
    return 0;
}


