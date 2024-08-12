#ifndef PHONEBOOK_CLASSE_HPP
#define PHONEBOOK_CLASSE_HPP

#include "../includes/phonebook.hpp"
#include <iostream>
#include <string>

class phonebook
{
private:
    Contact _contact[nbr_contact];
    int _index;
    const int _columsize;
    std::string _rightAlign(const std::string& text);
    std::string _int_to_string(int nbr);
    int _string_to_int(const std::string& str);
    void _input_loop(void (Contact::*set_action)(std::string), const std::string& message);
    bool _check_overwrite_the_contact();
    void _print_head();
    void _print_index_enty(int nbr);
    int _array_size();
    void _print_line(    std::string index,
                                    std::string first_name,
                                    std::string last_name,
                                    std::string nick_name);
    void _select_index();

public:
    phonebook();
    ~phonebook();
    void add();
    void search();
};

#endif