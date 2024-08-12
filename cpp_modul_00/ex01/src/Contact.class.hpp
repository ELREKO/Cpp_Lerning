#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

# include "../includes/phonebook_ext_lib.hpp"

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nick;
		std::string _phone;
		std::string _secret;
		void _set_string_empty(void);
		void _print_get_error(std::string arg);


	public:
		Contact(void);
		~Contact(void);

    	std::string get_firstName(void) const;
		std::string get_lastName(void) const;
		std::string get_nick(void) const;
		std::string get_phone(void) const;
		std::string get_secret(void) const;

		void set_firstName(std::string);
		void set_lastName(std::string);
		void set_nick(std::string);
		void set_phone(std::string);
		void set_secret(std::string);
};

#endif