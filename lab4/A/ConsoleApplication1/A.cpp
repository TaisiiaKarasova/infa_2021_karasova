#include <iostream>


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
        head = head -> next;
        delete old_head;
        size--;

        return value_head;
    }

};


int main()
{
    int n;
    List* list = new List;

    std::cin >> n;
    while (n != 0)
    {
        if (n > 0)
        {
            list->push_left(n);
        }
        else if (list->size > 0)
        {
            int top = list->pop_head();
            if (abs(n) < top)
            {
                list->push_left(n + top);
            }

        }
        std::cin >> n;
    }

    int final_size = list->size;
    int final_top;
    if (final_size > 0) final_top = list->head->value;
    else final_top = -1;
    std::cout << final_size << ' ' << final_top << '\n';
    list->clear();
    delete list;

}
