#include <iostream>
#include <fstream>

#include "headers/main.h"

int main(const int argc, const char **argv)
{
    if(argc < 2)
    {
        std::cerr << "Use format: " << argv[0] << " <string 1> <string 2>\n";
        help();
        return -1;
    }
    if((std::string)argv[1] == "-h" || (std::string)argv[1] == "--help")
    {
        help();
        return 0;
    }
    std::string first, second;
    if((std::string)argv[1] == "-F" || (std::string)argv[1] == "--file")
    {
        if(argc != 4)
        {
            std::cerr << "We need two files\n";
        }
        first = read_file(argv[2]), second = read_file(argv[3]);
    }
    else
    {
        first = argv[1], second = argv[2];
    }
    results(first, second);
    return 0;
}

std::string read_file(const std::string &path)
{
    std::ifstream file(path);
    if(!file.is_open())
    {
        return "";
    }
    std::string buffer, contents;
    while(std::getline(file, buffer))
    {
        contents += buffer;
    }
    file.close();
    return contents;
}

std::string &remove_whitespace(std::string &string)
{
    unsigned int length = string.length();
    for(unsigned int i = 0; i < length; ++i)
    {
        const char &c = string[i];
        switch(c)
        {
            case ' ':
            case '\n':
            case '\r':
            case '\t':
            {
                string.erase(i);
                --i;
                --length;
                continue;
            }
            default:continue;
        }
    }
    return string;
}

void results(std::string &first, std::string &second)
{
    if(first == second)
    {
        std::cout << "Strings are identical\n";
    }
    else if(remove_whitespace(first) == remove_whitespace(second))
    {
        std::cout << "Strings are the same without whitespace\n";
    }
    else
    {
        std::cout << "Strings aren't the same\n";
    }
}

void help()
{
    std::cout << "Options\n-h and --help prints help menu\n" << "-F --file means you want to use files for input\n" << std::endl;
}