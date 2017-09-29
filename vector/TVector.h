#ifndef TVECTOR_TVECTOR_H
#define TVECTOR_TVECTOR_H
#include <iostream>

template <typename T>
class TVector{
    size_t Size;
    size_t Capacity;
    T* Ptr;
public:
    TVector():
            Size(0),
            Capacity(0),
            Ptr(nullptr)
    {}

    TVector(T* ptr, size_t size, size_t cap):
            Size(size),
            Capacity(cap),
            Ptr(ptr)
    {}

    TVector(const TVector & rhs):
            Size(rhs.Size),
            Capacity(rhs.Capacity)
    {
        delete[] Ptr;
        Ptr = new T[Capacity];
        for (int i = 0; i < Size; i++)
        {
            Ptr[i] = rhs.Ptr[i];
        }

    }

    TVector& operator=(const TVector & rhs)
    {
        if(this == &rhs)
            return *this;
        Size = rhs.Size;
        Capacity = rhs.Capacity;
        delete[] Ptr;
        Ptr = new T[Capacity];
        for (int i = 0; i < Size; i++)
        {
            Ptr[i] = rhs.Ptr[i];
        }
        return *this;
    }

    TVector& operator=(TVector&& rhs)
    {
        if(this == &rhs)
            return *this;
        Size = rhs.Size;
        Capacity = rhs.Capacity;
        rhs.Size = 0;
        rhs.Capacity = 0;
        delete[] Ptr;
        std::swap(Ptr, rhs.Ptr);
        return *this;
    }

    TVector(TVector&& rhs):
            Size(rhs.Size),
            Capacity(rhs.Capacity)
    {
        delete[] Ptr;
        rhs.Size = 0;
        rhs.Capacity = 0;
        std::swap(Ptr, rhs.Ptr);
    }
    ~TVector()
    {
        if(Ptr != nullptr)
            delete[] Ptr;
    }
};

#endif //TVECTOR_TVECTOR_H
