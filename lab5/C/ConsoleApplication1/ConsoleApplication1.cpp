#include<iostream>
#include <cmath>
using namespace std;

struct Node {
    string value;
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

    void push_back(string value)
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
        size++;
    }


    void push_left(string value)
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

    void add_to_the_middle(string value)
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

        if (size == 1) push_back(value);
        else
        {
            int middle_place = size % 2 == 0 ? (size / 2) : (size / 2 + 1);

            Node* temporary_node = head;
            for (int j = 1; j <= middle_place - 1; j++)
            {
                temporary_node = temporary_node->next;
            }
            Node* new_middle = new Node;
            new_middle->value = value;
            new_middle->next = temporary_node->next;
            temporary_node->next = new_middle;
            size++;
        }
        

    }

    string pop_head()
    {
        if (head == NULL)
        {
            return "error";
        }
        string value_head = head->value;
        Node* old_head = head;
        head = head->next;
        delete old_head;
        size--;

        return value_head;
    }

};

int main()
{
    int n;
    char operand;
    string number;

    List* list = new List;

    cin >> n;
    
    int i = 1;
    while (i <= n)
    {
        cin >> operand;
        if (operand == '-')
        {
            cout << list->pop_head() << '\n';
        }
        else
        {
            cin >> number;
            if (operand == '+') list->push_back(number);
            if (operand == '*') list->add_to_the_middle(number);
        }
        i++;
    }    
}