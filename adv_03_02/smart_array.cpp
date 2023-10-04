#include <stdexcept>
#include <iostream>
#include <string>

#include "smart_array.h"

smart_array::smart_array(int size_)
{
    if (size_ <= 0)
    {
        throw std::runtime_error("Invalid size of array.");
    }
    
    size = size_;
    filled_elements_amount = 0;
    address = new int[size];
}

smart_array::smart_array(int size_, int filled_elements_amount_, int* address_)
{
    if (size_ <= 0)
    {
        throw std::logic_error("Invalid size of array.");
    }
    if (filled_elements_amount_ > size_)
    {
        throw std::logic_error("Cannot create an array with filled elements amount greater than its size");
    }
    if (address_ == nullptr)
    {
        throw std::logic_error("Transmittion of a null pointer");
    }
    
    size = size_;
    filled_elements_amount = filled_elements_amount_;
    address = address_;
}

smart_array::~smart_array()
{
    delete[] address;
    address = nullptr;
}

smart_array::smart_array(const smart_array& right_array)
{
    size = right_array.size;
    filled_elements_amount = right_array.filled_elements_amount;
    address = new int[size];
    for (int i = 0; i < filled_elements_amount; i++)
    {
        address[i] = right_array.address[i];
    }
}

smart_array& smart_array::operator=(const smart_array& right_array)
{
    if (&right_array == this)
    {
        return *this;
    }
    smart_array tmp(right_array);
    size = tmp.size;
    filled_elements_amount = tmp.filled_elements_amount;
    int* tmp_address = tmp.address;
    tmp.address = address;
    address = tmp_address;
    return *this;
}

void smart_array::add_element(int value)
{
    if (filled_elements_amount >= size)
    {
        throw std::runtime_error("Cannot add a new element. The array is completely filled.");
    }
    
    address[filled_elements_amount] = value;
    filled_elements_amount++;
}

int smart_array::get_element(int position)
{
    if (position >= size || position < 0)
    {
        throw std::out_of_range("Cannot get element outside of array");
    }
    if (position >= filled_elements_amount)
    {
        throw std::runtime_error("The element with this index does not yet exist");
    }
    
    return address[position];
}

int* smart_array::get_address()
{
    return address;
}

void smart_array::print(std::string invitation_message)
{
    std::cout << invitation_message << ":";
    for (int i = 0; i < filled_elements_amount; i++)
    {
        std::cout << " " << address[i];
    }
    for (int i = filled_elements_amount; i < size; i++)
    {
        std::cout << " _";
    }
    std::cout << std::endl;
}

int smart_array::get_size()
{
    return size;
}

int smart_array::get_filled_amount()
{
    return filled_elements_amount;
}
