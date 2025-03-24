#include "../include/BitcoinExchange.hpp"

// ------------------------------------- Lib funktion ---------------------------------

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)  
        return "";
    size_t last = str.find_last_not_of(" \t\n\r\f\v"); 
    return str.substr(first, (last - first + 1));
}

bool isLineEmpty(const std::string& line) {
    std::string trimmed = trim(line);
    return trimmed.empty();
}

std::string removeAllWhiteSpace(std::string str) {
    std::string result = "";
    
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isspace(str[i])) {
            result += str[i];
        }
    }
    
    return result;
}

bool Schatjahr(int year)
{
    const int baseyear = 1588; // Gregorianischer Kalender!
    if ((year - baseyear) % 4 == 0)
        return true;
    return false;
}

std::string getColorCode(printColor color) {
    std::ostringstream oss;
    oss << "\033[" << color << "m";
    return oss.str();
}

//------------------------------------Const and Deconstr ---------------------------------

BitcoinCalculator::BitcoinCalculator() {}

BitcoinCalculator::BitcoinCalculator(std::string path_compare_csv,  std::string path_question_csv) : _path_compare_csv(path_compare_csv), _path_question_csv(path_question_csv)
{
    //std::cout << "Start Constructer" << std::endl;
}

BitcoinCalculator::BitcoinCalculator(const BitcoinCalculator &copy)
{   
    *this = copy;
}

BitcoinCalculator &BitcoinCalculator::operator=(const BitcoinCalculator &src)
{
    if (this != &src)
	{
		this->_bitCoinCompare = src._bitCoinCompare;
        this->_path_question_csv = src._path_question_csv;
        this->_path_compare_csv = src._path_compare_csv;
	}
	return (*this);
}

BitcoinCalculator::~BitcoinCalculator()
{
   // std::cout << "Deconstructor" << std::endl;
}

// ------------------------ public Members ---------------------------------------

int BitcoinCalculator::Calculate(char sep_compare, char sep_calculate)
{
    if (!ReadCompare_File(this->_path_compare_csv, sep_compare, true))
    {
        std::cerr << getColorCode(RED) << "Incorrect or Empty Data file" << getColorCode(RESET) << std::endl;
        return 1;
    }

    if (!ReadCompare_File(this->_path_question_csv, sep_calculate, false))
    {
        std::cerr << getColorCode(RED) << "Incorrect or Empty given file" << getColorCode(RESET) << std::endl;
        return 1;
    }

    return 0;  
}

void BitcoinCalculator::printMap()
{
    for (std::map<std::string, float>::iterator it = _bitCoinCompare.begin(); it != _bitCoinCompare.end(); ++it) 
    {
        if (it->second > 20)
            return;
        std::cout << "Datum: " << it->first << ", Wert: " << it->second << std::endl;
    }
}

// -------------------------- Protectet Members -----------------------------------------


bool BitcoinCalculator::checkDate(const std::string &date)
 {
    // Check Date Format (yyyy-mm-dd)
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    try 
    {
        year = std::atoi(date.substr(0, 4).c_str());  
        month = std::atoi(date.substr(5, 2).c_str()); 
        day = std::atoi(date.substr(8, 2).c_str());  
    } 
    catch (...)    { return false; }

    // Gregorianischer Kalender! 
    if ((year == 1582 && ((month >= 10 && day < 15) || month < 10)) || year < 1582)
        return false;

    if (month < 1 || month > 12)
        return false;

    if ((month == 2 && Schatjahr(year) && (day < 1 || day > 29)) ||  // Schaltjahr 
        (month == 2 && !Schatjahr(year) && (day < 1 || day > 28)) || 
        (( month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) || 
        (day < 1 || day > 31))
        return false;

    // Check Date withe actuall date 
    std::time_t t = std::time(0);
    std::tm* now = std::gmtime(&t);
    if (year > (now->tm_year + 1900) || 
        (year == (now->tm_year + 1900) && month > (now->tm_mon + 1)) ||
        (year == (now->tm_year + 1900) && month == (now->tm_mon + 1) && 
        day > now->tm_mday))
            return false;
    return true;
}



bool BitcoinCalculator::CheckLine(const std::string& line, char seperator, bool map_storage, int line_number) 
{
    std::string date, value_str, line_cp;

    // Check Seperator 
    if (std::string::npos == line.find(seperator))
    {
        if(line_number != 0)
            std::cerr   << getColorCode(RED) << "Error: No seperator \"" << seperator << "\" found! -> \"" << line << "\" -> line: " 
                        << line_number  <<  getColorCode(RESET) << std::endl;
        return false;
    }

    std::istringstream ss(removeAllWhiteSpace(line));
    if (!std::getline(ss, date, seperator) || !std::getline(ss, value_str))
        return false;
    
    //CheckDate 
    if (!checkDate(date))
    { 
        if(line_number != 0)
            std::cerr   << getColorCode(RED) << "Error: Wrong Date \"" << date << "\" format \"yyyy-mm-dd\" -> line:" << line_number << getColorCode(RESET) <<  std::endl;
        return false;
    }
        
    // Check value 
    char *end;
    double value = std::strtod(value_str.c_str(), &end);
    if (end == value_str.c_str() || *end != '\0') {
        // Ungültige Zahl oder nicht vollständig konvertiert
        std::cerr   << getColorCode(RED) << "Fehler: Ungültiger Wert '" 
                    << value_str << " -> line: " << line_number  
                    << getColorCode(RESET) << std::endl;;
        return false;
    }

    if (map_storage)
        _bitCoinCompare[date] = value;

    return true;
}

void BitcoinCalculator::PrintOut(const std::string &line, char seperator, long line_number, bool storage)
{
    std::string date, value_str;
    float multi, value;
    
    std::istringstream ss(line);
    std::getline(ss, date, seperator);
    std::getline(ss, value_str);
    value = std::atof(value_str.c_str());

    if (value < 0)
        std::cerr << getColorCode(RED) << "Error: not a positive number"  << " -> line: " << line_number << getColorCode(RESET) << std::endl;
    else if (value > 1000)
        std::cerr << getColorCode(RED) << "Error: too large a number." << " -> line: " << line_number << getColorCode(RESET) << std::endl;
    // else if (!(CheckLine(line, seperator, storage, line_number)))
    //     std::cerr << getColorCode(RED) << "Error: bad input => " << line << " -> line: " << line_number << getColorCode(RESET) << std::endl;
    else
    {
        if ((CheckLine(line, seperator, storage, line_number)))
        {
            multi = FindMultiplikant (date);
            std::cout << date << " => " << value <<  " = " << multi << " = " <<  value*multi << std::endl;
        }
    }

}

// Liest die CSV-Datei und speichert gültige Einträge in _bitCoinCompare oder schreibt dies auf die Konsole
bool BitcoinCalculator::ReadCompare_File(std::string path, char seperator, bool store) 
{
    std::ifstream file(path.c_str());
    if (!file.is_open()) {
        throw std::runtime_error(getColorCode(RED) + "Error: Could not open file: " + _path_compare_csv + getColorCode(RESET));
    }

    std::string line;
    int line_number = 0;

    while (std::getline(file, line)) 
    {
        // Jump over the Headline 
        if ((line_number == 0 && !(CheckLine(line, seperator, store, line_number))) || isLineEmpty(line))
        {
            line_number++;
            continue;
        }

        //CSV incorret --> break up! 
        if (store && ((!(CheckLine(line, seperator, store, line_number))) || (std::string::npos == line.find(seperator))))
            {
                file.close();
                return (false);
            }
        
        if (!store && !this->_bitCoinCompare.empty())
            PrintOut(line, seperator, line_number, store);
        line_number++;
    }

    file.close();
    return true;
}

float BitcoinCalculator::FindMultiplikant(std::string searchDate)
{
    std::map<std::string, float>::iterator it = this->_bitCoinCompare.lower_bound(searchDate);

    if (it != this->_bitCoinCompare.begin() && (it == this->_bitCoinCompare.end() || it->first != searchDate))
        --it;
    return it->second;
}


