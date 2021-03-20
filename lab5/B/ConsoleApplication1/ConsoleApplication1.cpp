#include<iostream>
#include <cmath>
using namespace std;

struct Node {
    int value;
    Node* next = NULL;
    Node* prev = NULL;
};

struct List
{
    Node* head = NULL;
    Node* tail = NULL;
    unsigned int size = 0;

    void print()
    {
        Node* p_node = head;
        while (p_node != NULL) {
            std::cout << p_node->value << ' ';
            p_node = p_node->next;
        }
        std::cout << '\n';
    }

    void clear()
    {
        while (head != NULL) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        size = 0;
    }

    void push_back(int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->value = value;
            tail = head;
            size = 1;
            return;
        }

        Node* new_node = new Node;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->value = value;
        tail = new_node;
        ++size;
    }


    void push_left(int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->value = value;
            head->prev = NULL;
            size = 1;
            tail = head;
            return;
        }

        Node* new_left = new Node;
        new_left->value = value;
        new_left->next = head;
        head = new_left;
        size++;
    }

    int pop_head()
    {
        if (head == NULL)
        {
            return -1;
        }
        int value_head = head->value;
        Node* old_head = head;
        head = head->next;
        delete old_head;
        size--;

        return value_head;
    }

};

string operator_or_number (string s)
{
    if (s.length() != 1) return "number";
    else if (s[0] == '+' || s[0] == '*' || s[0] == '/' || s[0] == '-') return "operator";
    else return "number";

}

int StrToInt(string s)
{
    int l, M;
    l = s.length();
    M = 0;
    if (s[0] == '-')
    {
        for (int i = 1; i < l; i++)
        {
            M += (s[i] - '0') * pow(10, l - i - 1);
        }
        return -M;
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            M += (s[i] - '0') * pow(10, l - i - 1);
        }
        return M;
    }
}

int main()
{

    List* list = new List;
    string Polish_sign;

    
    
   while (cin >> Polish_sign)
    {
        if (operator_or_number(Polish_sign) == "operator")
        {
            int last_number = list->pop_head();
            int pre_last_number = list->pop_head();
            if (Polish_sign == "+") list->push_left(pre_last_number + last_number);
            if (Polish_sign == "*") list->push_left(pre_last_number * last_number);
            if (Polish_sign == "/") list->push_left(pre_last_number / last_number);
            if (Polish_sign == "-") list->push_left(pre_last_number - last_number);
        }
        else list->push_left(StrToInt(Polish_sign));
    } 

    cout << list->head->value <<'\n';

    list->clear();
    delete list;

    return 0;
}
