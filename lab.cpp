#include <iostream>
#include <string>

enum class string_type {number, id, incorrect};

string_type analyze_string(std::string s_in) {
    std::string numbers{"0123456789"};
    std::string sp_symbols{"!@#$%^&*.,/-?:;()+-"};
    string_type str_type;

    if(numbers.find(s_in[0]) != std::string::npos || s_in[0] == '-')
        str_type = string_type::number;
    else if(sp_symbols.find(s_in[0]) != std::string::npos)
        str_type = string_type::incorrect;
    else
        str_type = string_type::id;

    bool dot_found{false};
    switch(str_type)
    {
        case string_type::number:
            for(int i {1}; i < s_in.length(); i++) {
                if(s_in[i] == '.') {
                    if(dot_found) {
                        str_type = string_type::incorrect;
                        break;
                    }
                    else dot_found = true;
                }
                else if(numbers.find(s_in[i]) == std::string::npos) {
                    str_type = string_type::incorrect;
                    break;
                }
            }
            break;
        case string_type::id:
            for(int i {1}; i < s_in.length(); i++) {
                if(sp_symbols.find(s_in[i]) != std::string::npos) {
                    str_type = string_type::incorrect;
                    break;
                }
            }
            break;
        case string_type::incorrect:
        default:
            break;
    }

    return str_type;
}

int main() {
    std::cout << "Enter the line: ";
    std::string s_in;
    std::cin >> s_in;
    string_type str_type {analyze_string(s_in)};

    switch(str_type)
    {
        case string_type::number:
            std::cout << "It is number" << std::endl;
            break;
        case string_type::id:
            std::cout << "It is id" << std::endl;
            break;
        case string_type::incorrect:
        default:
            std::cout << "Incorrect input" << std::endl;
            break;
    }

    return 0;
}
