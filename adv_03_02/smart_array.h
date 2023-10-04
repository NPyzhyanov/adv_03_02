#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

class smart_array
{
public:
    smart_array(int size_);
    smart_array(int size_, int filled_elements_amount_, int* address_);
    ~smart_array();
    
    smart_array (const smart_array& right_array);
    smart_array& operator=(const smart_array&);
    
    void add_element(int value);
    int get_element(int position);
    
    void print(std::string invitation_message);
    int* get_address();
    
    
    int get_size();
    int get_filled_amount();
    
private:
    int* address;
    int size;
    int filled_elements_amount;
    
};

#endif // SMART_ARRAY_H
