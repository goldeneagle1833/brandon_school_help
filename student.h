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
            for(int i = 0; i < 3; i++){
                daysString.append(std::to_string(daysInCourse[i]));
                daysString.append(", ");}
            daysString.append("}");
            return daysString;
        }
        DegreeProgram getDegreeProgram(){return degree;}

        // Constructor
        Student(std::string sId, std::string fn, std::string ln, std::string em, int a, int *dc[3], DegreeProgram dp){
            setStudentId(sId);
            setFirstName(fn);
            setLastName(ln);
            setEmail(em);
            setAge(a);
            setDaysInCourse(*dc);
            setDegreeProgram(dp);
        }

        // Print statement
};