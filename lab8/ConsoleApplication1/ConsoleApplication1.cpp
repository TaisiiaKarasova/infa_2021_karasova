#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <cmath>
#include <algorithm>

//Пузырёк
void bubble(int* m, int n)
{
    bool sorti = false;
    int counti = 0;
    while (!sorti)
    {
        sorti = true;
        for (int i = 0; i < n - 1; i++)
            if (m[i] > m[i + 1])
            {
                std::swap(m[i], m[i + 1]);
                sorti = false;
                counti++;
            }

    }
}

//Выбором
void selection(int* m, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int maxx = 0;
        for (int j = 1; j <= i; j++)
            if (m[j] > m[maxx]) maxx = j;
        std::swap(m[i], m[maxx]);
    }
}

//Вставками
void insertion(int* m, int n)
{
    for (int i = 1; i < n; i++)
    {
        int etalon = m[i], j = i - 1;
        while (j >= 0 && m[j] > etalon)
        {
            m[j + 1] = m[j];
            j--;
        }
        m[j + 1] = etalon;
    }
}

//Пирамидальная
void restoreheap(int* m, int father, int last)
{
    while (father <= last / 2)
    {

        int maxson;
        if (2 * father == last) maxson = last;
        else if (m[2 * father + 1] > m[2 * father])
            maxson = 2 * father + 1;
        else maxson = 2 * father;
        if (m[father] < m[maxson])
        {

            std::swap(m[father], m[maxson]);
            father = maxson;

        }
        else father = last;
    }
}

void heapsort(int* m, int N)
{
    for (int i = N / 2; i >= 1; i--)
    {
        restoreheap(m, i, N);
    }
    for (int i = N; i > 1; i--)
    {
        std::swap(m[1], m[i]);
        restoreheap(m, 1, i - 1);
    }
}

//Слиянием
void mergesort(int* m, int st, int fin)
{
    int* c = new int[fin - st + 1];
    int mid = (st + fin) / 2;
    if (st < mid) mergesort(m, st, mid);
    if (mid + 1 < fin) mergesort(m, mid + 1, fin);
    int i = st;
    int j = mid + 1;
    int p = 0;
    while (i <= mid && j <= fin)
    {
        if (m[i] <= m[j])
        {
            c[p] = m[i];
            p++;
            i++;
        }
        else
        {
            c[p] = m[j];
            p++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[p] = m[i];
        p++;
        i++;
    }
    while (j <= fin)
    {
        c[p] = m[j];
        p++;
        j++;
    }
    for (int i = st; i <= fin; i++)
    {
        m[i] = c[i - st];
    }
}

struct massiv
{
    int size;
    int* a;
};

std::vector <massiv> tests;

int main()
{
    long long int min_time = LLONG_MAX;

    std::vector<long long> bubble_time;
    std::vector<long long> selection_time;
    std::vector<long long> insertion_time;
    std::vector<long long> heapsort_time;
    std::vector<long long> mergesort_time;
 
    std::mt19937 engine(23); 
    std::uniform_int_distribution<int> int_dist(0, 1000);

    //Bubble
    //generation
    for (int j = 1; j <= 10; j++)
    {
        massiv m;
        m.size = 1000 * j;
        int* s = new int[10001];
        m.a = s;
        for (int i = 0; i < m.size; i++)
           m.a[i] = int_dist(engine);
        tests.push_back(m);
    }
    
    //counting time
    for (int j = 0; j < 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < tests[j].size; i++)
                    tests[j].a[i] = int_dist(engine);
            }
            auto start = std::chrono::high_resolution_clock::now();
            bubble(tests[j].a, tests[j].size - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        bubble_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    //time print
    std::cout << "Bubble" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 1000 << ' ';
    std::cout << '\n';
    std::cout << "time" << ' ';
    for (long long j : bubble_time)
        std::cout << j << ' ';
    std::cout << '\n';
    std::cout << '\n';


    //Insertion
    
    //counting time
    for (int j = 0; j < 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < tests[j].size; i++)
                    tests[j].a[i] = int_dist(engine);
            }
            auto start = std::chrono::high_resolution_clock::now();
            insertion(tests[j].a, tests[j].size - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        insertion_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    //time print
    std::cout << "Insertion" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 1000 << ' ';
    std::cout << '\n';
    std::cout << "time" << ' ';
    for (long long j : insertion_time)
        std::cout << j << ' ';
    std::cout << '\n';
    std::cout << '\n';


    //Selection
    //generation
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < tests[j].size; i++)
            tests[j].a[i] = int_dist(engine);
    }

    for (int j = 0; j < 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < tests[j].size; i++)
                    tests[j].a[i] = int_dist(engine);
            }

            auto start = std::chrono::high_resolution_clock::now();
            selection(tests[j].a, tests[j].size - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        selection_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    //time print
    std::cout << "Selection" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 1000 << ' ';
    std::cout << '\n';
    std::cout << "time" << ' ';
    for (long long j : selection_time)
        std::cout << j << ' ';
    std::cout << '\n';
    std::cout << '\n';

    //Pyramide

   

    //counting time
    for (int j = 0; j < 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < tests[j].size; i++)
                    tests[j].a[i] = int_dist(engine);
            }
            auto start = std::chrono::high_resolution_clock::now();
            heapsort(tests[j].a, tests[j].size - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        heapsort_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    //time print
    std::cout << "Pyramide" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 1000 << ' ';
    std::cout << '\n';
    std::cout << "time" << ' ';
    for (long long j : heapsort_time)
        std::cout << j << ' ';
    std::cout << '\n';
    std::cout << '\n';

    //Merge


    //counting time
    for (int j = 0; j < 10; j++)
    {
        for (int n = 1; n <= 5; n++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < tests[j].size; i++)
                    tests[j].a[i] = int_dist(engine);
            }
            auto start = std::chrono::high_resolution_clock::now();
            mergesort(tests[j].a, 0, tests[j].size - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            if (time.count() < min_time)
                min_time = time.count();
        }
        mergesort_time.push_back(min_time);
        min_time = LLONG_MAX;
    }

    //time print
    std::cout << "Merge" << '\n';
    std::cout << "data size" << ' ';
    for (int j = 1; j <= 10; j++)
        std::cout << j * 1000 << ' ';
    std::cout << '\n';
    std::cout << "time" << ' ';
    for (long long j : mergesort_time)
        std::cout << j << ' ';
    std::cout << '\n';
    std::cout << '\n';

    return 0;

}


