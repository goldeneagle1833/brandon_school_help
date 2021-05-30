#include <algorithm>
#include <cstring>
#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include <vector>
#include "roster.h"
#include "student.cpp"

class Roster{
    private:
        const std::string *classRosterArray[5];
        std::vector<Student> classRosterVector;

        void populateClassRoasterArray(){for(int i = 0; i < 5; i++){
            classRosterArray[i] = &studentData[i];}
        }

        std::string createSubstring(std::string tempRosterArray){
            std::string ss[9];
            int i = 0;
            std::stringstream tempString(tempRosterArray);
            while(tempString.good() && i < 9){
                tempString >> ss[i];
                i++;
            }
            return *ss;
        }

        void printSingleStudent(int i){
            const std::string enum_string[3] = {"Security", "Network", "Software"};
            std::string dp;

            if(classRosterVector[i].getDegreeProgram() == SECURITY){
                    dp = enum_string[0];
                    i++;}
                else if(classRosterVector[i].getDegreeProgram() == NETWORK){
                    dp = enum_string[1];
                    i++;}
                else if(classRosterVector[i].getDegreeProgram() == SOFTWARE){
                    dp = enum_string[2];
                    i++;}
            std::cout << classRosterVector[i].getStudentId() << "\tFirst Name: " << classRosterVector[i].getFirstName() << "\tLast Name: " <<
            classRosterVector[i].getLastName() << "\tAge: " << classRosterVector[i].getAge() << "\tdatsInCourse: " << classRosterVector[i].getDaysInCourse()  << "\tDegree Program: " <<
            dp << '\n';
        }

    public:
        void initStudentObjs(){
            populateClassRoasterArray();
            for(int i = 0; i < 5; i++){
                std::string ss;
                ss = createSubstring(*classRosterArray[i]);

                int daysInClassTemp[3] = {ss[5], ss[6], ss[7]};
                int *daysInClass[3] = {&daysInClassTemp[0], &daysInClassTemp[1], &daysInClassTemp[2]};
                DegreeProgram dt = convertToDegreeType(&ss[8]);

                Student studentObj(&ss[0], &ss[1], &ss[2], &ss[3], ss[4], daysInClass, dt);
                classRosterVector.push_back(studentObj);}
        }

        DegreeProgram convertToDegreeType(std::string degreeString){
            std::transform(degreeString.begin(), degreeString.end(), degreeString.begin(), ::toupper);
            if(degreeString == "SECURITY"){return DegreeProgram::SECURITY;}
            else if(degreeString == "NETWORK"){return DegreeProgram::NETWORK;}
            else {return DegreeProgram::SOFTWARE;}
        }

        void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
            int *daysInClassTemp[3] = {&daysInCourse1, &daysInCourse2, &daysInCourse3};
            Student studentObj(studentID, firstName, lastName, emailAddress, age, daysInClassTemp, degreeprogram);
            classRosterVector.push_back(studentObj);
        }

        void remove(std::string studentID){
            int classSize = classRosterVector.size();
            int i = 0;
            std::string curSID = classRosterVector[i].getStudentId();
            while(i < classSize){
                if(curSID == studentID){
                    classRosterVector.erase(classRosterVector.begin()+i);
                    break;}
            }
        }

        void printAll(){
            int classSize = classRosterVector.size();
            int i = 0;
            while(i < classSize){
                printSingleStudent(i);
                i++;
            }
        }

        void printAverageDaysInCourse(std::string studentID){
            int classSize = classRosterVector.size();
            int i = 0;
            std::string dayString;
            std::string curSID = classRosterVector[i].getStudentId();
            int daySum;
            float dayAve = 0.0;

            while(i < classSize){
                if(curSID == studentID){
                    dayString = classRosterVector[i].getDaysInCourse();
                    break;}
                else{
                    i++;}
            }
            int len = dayString.length();
            char charArray[len + 1];
            strcpy(charArray, dayString.c_str());
            i = 0;
            int j = 0;
            while(i < len && j < 3){
                if(isdigit(charArray[i])){
                    daySum += charArray[i];
                    i++;
                    j++;}
                else{
                    i++;}
            }
            dayAve = daySum / 3;
            std::cout << "Student " << studentID << " has an average of " << dayAve << " in class over three classes.";
        }

        void printInvalidEmails(){
            int classSize = classRosterVector.size();
            int i = 0;
            char first = ' ';
            char second = '.';
            char third = '@';
            while(i < classSize){
                std::string curEmail = classRosterVector[i].getEmail();
                if(curEmail.find(first) == std::string::npos && curEmail.find(second) != std::string::npos && curEmail.find(third) != std::string::npos){
                    std::cout << classRosterVector[i].getStudentId() << "has the valid email: " << classRosterVector[i].getEmail();
                    i++;}
                else{
                    std::cout << classRosterVector[i].getStudentId() << "has an invalid email.";
                    i++;}
            }
        }

        void printByDegreeProgram(DegreeProgram degreeProgram){
            int classSize = classRosterVector.size();
            int i = 0;
            while(i < classSize){
                if(classRosterVector[i].getDegreeProgram() == degreeProgram){
                    printSingleStudent(i);
                    i++;}
                else{
                    i++;}
            }

        }
};


/*
            setStudentId(sId);
            setFirstName(fn);
            setLastName(ln);
            setEmail(em);
            setAge(a);
            setDaysInCourse(dc);
            setDegreeProgram(dp);

            SECURITY, NETWORK, SOFTWARE
*/