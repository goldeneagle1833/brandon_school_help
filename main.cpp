#include <iostream>
#include <string>
#include "roster.cpp"

int main(){
    std::cout << "Scripting and Programming- Applications– C867, C++, #001459799, Brandon M Burky";

    Roster classRoster;
    classRoster.initStudentObjs();

    //Runtime Test Code:
    std::string in;
    int i = 0;
    while(true){
        std::cout << "What would you like to do?\n" <<
                    "1. Print all\n" << "2. Print Email\n" << "3. Print by degree\n" << "4. Print studentData\n" << "5. Print Average days in course by ID\n" << "0. Exit\n";

        std::cin >> i;
        switch(i){
            case 1:
                classRoster.printAll();
                break;
            case 2:
                classRoster.printInvalidEmails();
                break;
            case 3:
                std::cout << "What degree type?";
                std::cin >> in;
                classRoster.printByDegreeProgram(in);
                break;
            
            case 4:
                std::cout << *&studentData[0] << "\n";
                std::cout << *&studentData[1] << "\n";
                std::cout << *&studentData[2] << "\n";
                std::cout << *&studentData[3] << "\n";
                std::cout << *&studentData[4] << "\n";
                break;
            case 5:
                std::cout << "What Student ID?";
                std::cin >> in;
                //classRoster.printAverageDaysInCourse(in);
                break;
            case 0:
                return 0;
        }

    }
    


}