#pragma once
#include <string>
#include<exception>


class incorrect_dimension_error : public std::exception
{
public:
    incorrect_dimension_error(const std::string& message): message{message}{}
    const char* what() const noexcept override
{
    return message.c_str();
}
private:
    std::string message;
    
};
