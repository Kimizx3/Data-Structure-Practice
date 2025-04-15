//
// Created by Kimiz on 4/14/2025.
//

#pragma once
#include <iostream>

template<typename T>                        // template class
class Vector
{
private:
    T* m_Data = nullptr;                    // Pointer to the actual array
    size_t m_Size = 0;                      // Number of elements currently in the vector
    size_t m_Capacity = 0;                  // Total capacity of the allocated array

    void Resize(size_t newCapacity)
    {
        T* newData = new T[newCapacity];    // allocate new block

        for (size_t i = 0; i < m_Size; ++i)
        {
            newData[i] = m_Data[i];         // move elements
        }

        delete[] m_Data;                    // delete old block
        m_Data = newData;                   // allocate new block


        m_Capacity = newCapacity;           // resize

    }

public:
    Vector() {};                                                      // default constructor
    ~Vector() {delete[] m_Data;};                                     // destructor: clear memory allocation

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            Resize(m_Capacity == 0 ? 1 : m_Capacity * 2); // expand capacity size if array size is bigger than capacity, reserve memory
        m_Data[m_Size++] = value;                                    // add data to array
    }

    void PopBack()
    {
        if (m_Size > 0)
            --m_Size;                                                // if array size is not 0, decrease array size by 1
    }

    inline size_t Size() const {return m_Size;};                     // checker function for array size
    inline size_t Capacity() const {return m_Capacity;};             // checker function for capacity size
    inline bool Empty() const {return m_Size == 0;};                 // checker function for current array size, return true if array is empty

    T& operator[](size_t index)
    {
        return m_Data[index];                                        // square bracket operator to assign current indexed array member element
    }

    const T& operator[](size_t index) const
    {
        return m_Data[index];                                        // square bracket operator to check current indexed array member element
    }

    void Clear()
    {
        m_Size = 0;                                                 // clear current array size, capacity & data pointer remain for future reuse
    }
};
