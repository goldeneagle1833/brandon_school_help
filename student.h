#include <iostream>
#include <string>
#include "degree.h"

class Student{
    private:
        std::string studentId; // set const in setter, all other vars could change, though that is not implemented
        std::string firstName;
        std::string lastName;
        std::string email;
        int age;
        int daysInCourse[3];
        DegreeProgram degree;

    public:
        // Setters
        void setStudentId(const std::string sId){studentId = sId;}
        void setFirstName(std::string fn){firstName = fn;}
        void setLastName(std::string ln){lastName = ln;}
        void setEmail(std::string em){email = em;}
        void setAge(int a){age = a;}
        void setDaysInCourse(int di[3]){for(int i = 0; i < 3; i++){
            daysInCourse[i] = di[i];}
        }
        void setDegreeProgram(DegreeProgram d){degree = d;}

        // Getters
        std::string getStudentId(){return studentId;}
        std::string getFirstName(){return firstName;}
        std::string getLastName(){return lastName;}
        std::string getEmail(){return email;}
        int getAge(){return age; }
        std::string getDaysInCourse(){
            std::string daysString = "{";
            daysString.append(std::to_string(daysInCourse[0]));
            for(int i = 1; i < 3; i++){
                daysString.append(", ");
                daysString.append(std::to_string(daysInCourse[i]));}
            daysString.append("}");
            return daysString;
        }
        DegreeProgram getDegreeProgram(){return degree;}

        // Print statement. Not needed, but added to satisfy the PA
        void printStudentId(){std::cout << studentId;}
        void printFirstName(){std::cout << firstName;}
        void printLastName(){std::cout << lastName;}
        void printEmail(){std::cout << email;}
        void printAge(){std::cout << age;}
        void printDaysInCourse(){
            std::string days = getDaysInCourse();
            std::cout << days;}
        void printDegreeProgram(){
            const std::string enum_string[3] = {"Security", "Network", "Software"};
            std::string dp;
            if (getDegreeProgram() == SECURITY){
                dp = enum_string[0];}
            else if (getDegreeProgram() == NETWORK){
                dp = enum_string[1];}
            else if (getDegreeProgram() == SOFTWARE){
                dp = enum_string[2];}
            std::cout << dp;
        }

        // Constructor
        Student(std::string sId, std::string fn, std::string ln, std::string em, int a, int dc[3], DegreeProgram dp){
            setStudentId(sId);
            setFirstName(fn);
            setLastName(ln);
            setEmail(em);
            setAge(a);
            setDaysInCourse(dc);
            setDegreeProgram(dp);
        }
};