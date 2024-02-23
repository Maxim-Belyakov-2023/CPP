#pragma once
#include <string>
#include<exception>

class out_of_range_error : public std::exception
{
public:
    out_of_range_error(const std::string& message): message{message}{}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};
