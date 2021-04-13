#include <iostream>
#include <chrono>
#include <vector>
#include <random>

unsigned hash(unsigned x, unsigned key, unsigned size)
{
    unsigned int y = x * key;
    return y % size;
}

struct Node
{
    unsigned x = 0;
    unsigned value = UINT_MAX;
    bool alive = false;
};

struct HashMap
{
    unsigned size;
    unsigned n_elements = 0;
    Node* table;
    unsigned key1 = 0;
    unsigned key2 = 0;

    HashMap(unsigned n)
    {
        size = n;
        key1 = size - 1;
        key2 = size + 1;
        n_elements = 0;
        table = new Node[size];
        for (int i = 0; i < size; i++)
        {
            table[i].x = 0;
            table[i].value = 0;
            table[i].alive = false;
        }
    }


    void add(unsigned x, unsigned value)
    {
        unsigned h = hash(x, key1, size);
        unsigned i = 1;
        //выходим из цикла, если пришли к пустой ячейке
        while (table[h].value != UINT_MAX && table[h].x != 0)
        {
            h = (hash(x, key1, size) + i * hash(x, key2, size)) % size;
            i++;
        }
        Node new_element;
        new_element.x = x;
        new_element.value = value;
        new_element.alive = true;
        table[h] = new_element;
        n_elements += 1;

        if (n_elements * 2 >= size)
        {
            Node* temporary_table = new Node [2 * size];
            unsigned new_size = size * 2;
            for (unsigned i = 0; i < size; i++)
            {
                //копируем table[i]
                unsigned h = hash(table[i].x, key1, size);
                for (unsigned j = 1; (table[h].value != UINT_MAX && table[h].x != 0); j++)
                {
                    h = (hash(table[i].x, key1, new_size) + i * hash(table[i].x, key2, new_size)) % new_size;
                }

                Node new_element;
                new_element.x = table[i].x;
                new_element.value = table[i].value;
                new_element.alive = true;
                temporary_table[h] = new_element;
            }
            size = new_size;
            table = temporary_table;
            delete[] temporary_table;
        }
    }

    unsigned get(unsigned x)
    {
        unsigned h = hash(x, key1, size);
        //выходим из цикла, если пришли к живому элементу с подходящим ключом или к незаполненной ячейке
        for (unsigned i = 1; -((table[h].x = x && table[h].alive == true) || (table[h].value == UINT_MAX && table[h].x==0)); i++)
        {
            h = (hash(x, key1, size) + i * hash(x, key2, size)) % size;
        }
        return table[h].value;
    }

    unsigned pop(unsigned x)
    {
        unsigned h = hash(x, key1, size);
        //выходим из цикла, если пришли к живому элементу с подходящим ключом или к незаполненной ячейке
        for (unsigned i = 1; !((table[h].x = x && table[h].alive == true) || (table[h].value == UINT_MAX && table[h].x == 0)); i++)
        {
            h = (hash(x, key1, size) + i * hash(x, key2, size)) % size;
        }

        table[h].alive = false;
        return table[h].value;
    }

};

int main()
{
    long long min_time = LLONG_MAX;

    std::vector<long long> get_time;

    unsigned keys[100];
    unsigned values[100];

    std::mt19937 engine(23);
    std::uniform_int_distribution<int> int_dist(0, 1000);

    


    for (unsigned k = 1; k <= 20; k++)
    {
        //генерируем ключи и значения
        for (int t = 0; t < 100; t++)
        {
            keys[t] = int_dist(engine);
            values[t] = int_dist(engine);
        }

        //добавляем значения по соответствующим ключам
        HashMap Map(k * 1000);
        for (int p = 0; p < 100; p++)
        {
            Map.add(keys[p], values[p]);
        }

        for (int u = 1; u <= 5; u++)
        {
            //достаём значения
            auto start = std::chrono::high_resolution_clock::now();
            for (int p = 0; p < 100; p++)
            {
                unsigned N = Map.get(keys[p]);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        get_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    std::cout << "data size" << ' ';
    for (int k = 1; k <= 20; k++)
    {
        std::cout << k * 1000 << ' ';
    }
    std::cout << '\n';

    std::cout << "time" << ' ';
    for (long long k : get_time)
        std::cout << k << ' ';

    return 0;
}
