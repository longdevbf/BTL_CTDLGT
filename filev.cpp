#include <bits/stdc++.h>
using namespace std;

template <class T>
class Vector
{
private:
    int size, space;
    T *elem;
    void Expand(int newspace)
    {
        if (newspace <= space)
            return;
        else
        {
            T *odd = elem;
            elem = new T[newspace];
            for (int i = 0; i < size; i++)
            {
                elem[i] = odd[i];
            }
            delete[] odd;
            space = newspace;
        }
    }

public:
    Vector() 
    {
        size = space = 0;
        elem = NULL;
    }
    Vector(int n)
    {
        size = 0;
        space = n;
        elem = new T[n];
    }
    ~Vector() { delete[] elem; }
    int getSize()
    {
        return size;
    }
    int getSpace()
    {
        return space;
    }
    T getElem(int i)
    {
        return elem[i];
    }
    bool Empty()
    {
        return size == 0;
    }
    Vector<T> &operator=(Vector<T> &p)
    {
        if (this != &p)
        {
            delete[] elem;
            this->size = p.size;
            this->space = p.space;
            elem = new T[space];
            for (int i = 0; i < size; i++)
            {
                elem[i] = p.elem[i];
            }
        }
        return *this;
    }
    
    T &operator[](int i)
    {
        return elem[i];
    }

    void Push_Back(T val)
    {
        if (size == space)
        {
            if (size == 0)
        {
            Expand(1);
        }
            else
                Expand(2 * size);
        }
        elem[size] = val;
        size++;
    }
    void Pop_Back()
    {
        size--;
    }
    void Insert(T val, int pos)
    {
        if (size == space)
        {
            if (size == 0)
                space = 1;
            else
                Expand(2 * size);
        }
        for (int i = size; i > pos; i--)
        {
            elem[i] = elem[i - 1];
        }
        elem[pos] = val;
        size++;
    }
    void Erase(int pos)
    {
        for (int i = pos; i < size - 1; i++)
        {
            elem[i] = elem[i + 1];
        }
        size--;
    }
    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << elem[i] << " ";
        }
    }
    void Clear()
    {
        size = 0;
    }
};

// int main()
// {
//     Vector<int> a(10);
//     for(int i=0;i<10;i++)
//     {
//         a.Push_Back(i);
//     }
// }
