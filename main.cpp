#include <iostream>
#include <string>


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

int main(const int argc, const char **argv)
{
    if(argc != 3)
    {
        std::cerr << "Use format: " << argv[0] << " <string 1> <string 2>\n";
        return -1;
    }
    std::string first = argv[1], second = argv[2];
    std::cout << "Comparing " << first << "\nand " << second << "\n\n";
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
    return 0;
}