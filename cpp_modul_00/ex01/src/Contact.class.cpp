#include "Contact.class.hpp"

Contact::Contact(void)
{
    this->_set_string_empty();
}

Contact::~Contact(void)
{
    this->_set_string_empty();
}

std::string Contact::get_firstName(void) const
{
    return (this->_firstName);
}

std::string Contact::get_lastName(void) const
{
    return (this->_lastName);
}

std::string Contact::get_nick(void) const
{
    return (this->_nick);
}

std::string Contact::get_phone(void) const
{
    return (this->_phone);
}

std::string Contact::get_secret(void) const
{
    return (this->_secret);
}

void Contact::set_firstName(std::string arg)
{
    this->_firstName = arg;
    return ;
}
void Contact::set_lastName(std::string arg)
{
    this->_lastName = arg;
    return ;
}

void Contact::set_nick(std::string arg)
{
    this->_nick = arg;
    return ;
}

void Contact::set_phone(std::string arg)
{
    this->_phone = arg;
    return ;
}

void Contact::set_secret(std::string arg)
{
    this->_secret = arg;
    return ;
}

void Contact::_set_string_empty(void)
{
    this->_firstName = "";
    this->_lastName = "";
    this->_nick = "";
    this->_phone = "";
    this->_secret = "";
}

void _print_get_error(std::string arg)
{
    std::cout << arg << " not set!" << std::endl;
}