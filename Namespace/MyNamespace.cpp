#include "MyNamespace.h"

int main()
{
    MyNamespace::Vector<int> myVec{};

    myVec.PushBack(10);
    myVec.PushBack(20);
    myVec.PushBack(30);

    std::cout << "Size: " << myVec.Size() << ", Capacity: " << myVec.Capacity() << "\n";

    for (size_t i = 0; i < myVec.Size(); ++i)
    {
        std::cout << "Element " << i << ": " << myVec[i] << "\n";
    }

    myVec.Insert(2, 30);

    myVec.Remove(1);
    for (size_t i = 0; i < myVec.Size(); ++i)
    {
        std::cout << "Element " << i << ": " << myVec[i] << "\n";
    }

    std::cout << "After Remove(), Size: " << myVec.Size() << ", Empty? " << myVec.Empty() << "\n";

    myVec.Reverse(myVec.Size());
    for (size_t i = 0; i < myVec.Size(); ++i)
    {
        std::cout << "Element " << i << ": " << myVec[i] << "\n";
    }

    srand(time(nullptr));

    myVec.Shuffle();

    for (size_t i = 0; i < myVec.Size(); ++i) {
        std::cout << "Shuffled Element " << i << ": " << myVec[i] << "\n";
    }

    return 0;
}