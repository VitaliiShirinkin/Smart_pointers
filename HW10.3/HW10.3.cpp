//Задача 3 * .std::unique_ptr своими руками

#include <iostream>
#include"Unique_ptr.h"

int main()
{
    int x = 50;
    int* ptr_x = &x;
    std::cout << "*ptr_x = "<< * ptr_x << '\n';

    unique_ptr<int> smart_ptr(ptr_x);
    std::cout <<"*smart_ptr = " << * smart_ptr << '\n';

    unique_ptr<int> smart_ptr2 = std::move(smart_ptr);
    std::cout <<"*smart_ptr2 = " << * smart_ptr2 << '\n';

    *smart_ptr2 = 30;
    std::cout << "*smart_ptr2 = " << *smart_ptr2 << '\n';

    unique_ptr<int> smart_ptr3 = std::move(smart_ptr2);
    *smart_ptr3 = 200;
    std::cout << "*smart_ptr3 = " << *smart_ptr3 << '\n';

    ptr_x = smart_ptr3.release();

    std::cout << "*ptr_x = " << *ptr_x << '\n';

    return 0;
}
