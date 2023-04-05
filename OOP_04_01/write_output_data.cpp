#include <fstream>

#include "return_codes.h"
#include "address.h"
#include "display_message.h"

#include "write_output_data.h"

void write_output_data(int* p_addresses_amount, Address** p_p_addresses)
{
    if (p_addresses_amount == nullptr)
    {
        display_message(wrong_ptr_transmission_error);
        return;
    }
    
    if (p_p_addresses == nullptr)
    {
        if (*p_addresses_amount != 0)
        {
            display_message(wrong_ptr_transmission_error);
            return;
        }
    }
    
    std::ofstream output_file("../OOP_04_01/out.txt");
    
    int local_addresses_amount = *p_addresses_amount;
    
    output_file << local_addresses_amount << std::endl;
    
    if (local_addresses_amount == 0)
    {
        output_file.close();
        return;
    }
    
    std::string output_address = "";
    
    for (int address = local_addresses_amount - 1; address >= 0 ; address--)
    {
        output_address = p_p_addresses[address]->form_output_address();
        output_file << output_address << std::endl;
    }
    
    output_file.close();
}
