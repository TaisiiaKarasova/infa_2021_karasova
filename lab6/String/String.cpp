#include <iostream>
#include <cstddef>
using std::size_t;
using std::cout;


struct string 
{
    char* str;
    size_t size;
    size_t capacity;

    string () 
    {
        str = NULL;
        size = 0;
        capacity = size * 2;
    }

    string(size_t cnt, char c)
    {
        size = cnt;
        capacity = 2 * size;
        str = new char[capacity];
        for (unsigned int i = 0; i < cnt; i++) 
            str[i] = c;
        str[size] = 0;
    }

    string(const string& s) 
    {  
        size = s.size;
        capacity = 2 * size;
        str = new char[capacity];
        for (unsigned int i = 0; i < size; i++) 
            str[i] = s.str[i];
        str[size] = 0;
    }

    ~string()
    {
       if (str != NULL) delete[] str;
    }

    string& operator= (const string& new_str) 
    {  
        if (new_str.size > capacity)
        {
            if (str != NULL) delete[] str;
            capacity = new_str.size * 2;
            str = new char[capacity];
        }
        size = new_str.size;
        capacity = new_str.capacity;
        for (unsigned int i = 0; i < size; i++)
        {
            str[i] = new_str[i];
        }
        str[size] = 0;
        return *this;
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
        unsigned int i = 0;
        while ((i < size) && (i < other.size) && (str[i] == other[i])) ++i;
        return (str[i] > other[i]);
    
    }

    bool operator< (const string& other) 
    {  
        unsigned int i = 0;
        while ((i < size) && (i < other.size) && (str[i] == other[i])) i++;
        return (str[i] < other[i]);
    
    }

    string& operator+= (const string& other) 
    {  
        if ((size + other.size) >= capacity)
        {
            resize((size + other.size) * 2);
        }
        for (unsigned int i = 0; i < other.size; i++)
        {
            str[i + size] = other[i];
        }
        size += other.size;
        str[size] = 0;
        return *this;
    }

    string& operator+= (const char c)
    {
        if ((size + 1) >= capacity)
        {
            resize((size + 1) * 2);
        }
        str[size] = c;
        size += 1;
        str[size] = 0;
        return *this;
    }

    char operator[] (unsigned int pos) const
    {  
        return str[pos];
    }

    void append(const string &other)
    {
        *this += other;
    }

    void resize(unsigned int new_capacity)
    {
        char* new_str = NULL;
        if (new_capacity == 0)
        {
            size = 0;
        }
        else
        {
            new_str = new char[new_capacity];
            if (new_capacity <= size)
                size = new_capacity - 1;
            for (unsigned int i = 0; i < size; ++i)
                new_str[i] = str[i];
        }
        if (str) delete str;
        str = new_str;
        capacity = new_capacity;
    }

    void reserve(unsigned int capacity)
    {
        resize(std::max(capacity, this->capacity));
    }

    void insert(unsigned int pos, string other)
    {
        if (size + other.size >= capacity)
            resize((size + other.size) * 2);
        for (unsigned int i = size; i >= pos; i--)
            str[i + other.size] = str[i];
        for (unsigned int i = 0; i < other.size; i++)
            str[pos + i] = other[i];
    }

    void shrink_to_fit()
    {
        resize(size + 1);
    }

    void clear()
    {
        if (str)
        {
            str[0] = 0;
            size = 0;
        }
    }

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) 
    {  
        return ostr << str.str;
    
    }
    friend std::istream& operator>> (std::istream& istr, string& str) 
    {  
        str.clear();
        char t;
        while ((!istr.eof()) && (t == istr.get()) && (t != ' ') && (t != '\n'))
            str += t;
        return istr;
    
    }

};


string operator + (const string& str1, const string& str2)
{
    string res;
    res += str1;
    res += str2;
    return res;
}


int StrToInt (const string str, std::size_t pos = 0, int base = 10)
{
    int value = 0;
    int number;
    if (str[0] == '-') pos += 1;
    unsigned int length = str.size; // to avoid recounting it during each iteration
    while (pos < length)
    {
        if (str[pos] >= '0' && str[pos] <= '9' && str[pos] < '0' + base)
            number = str[pos] - '0';
        else if (str[pos] >= 'A' && str[pos] < 'A' - 10 + base)
            number = str[pos] - 'A' + 10;
        else if (str[pos] >= 'a' && str[pos] < 'a' - 10 + base)
            number = str[pos] - 'a' + 10;
        else break;
        value *= base;
        value += number;
        pos++;
    }
    if (str[0] == '-') return -value;
    else return value;

}

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