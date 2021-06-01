#include <iostream>
#include <string>
#include "roster.cpp"

int main(){
    // F.1
    std::cout << "F.1: Scripting and Programming- Applications– C867, C++, #001459799, Brandon M Burky\n\n";
    // F.2 & F.3
    Roster *classRoster = new Roster;
    // F.4 -- Extra 'cout << "\n"'s are to help make this easier to follow in output.
    std::cout << "F.4:\n";
    classRoster -> printAll();
    std::cout << '\n';
    classRoster -> printInvalidEmails();
    std::cout << '\n';
    for(int i = 0; i < classRoster -> classRosterVector.size(); i++){
        classRoster -> printAverageDaysInCourse(classRoster -> classRosterVector[i].getStudentId());
    }
    std::cout << '\n';
    classRoster -> printByDegreeProgram(SOFTWARE);
    std::cout << '\n';
    classRoster -> remove("A3");
    std::cout << '\n';
    classRoster -> printAll();
    std::cout << '\n';
    classRoster -> remove("A3");
    std::cout << '\n';
    // F.5
    std::cout << "F.5:\n";
    delete classRoster;
    std::cout << "\"classRoster\" object destructed.\n";
}