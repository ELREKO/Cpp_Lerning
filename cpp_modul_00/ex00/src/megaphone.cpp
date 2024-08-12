#include <iostream>
#include <string>

static void toUpperString(std::string& str);
static void use_cout(const std::string& str, bool space);

int main(int argc, char* argv[]) 
{
    std::string str;

    if (argc < 2) {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i)
    {   
        str = argv[i];
        toUpperString(str);
        use_cout(str, true);
    }
    std::cout << std::endl;
    return 0;
}

static void toUpperString(std::string& str) 
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        str[i] = std::toupper(str[i]);
    }
}

static bool cout_err(void)
{
    if (std::cout.fail()) {
        std::cerr << "Fehler beim Schreiben auf std::cout!" << std::endl;
        return (1);
    }
    return (0);
}

static void use_cout(const std::string& str, bool space)
{
    for (size_t i = 0; i < str.size(); ++i) 
    {
        std::cout << str[i];
        if (cout_err())
            break;
    }
    if (space)
    {
        std::cout << " ";
        cout_err();
    }
}


