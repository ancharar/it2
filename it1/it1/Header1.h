#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array
{
    T* Xarray;
    int len;
    int max_size;

public:
    class Iterator;
    Array()
    {
        len = 0;
        Xarray = new T[1];
        max_size = 1;
    }
    ~Array() { delete[]Xarray; }

    void pushBack(const T& value)
    {
        if (len >= max_size) addMemory();
        Xarray[len] = value;
        len++;
    }

    void addMemory()
    {
        max_size *= 2;
        T* tmp = Xarray;
        Xarray = new T[max_size];
        for (int i = 0; i < len; ++i)
            Xarray[i] = tmp[i];
        delete[] tmp;
    }

    T& operator[](const int Li)
    {
        return Xarray[Li];
    }

    Iterator Front()
    {
        return &Xarray[0];
    }

    Iterator Back()
    {
        return &Xarray[len];
    }

    void Fill(const int Xi)
    {
        for (auto i : Xarray)
        {
            Xarray[i] = Xi;
        }
    }

    size_t max() const
    {
        return max_size;
    }

    int Size()
    {
        return len;
    }

    void Resize(const int S)
    {
        T* Rarray = new T[S];

        for (int i = 0; i < len; i++)
        {
            Rarray[i] = Xarray[i];
        }

        delete[]Xarray;
        Xarray = new T[S];

        for (int i = 0; i < S; i++)
        {
            Xarray[i] = Rarray[i];
        }

        len = S;
    }

    Array& operator +(Array a)
    {
        const int lenn = len + a.Size();
        T* x = new T[lenn];

        for (int i = 0; i < len; i++)
        {
            x[i] = Xarray[i];
        }

        for (int i = len, g = 0; i < lenn; i++, g++)
        {
            x[i] = a[g];
        }

        len = lenn;
        delete[]Xarray;
        Xarray = new T[len];

        for (int i = 0; i < len; i++)
        {
            Xarray[i] = x[i];
        }
        return *this;
    }

    void operator =(Array x)
    {

        T* XXarr = new T[x.Size()];

        for (int i = 0; i < x.Size(); i++)
        {
            XXarr[i] = x[i];
        }

        delete[]Xarray;
        len = x.Size();
        Xarray = new T[len];

        for (int i = 0; i < len; ++i)
        {
            Xarray[i] = XXarr[i];
        }
    }

    template<typename T2>
    friend ostream& operator<< (ostream& s, const Array<T2>& n);

    Iterator begin() { return Iterator(Xarray); }
    Iterator end() { return Iterator(Xarray + len); }

    friend ostream& operator<< (ostream& s, const Array<T>& n);

    class Iterator
    {
        T* cur;

    public:
        Iterator(T* first) : cur(first)
        {}

        Iterator& operator++ ()
        {
            ++cur;
            return *this;
        }

        T& operator+ (int n) { return *(cur + n); }
        T& operator- (int n) { return *(cur - n); }

        T& operator++ (int)
        {
            T temp = *cur;
            ++(*this);
            return temp;
        }

        T& operator-- (int)
        {
            T temp = *cur;
            --(*this);
            return temp;
        }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }
        T& operator* () { return *cur; }
    };
};

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

template <typename T>
ostream& operator<< (ostream& s, const Array<T>& n)
{
    for (int i = 0; i < n.Size(); ++i) {
        s << n[i] << " ";
    }
    return s;
}

#endif ITERATOR_H