#include <iostream>
#include <fstream>
#include <string>

std::string read_inputfile(const std::string& filename)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "ERROR: The inputstream not found or could not open!" << std::endl;
        return "";
    }

    std::string content, line;
    while (getline(inputFile, line)) {
        content += line + '\n';
    }
    inputFile.close();
    return (content);
}

int write_outputfile(const std::string& filename, const std::string content, const std::string& s1, const std::string& s2)
{
    std::ofstream	outfile((filename + ".replace").c_str());
	int				pos;

	if (outfile.fail() || content.empty())
    {
        std::cerr << "ERROR: The outputstream could not open" << std::endl;
		return 1;
    }
	for (int i = 0; i < (int)content.size(); i++)
	{
		pos = content.find(s1, i);
		if (pos != -1 && pos == i)
		{
			outfile << s2;
			i += std::string(s1).size() - 1;
		}
		else
			outfile << content[i];
	}
    outfile.close();
    std::cout << "Ersetzung erfolgreich. Überprüfen Sie " << filename << ".replace" << std::endl; 
    return 0;
}

int replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::string content;

    content = read_inputfile(filename);
    if (content.empty())
    {
        std::cerr << "Inputstream are empty!" << std::endl;
        return 1;
    }

    return (write_outputfile(filename, content, s1, s2));
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Verwendung: " << argv[0] << " <Dateiname> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    return (replaceInFile(filename, s1, s2));
}
