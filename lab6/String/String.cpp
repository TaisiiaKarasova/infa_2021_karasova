#include <iostream>
#include <cstddef>
using std::size_t;
using std::cout;


struct string 
{
    char* str;
    size_t size;
    size_t capacity = size * 2;

    string () 
    {
        str = NULL;
        size = 0;
        capacity = size * 2;
    }

    string(size_t cnt, char c)
    {
        str = new char[cnt];
        size = cnt;
        capacity = 2 * size;
        for (unsigned int i = 0; i < cnt; i++) str[i] = c;
    }

    string(const string& s) 
    {  
        str = new char[s.size];
        size = s.size;
        capacity = 2 * size;
        for (unsigned int i = 0; i < size; i++) str[i] = s.str[i];
    }

    ~string()
    {
        delete[] str;
    }

    string& operator= (const string& new_str) 
    {  
        str = new char[new_str.size];
        size = new_str.size;
        capacity = 2 * size;
        for (unsigned int i = 0; i < size; i++) str[i] = new_str.str[i];
        //не ясно что должна возвращать функция такого типа
    }

    bool operator== (const string& other) 
    {  
        if (size != other.size) return false;
        else
            for (unsigned int i = 0; i < size; i++)
                if (str[i] != other.str[i])
                    return false;
        return true;
    }

    bool operator!= (const string& other) 
    {  
        if (size != other.size) return true;
        else
            for (unsigned int i = 0; i < size; i++)
                if (str[i] != other.str[i])
                    return true;
        return false;
    }

    bool operator> (const string& other) 
    {  
    
    }

    bool operator< (const string& other) 
    {  
    
    }

    string& operator+= (const string& other) 
    {  
    
    }

    char operator[] (unsigned int pos) 
    {  
        return str[pos];
    }

    void append(const string other);  // дописать в конец данной строки другую

    void resize(unsigned int new_capacity);  // увеличить/уменьшить емкость строки

    void reserve(unsigned int capacity); // зарезервировать память в нужном объеме

    void insert(unsigned int pos, string other);  // Вставка другой строки внутрь данной

    void shrink_to_fit();  //очистить неиспользуемую память

    void clear();   //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {  }
    friend std::istream& operator>> (std::istream& istr, const string& str) {  }

};


string operator + (const string& str1, const string& str2)
{
    string res();
    res.size = str1.size + str2.size;
    res.capacity = res.size * 2;
    for (unsigned int i = 0; i < str1.size; i++) res[i] = str1[i];
    for (unsigned int i = str1.size; i < str1.size + str2.size; i++) res[i] = str2[i - str1.size];
    return res();
}


int stoi(const string str, std::size_t pos = 0, int base = 10);
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main()
{
    string s1(10, '*');
    string s2(10, '*');
    s2 = s1;
    std::cout << (s1 + s2) << '\n';
    std::cout << (s1.str) << '\n';
    std::cout << (s2[1]) << '\n';
    return 0;
}