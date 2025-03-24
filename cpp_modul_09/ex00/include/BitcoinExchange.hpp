#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <iomanip>

enum printColor {
    RED = 31,   
    GREEN = 32,  
    YELLOW = 33,
    BLUE = 34,  
	MAGENTA = 35,
	CYAN = 36, 
	GTAY = 30,
	WHITE = 37,
    RESET = 0  
};


class BitcoinCalculator 
{
    private:
        std::map<std::string, float> _bitCoinCompare; 
        std::string _path_compare_csv;
        std::string _path_question_csv;


    protected:
        bool ReadCompare_File(std::string path, char seperator, bool store);
        bool checkDate(const std::string &date);
        bool CheckLine(const std::string& line, char seperator, bool map_storage, int line_number);
        float FindMultiplikant(std::string searchDate);
        void PrintOut(const std::string &line, char seperator, long line_number, bool storage);

    public:
        BitcoinCalculator(); 
        BitcoinCalculator(std::string path_compare_csv,  std::string path_question_csv); 
        BitcoinCalculator(const BitcoinCalculator &copy);
		BitcoinCalculator &operator=(const BitcoinCalculator &src);
        ~BitcoinCalculator();

        int Calculate(char sep_compare, char sep_calculate);
        void printMap();
};

std::string getColorCode(printColor color);

#endif