#ifndef PERSON_H
#define PERSON_H
#include <string>
enum raceType
{
    NATIVE,
    ISLANDER,
    HISPANIC,
    WHITE,
    ASIAN,
    BLACK,
    OTHER
};
const int NUM_RACES = 7;
const raceType races[] = {NATIVE,
                          ISLANDER,
                          HISPANIC,
                          WHITE,
                          ASIAN,
                          BLACK,
                          OTHER};
const std::string raceToStr[] = {"Native American",
                                 "Pacific Islander",
                                 "Hispanic",
                                 "White",
                                 "Asian",
                                 "Black",
                                 "Other"};
class person
{
public:
    person(std::string first_name, std::string last_name, int a, raceType r, double h, double w, std::string hair, std::string eye, char middle = '\0');
    std::string getName();
    std::string getFName();
    std::string getLName();
    std::string getMI();
    int getAge();
    std::string getRace();
    double getHeight();
    double getWeight();
    std::string getHairColor();
    std::string getEyeColor();
    void setName(std::string fn, std::string ln, char m = '\0');
    void setFName(std::string);
    void setLName(std::string);
    void setMI(char);
    void incrementAge(int);
    void setHeight(double);
    void setWeight(double);
    void setHairColor(std::string);
    std::string tostring();

protected:
    std::string fname;
    std::string lname;
    char mi;
    int age;
    raceType race;
    double height;
    double weight;
    std::string hairColor;
    std::string eyeColor;
};

class employee : public person
{
public:
    employee(std::string first_name, std::string last_name, int a, raceType r, double h, double w, std::string hair, std::string eye, std::string hire, double sal, unsigned int id, std::string pos, bool hour, char middle = '\0');
    std::string getHireDate();
    double getSalary();
    int getEmpID();
    std::string getPosition();
    bool isHourly();
    void setSalary(double salary);
    void setPosition(std::string pos);
    void setHourly(bool);
    std::string tostring();

private:
    std::string hireDate;
    double salary;
    unsigned int empID;
    std::string position;
    bool hourly;
};

class student : public person
{
    private:
        bool vaccinationStatusUpToDate;        //social determinents of health
        bool stableHomeAddress;
    
public:
    student(double GPA, std::string major, course schedule, bool vaccinationStatusUpToDate, bool stableHomeAddress);
    double GPA;
    std::string major;
    course schedule;

    int getVaccinationStatusUpToDate(){
        return VaccinationStatusUpToDate;}

    int getstableHomeAddresst(){
        return stableHomeAddress;}

    void setVaccinationStatusUpToDate(){
        this->VaccinationStatusUpToDate = VaccinationStatusUpToDate;}

    void setstableHomeAddress(){
        this->stableHomeAddress = stableHomeAddress;}
};

class course
{
    std::string dept;
    int courseNum;
    std::string section;
    int semester;
    int creditHours;
    char grade;
};

#endif
