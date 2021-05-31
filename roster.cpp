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

        // Used by initStudentObjs() only, could be combined, like the obfuscation
        void populateClassRoasterArray(){
            for (int i = 0; i < 5; i++){
                classRosterArray[i] = &studentData[i];
            }
        }

        //Used by initStudentObjs() only, could be combined, like the obfuscation
        std::string *createSubstring(std::string tempRosterArray){
            static std::string ss[9];
            std::string curWord;
            int i = 0;
            std::istringstream streamString(tempRosterArray);
            while (std::getline(streamString, curWord, ',')){
                ss[i] = curWord;
                i++;
            }
            return ss;
        }

        void printSingleStudent(int i){
            classRosterVector[i].printStudentId();
            std::cout << "\tFirst Name: ";
            classRosterVector[i].printFirstName();
            std::cout << "\tLast Name: ";
            classRosterVector[i].printLastName();
            std::cout << "\tAge: ";
            classRosterVector[i].printAge();
            std::cout << "\tdaysInCourse: ";
            classRosterVector[i].printDaysInCourse();
            std::cout << "\tDegree Program: ";
            classRosterVector[i].printDegreeProgram();
            std::cout << '\n';
        }

        // Used by initStudentObjs() and printByDegreeProgram(). Changes input strings to enum DegreeProgram
        DegreeProgram convertToDegreeType(std::string degreeString){
            std::transform(degreeString.begin(), degreeString.end(), degreeString.begin(), ::toupper);
            if (degreeString == "SECURITY"){
                return DegreeProgram::SECURITY;
            }
            else if (degreeString == "NETWORK"){
                return DegreeProgram::NETWORK;
            }
            else{
                return DegreeProgram::SOFTWARE;
            }
        }

    public:
        void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
            int daysInClassTemp[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
            Student studentObj(studentID, firstName, lastName, emailAddress, age, daysInClassTemp, degreeprogram);
            classRosterVector.push_back(studentObj);
        }

        void remove(std::string studentID){
            int classSize = classRosterVector.size();
            int i = 0;
            std::string curSID = classRosterVector[i].getStudentId();
            while (i < classSize){
                if (curSID == studentID){
                    classRosterVector.erase(classRosterVector.begin() + i);
                    break;
                }
                else{
                    i++;
                }
            }
        }

        void printAll(){
            int classSize = classRosterVector.size();
            int i = 0;
            while (i < classSize){
                printSingleStudent(i);
                i++;
            }
        }

        /*
        void printAverageDaysInCourse(std::string studentID){
            int classSize = classRosterVector.size();
            int i = 0;
            
            std::cout << "Student " << studentID << " has an average of " << dayAve << " in class over three classes.";
        }
        */

        void printInvalidEmails(){
            int classSize = classRosterVector.size();
            int i = 0;
            char first = ' ';
            char second = '.';
            char third = '@';
            while (i < classSize){
                std::string curEmail = classRosterVector[i].getEmail();
                if (curEmail.find(first) == std::string::npos && curEmail.find(second) != std::string::npos && curEmail.find(third) != std::string::npos){
                    std::cout << classRosterVector[i].getStudentId() << " has the valid email: " << classRosterVector[i].getEmail() << '\n';
                    i++;
                }
                else{
                    std::cout << classRosterVector[i].getStudentId() << " has an invalid email." << '\n';
                    i++;
                }
            }
        }

        void printByDegreeProgram(std::string degreeProgramInput){
            DegreeProgram degreeProgram = convertToDegreeType(degreeProgramInput);
            int classSize = classRosterVector.size();
            int i = 0;
            while (i < classSize){
                if (classRosterVector[i].getDegreeProgram() == degreeProgram){
                    printSingleStudent(i);
                    i++;
                }
                else{
                    i++;
                }
            }
        }

        // Init Roster Class object w/ init data.
        void initStudentObjs(){
            populateClassRoasterArray();
            for (int i = 0; i < 5; i++){
                std::string *ss;
                ss = createSubstring(*classRosterArray[i]);
                int age = stoi(ss[4]);
                int daysInClass[3] = {stoi(ss[5]), stoi(ss[6]), stoi(ss[7])};
                DegreeProgram dt = convertToDegreeType(ss[8]);
                Student studentObj(ss[0], ss[1], ss[2], ss[3], age, daysInClass, dt);
                classRosterVector.push_back(studentObj);
            }
        }
};