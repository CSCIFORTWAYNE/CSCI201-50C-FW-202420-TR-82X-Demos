#ifndef CLOCKEXCEPT_H
#define CLOCKEXCEPT_H
#include <stdexcept>

class invalid_AmPmType : public std::invalid_argument
{
public:
    invalid_AmPmType(std::string);
};
class invalid_Hour : public std::invalid_argument
{
public:
    invalid_Hour(std::string);
};

class invalid_Min : public std::invalid_argument
{
public:
    invalid_Min(std::string);
};

class invalid_Sec : public std::invalid_argument
{
public:
    invalid_Sec(std::string);
};
#endif