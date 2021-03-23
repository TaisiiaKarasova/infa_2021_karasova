#include <iostream>
#include <chrono>
#include <vector>
#include <list>

int main()
{
    long long int min_time = LLONG_MAX;
    std::vector<int> cycle_time;

    std::vector<int> creation_fill_vector;
    std::vector<int> add_end_vector;
    std::vector<int> add_begin_vector;
    std::vector<int> add_middle_vector;
    std::vector<int> call_element_vector;

    std::vector<int> creation_fill_list;
    std::vector<int> add_end_list;
    std::vector<int> add_begin_list;
    std::vector<int> add_middle_list;
    std::vector<int> call_element_list;

    /* finding the time it takes to organize the cycle */
    for (int j = 1; j <= 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= j * 10000; i++);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time) 
                min_time = time.count();
        }
        cycle_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    /* finding the time it takes to create and fill the structure */
    for (int j = 1; j <= 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<int> vec;
            vec.reserve(j * 10000);
            for (int i = 1; i <= j * 10000; i++)
            {
                vec.push_back(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        creation_fill_vector.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;

        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::list<int> lis;
            lis.resize(j * 10000);
            for (int i = 1; i <= j * 10000; i++)
            {
                lis.push_back(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        creation_fill_list.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;
    }

    std::cout << "create and fill the structure" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 10000 << ' ';
    std::cout << '\n';
    std::cout << "vector" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << creation_fill_vector[j - 1] << ' ';
    std::cout << '\n';
    std::cout << "list" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << creation_fill_list[j - 1] << ' ';
    std::cout << '\n';

    std::cout << '\n';

    /* finding the time it takes to add an element to the end lots of times */
    for (int j = 1; j <= 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            std::vector<int> vec;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= j * 10000; i++)
            {
                vec.push_back(0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        add_end_vector.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;

        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::list<int> lis;
            for (int i = 1; i <= j * 10000; i++)
            {
                lis.push_back(0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        add_end_list.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;
    }

    std::cout << "add an element to the end lots of times" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 10000 << ' ';
    std::cout << '\n';
    std::cout << "vector" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << add_end_vector[j - 1] << ' ';
    std::cout << '\n';
    std::cout << "list" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << add_end_list[j - 1] << ' ';
    std::cout << '\n';

    std::cout << '\n';

    /* finding the time it takes to refer to an element by its number lots of times */
    std::vector<int> vec(100001, 0);
    std::list<int> lis(100001, 0);
    int temp_calling;
    for (int j = 1; j <= 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            temp_calling = vec[j * 10000];
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        call_element_vector.push_back(min_time);
        min_time = LLONG_MAX;

        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            auto it = lis.begin();
            std::advance(it, j*10000);
            temp_calling = *it;
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        call_element_list.push_back(min_time);
        min_time = LLONG_MAX;
    }

    std::cout << "refer to an element by its number lots of times" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 10000 << ' ';
    std::cout << '\n';
    std::cout << "vector" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << call_element_vector[j - 1] << ' ';
    std::cout << '\n';
    std::cout << "list" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << call_element_list[j - 1] << ' ';
    std::cout << '\n';

    std::cout << '\n';

    /* finding the time it takes to add an element to the beginning lots of times */
    for (int j = 1; j <= 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            std::vector<int> vec;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= j * 10000; i++)
            {
                vec.insert(vec.begin(), 0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        add_begin_vector.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;

        for (int n = 1; n <= 5; n++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::list<int> lis;
            for (int i = 1; i <= j * 10000; i++)
            {
                lis.push_front(0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        add_begin_list.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;
    }

    std::cout << "add an element to the beginning lots of times" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 10000 << ' ';
    std::cout << '\n';
    std::cout << "vector" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << add_begin_vector[j - 1] << ' ';
    std::cout << '\n';
    std::cout << "list" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << add_begin_list[j - 1] << ' ';
    std::cout << '\n';

    std::cout << '\n';


    /* finding the time it takes to add an element to the middle lots of times */
    for (int j = 1; j <= 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            std::vector<int> vec;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= j * 10000; i++)
            {
                vec.insert(vec.begin() + vec.size() / 2, 0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        add_middle_vector.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;

        for (int n = 1; n <= 5; n++)
        {
            std::list<int> lis;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= j * 10000; i++)
            {
                auto it = lis.begin();
                int half_size = lis.size() / 2;
                std::advance(it, half_size);
                lis.insert(it, 0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() > 0 && time.count() < min_time)
                min_time = time.count();
            if (time.count() <= 0 && (INT_MAX - time.count()) < min_time)
                min_time = INT_MAX - time.count();
        }
        add_middle_list.push_back(min_time - cycle_time[j - 1]);
        min_time = LLONG_MAX;
    }

    std::cout << "add an element to the middle lots of times" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 10000 << ' ';
    std::cout << '\n';
    std::cout << "vector" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << add_middle_vector[j - 1] << ' ';
    std::cout << '\n';
    std::cout << "list" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << add_middle_list[j - 1] << ' ';
    std::cout << '\n';

    std::cout << '\n';

    

    return 0;
      
}

