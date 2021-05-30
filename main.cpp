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
                    "1. Print all\n" << "2. Print Email\n" << "3. Print by degree\n" << "0. Exit\n";

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
                classRoster.printByDegreeProgram(classRoster.convertToDegreeType(in));
                break;
            /*
            case 4:
                //
                break;
            case 5:
                //
                break;
            */
            case 0:
                return 0;
        }

    }
    


}