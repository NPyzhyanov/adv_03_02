#include <iostream>
#include <string>

#include "smart_array.h"

int main()
{
    try
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        
        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);
        
        arr.print("arr before assignment");
        new_array.print("new_array before assignment");
        
        arr = new_array;
        
        arr.print("arr after assignment");
        new_array.print("new_array after assignment");
    }
    catch (const std::exception &ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
