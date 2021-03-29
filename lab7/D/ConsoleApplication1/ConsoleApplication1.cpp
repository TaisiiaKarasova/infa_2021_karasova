#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;


struct resident
{
    string name;
    bool knight_liar;
    resident* next = NULL;
    resident* prev = NULL;
};

struct List
{
    resident* head = NULL;
    resident* tail = NULL;
    unsigned int size = 0;

    void print()
    {
        resident* res = head;
        std::cout << res->name << ' ' << res->knight_liar << '\n';
        res = res->next;
        while (res != head) 
        {
            std::cout << res->name << ' ' << res->knight_liar<< '\n';
            res = res->next;
        }
    }

    void push_back(string name, bool knight_liar)
    {
        if (head == NULL)
        {
            head = new resident;
            head->name = name;
            head->knight_liar = knight_liar;
            head->next = head;
            head->prev = head;
            tail = head;
            size = 1;
            return;
        }

        resident* new_resident = new resident;
        tail->next = new_resident;
        new_resident->name = name;
        new_resident->knight_liar = knight_liar;
        new_resident->next = head;
        new_resident->prev = tail;
        head->prev = new_resident;
        tail = new_resident;
        ++size;
    }


    void delete_element(resident* res)
    {
        if (res == head) head = res->next;
        if (res == tail) tail = res->prev;
        (res->prev)->next = res->next;
        (res->next)->prev = res->prev;
        size--;
    }
};

int main()
{
    int population, days;
    bool news;

    List* residents = new List;

    cin >> population >> news;
    string r_name;
    bool r_knight_liar;

    for (long long i = 0; i < population; i++)
    {
        cin >> r_name >> r_knight_liar;
        residents->push_back(r_name, r_knight_liar);
    }
    cin >> days;

    long long i = 1;
    resident* telling_resident = residents->head;

    while (i <= days)
    {
        if (population > 1)
        {
            if (telling_resident->knight_liar == 0)
                news = !news;
            if ((news == 1) && (telling_resident->knight_liar == 0))
                telling_resident->knight_liar = 1;
            if ((news == 0) && (telling_resident->knight_liar == 1))
            {
                residents->delete_element(telling_resident);
                population--;
            }
            telling_resident = telling_resident->next;
        }
        i++;
    }
    residents->print();
    return 0;
}

