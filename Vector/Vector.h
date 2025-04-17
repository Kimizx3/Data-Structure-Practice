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
        T* newData = new T[newCapacity];    // Allocate new block

        for (size_t i = 0; i < m_Size; ++i)
        {
            newData[i] = m_Data[i];         // Move elements
        }

        delete[] m_Data;                    // Delete old block
        m_Data = newData;                   // Allocate new block


        m_Capacity = newCapacity;           // Resize array capacity

    }

public:
    Vector() {};                                                      // Default constructor
    ~Vector() {delete[] m_Data;};                                     // Destructor: clear memory allocation

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            Resize(m_Capacity == 0 ? 1 : m_Capacity * 2);            // Expand capacity size if array size is bigger than capacity, reserve memory
        m_Data[m_Size++] = value;                                    // Add data to array
    }

    void PopBack()
    {
        if (m_Size > 0)
            --m_Size;                                                // If array size is not 0, decrease array size by 1
    }

    inline size_t Size() const {return m_Size;};                     // CHECKER FUNCTION for array size
    inline size_t Capacity() const {return m_Capacity;};             // CHECKER FUNCTION for capacity size
    inline bool Empty() const {return m_Size == 0;};                 // CHECKER FUNCTION for current array size, return true if array is empty

    T& operator[](size_t index)
    {
        return m_Data[index];                                        // SQUARE BRACKET OPERATOR to assign current indexed array member element
    }

    const T& operator[](size_t index) const
    {
        return m_Data[index];                                        // SQUARE BRACKET OPERATOR to check current indexed array member element
    }

    void Clear()
    {
        m_Size = 0;                                                 // Clear current array size, capacity & data pointer remain for future reuse
    }

    // TODO: Phase Two
    void Insert(size_t index, const T& value)
    {
        // Out of bounds
        if (index > m_Size) return;

        if (m_Size >= m_Capacity)
            Resize(m_Capacity == 0 ? 1 : m_Capacity * 2);

        // Shift elements from end to index one step to the right
        for (size_t i = m_Size; i > index; --i)
        {
            // 1, 2, 3, 4, 5, 6
            // 1, 2, 3, 7, 4, 5
            m_Data[i] = m_Data[i - 1];
        }

        m_Data[index] = value;
        ++m_Size;
    }

    void Remove(size_t index)
    {
        // Out of bounds
        if (index >= m_Size) return; // Illegal when index == m_Size

        for (size_t i = index; i < m_Size - 1; ++i)
        {

            // 1, 2, 3, 4, 5, 6
            // 1, 2, 4, 5, 6

            m_Data[i] = m_Data[i + 1];
        }
        --m_Size;
    }


    void Reverse(size_t capacity)
    {
        if (capacity == 0 || capacity > m_Size) return;
        size_t begin = 0;
        size_t end = capacity - 1;
        while (begin < end)
        {
            // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
            // 10, 2, 3, 4, 5, 6, 7, 8, 9, 1
            // 10, 9, ................, 2, 1
            // .............................
            // 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

            T temp = m_Data[begin];
            m_Data[begin] = m_Data[end];
            m_Data[end] = temp;

            ++begin;
            --end;
        }
    }

    // Default Version of Reverse()
    void Reverse()
    {
        Reverse(m_Size);
    }


    void ShrinkToFit()
    {
        // Capacity: 64
        // new capacity: 3
        // Resize current capacity(64) to Resize(3) -> capacity(3)

        if (m_Size < m_Capacity)
            Resize(m_Size);
    }

    // Shuffle
    void Shuffle()
    {
        
    }

    // Sort

    static constexpr size_t npos = static_cast<size_t>(-1);
    size_t Find(const T& value)
    {
        for (size_t i = 0; i < m_Size; ++i)
        {
            if (m_Data[i] == value)
            {
                return i;
            }
        }
        return npos;
    }

    // Copy Constructor
    // Copy Assignment
    // Move Constructor
    // Move Assignment
    // Range Check to operator[]
    // Write Unit Tests for Insert / Remove
    // Iterator supports begin(), end()
    // emplace_back() using placement new
    // Add to my own Mini STL library, combine with my other data structures
};
