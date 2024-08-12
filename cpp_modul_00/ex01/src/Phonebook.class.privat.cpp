#include "Phonebook.classe.hpp"

void phonebook::_select_index()
{
    std::string str_index_nbr ;
    int i_index_nbr = 0;

    while (1)
    {   
        std::cout << "Select an Index number :";
        std::cin >> str_index_nbr;
        if (std::cin.eof())
            return;
        i_index_nbr = _string_to_int(str_index_nbr);
        if (i_index_nbr == -1)
            continue;
        else
            break;
    }
 
    this->_print_index_enty(i_index_nbr);
}

void phonebook::_print_index_enty(int nbr)
{
    std::cout   << "First Name     :"
                << this->_contact[nbr].get_firstName() << std::endl
                << "Last Name      :"
                << this->_contact[nbr].get_lastName() << std::endl
                << "Nick Name      :"
                << this->_contact[nbr].get_nick() << std::endl
                << "Phone Number   :"
                << this->_contact[nbr].get_phone() << std::endl
                << "Dark Secret    :"
                << this->_contact[nbr].get_secret() << std::endl;
}

void   phonebook::_print_head()
{
    std::cout << " " << std::string(43, '-') << std::endl;
    this->_print_line   (   this->_rightAlign("Index"),
                            this->_rightAlign("First Name"),
                            this->_rightAlign("Last Name"),
                            this->_rightAlign("Nick Name")
                        );
    this->_print_line   (   std::string(this->_columsize, '-'),
                            std::string(this->_columsize, '-'),
                            std::string(this->_columsize, '-'),
                            std::string(this->_columsize, '-')
                        );
}

void phonebook::_print_line(    std::string index,
                                std::string first_name,
                                std::string last_name,
                                std::string nick_name)
{
    std::cout   << "|" << index << "|" << first_name
                << "|" << last_name << "|" << nick_name << "|"
                << std::endl;
}

std::string phonebook::_int_to_string(int nbr)
{
    std::stringstream ss;
    ss << nbr;
    return(ss.str()); 
}

int phonebook::_string_to_int(const std::string& str)
{
    int input_int;
    std::stringstream ss(str);
    ss >> input_int;
    if (!ss.fail() && ss.eof())
    {
        if (input_int >= this->_array_size())
            std::cout << "Invalid Number" << std::endl;
        else
            return (input_int);
    } 
    else 
    {
        std::cerr << "Please Select a Index number!" << std::endl;
    }
    return (-1);
}

std::string phonebook::_rightAlign(const std::string& text)
{
    size_t colum_size;

    colum_size = this->_columsize;
    if (text.length() >= colum_size)
        return text.substr(0, colum_size- 1) + ".";
    else
        return std::string(colum_size - text.length(), ' ') + text;
}

void phonebook::_input_loop(void (Contact::*set_action)(std::string), const std::string& message)
{
    std::string name;
    while (!std::cin.eof() && name == "")
    {
        std::cout << message;
        if (std::getline(std::cin, name) && name != "")
                (this->_contact[this->_index % nbr_contact].*set_action)(name);
    }
}

int phonebook::_array_size()
{
    int i_count = 0;

    while (i_count < nbr_contact)
    {
        if (this->_contact[i_count].get_firstName() == "")
            break;
        i_count++;
    }
    return (i_count);

}

bool phonebook::_check_overwrite_the_contact(void)
{
    std::string name;
    if (this->_index >= nbr_contact)
    {
        std::cout   << "---------------" << std::endl
                    << "Warning you are overwrite contact number " 
                    << this->_index % nbr_contact 
                    << " name [" 
                    << this->_contact[this->_index % nbr_contact].get_firstName() << "]"
                    << std::endl << "Overwrite this contact ? (y) (n):";
        while (std::getline(std::cin, name))
        {
            if (name == "y")
                return true; 
            else if ( name == "n")
                return false;
            std::cout   << "You want to overwrite this contact ?" << std::endl 
                        << "Please press 'y' for yes and 'n' for no :"; 
        } 
    }
    return true;
}
