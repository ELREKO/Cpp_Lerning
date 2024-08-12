#include "Phonebook.classe.hpp"

phonebook::phonebook() : _columsize(10)
{
    this->_index = 0;
    std::cout << std::endl << "Welcome to the Phone book tool in C++ Modul 00 exercice 01" << std::endl << std::endl;
}

phonebook::~phonebook()
{
    std::cout << std::endl << "You are closeing the Phonebook bye" << std::endl << std::endl;
}

void phonebook::add()
{
    std::string name;
    if (!_check_overwrite_the_contact())
        return;
    std::cout   << std::endl << "---------------" << std::endl
                << "You are add this Contact to index number " 
                << this->_index % nbr_contact 
                << std::endl << std::endl;
    this->_input_loop(&Contact::set_firstName, "Enter a first name: ");
    name = this->_contact[this->_index % nbr_contact].get_firstName();
    this->_input_loop(&Contact::set_lastName, "Enter a last name from " + name + " :" );
    this->_input_loop(&Contact::set_nick, "Enter a nick name from " + name + " :" );
    this->_input_loop(&Contact::set_phone, "Enter a phone number from " + name + " :" );
    this->_input_loop(&Contact::set_secret, "Enter a dark secret from " + name + " :" );
    std::cout   << std::endl << "Thank you all Information for contact number " 
                << this->_index % nbr_contact << " name [" 
                << this->_contact[this->_index % nbr_contact].get_firstName() << "]"
                << " are set."<< std::endl << "---------------" << std::endl;
    this->_index++;
    return;
}

void phonebook::search() {
    int i_count = 0;

    if (this->_contact[0].get_firstName() != "")
    {
        this->_print_head();
        while (i_count < nbr_contact)
        {
            if (this->_contact[i_count].get_firstName()== "")
                break;
            this->_print_line   (  this->_rightAlign(this->_int_to_string(i_count)),
                                this->_rightAlign(this->_contact[i_count].get_firstName()),
                                this->_rightAlign(this->_contact[i_count].get_lastName()),
                                this->_rightAlign(this->_contact[i_count].get_nick())
                                );
            i_count++;
        }
        std::cout << " " << std::string(43, '-') << std::endl;
        this->_select_index();
    }
    else
        std::cout << "Please add one contact first use the 'ADD' command!" << std::endl;
    return;
}
