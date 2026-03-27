#include "Base.hpp"
#include <cstdlib>

int main()
{
    Base* b1 = generate();
    Base* b2 = generate();
    Base* b3 = generate();
    Base* b4 = generate();
    Base* b5 = generate();

    Base* array[5] = {b1, b2, b3, b4, b5};

    for (int i = 0; i < 5; i++)
    {
            identify(array[i]);
            identify(*array[i]);
            delete array[i];
    }
    return 0;
}