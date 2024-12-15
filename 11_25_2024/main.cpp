#include "clock.h"
#include <iostream>
#include <limits>

clockFormatType getFormat();
std::string getTimeOfDay();
int getHour(clockFormatType f);
int getMinOrSec();
void codeGradeLoopFix(std::string errLocation);
void resetStream();
// create two new exception classes invalid_Min and invalid_Sec
// add code to setTime in the clock class to detect invalid minutes and invalid seconds and throw the error
// add catch blocks to the main to catch the new errors.

int main()
{
    int hr = 0;
    int min = 0;
    int sec = 0;
    clockFormatType format;
    std::string tod;
    clockType *clock;
    bool validHr = false;
    bool validMin = false;
    bool validSec = false;
    bool validTod = false;
    bool validFormat = false;
    while (true)
    {
        try
        {
            if (!validFormat)
            {
                format = getFormat();
                validFormat = true;
            }
            if (!validHr)
            {
                hr = getHour(format);
                validHr = true;
            }
            if (!validMin)
            {
                std::cout << "Enter the clock's minutes: ";
                min = getMinOrSec();
                validMin = true;
            }
            if (!validSec)
            {
                std::cout << "Enter the clock's seconds: ";
                sec = getMinOrSec();
                validSec = true;
            }
            if (format == TWELVE)
            {
                if (!validTod)
                {
                    tod = getTimeOfDay();
                    validTod = true;
                }
                clock = new clockType(hr, min, sec, tod, format);
            }
            else
            {
                clock = new clockType(hr, min, sec);
            }
            std::cout << *clock << std::endl;
            break;
        }
        catch (invalid_AmPmType e)
        {
            std::cout << e.what() << std::endl;
            validTod = false;
            continue;
        }
        catch (invalid_Hour e)
        {
            std::cout << e.what() << std::endl;
            validHr = false;
            continue;
        }
        catch (invalid_Min e)
        {
            std::cout << e.what() << std::endl;
            validMin = false;
            continue;
        }
        catch (invalid_Sec e)
        {
            std::cout << e.what() << std::endl;
            validSec = false;
            continue;
        }
        /* catch (...)
        {
            std::cout << "An error has occured. Program will exit." << std::endl;
            return 0;
        } */
    }
    return 0;
}

clockFormatType getFormat()
{
    return TWELVE;
}

std::string getTimeOfDay()
{
    std::string tod;
    std::cout << "Is it AM or PM?" << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, tod);

    std::transform(tod.begin(), tod.end(), tod.begin(), ::tolower);
    // std::cout << tod << std::endl;
    if (!clockType::strToAmPmType.count(tod))
    {
        codeGradeLoopFix("getTimeOfDay function");

        throw invalid_AmPmType(tod);
    }
    return tod;
}

int getHour(clockFormatType f)
{
    int hr;
    std::cout << "Enter the clock's hour: ";
    std::cin >> hr;
    if (!std::cin)
    {
        resetStream();
        if (f == TWELVE)
        {
            throw invalid_Hour("The hour must be between 1 and 12. ");
        }
        else
        {
            throw invalid_Hour("The hour must be between 0 and 23. ");
        }
    }

    return hr;
}

int getMinOrSec()
{
    int num;
    std::cin >> num;
    while (!std::cin || num < 0 || num > 59)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please enter a number between 0 and 59: ";
        std::cin >> num;
    }
    return num;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        throw std::runtime_error("Out of input " + errLocation);
    }
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
