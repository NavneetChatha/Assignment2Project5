#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct STUDENT_DATA
{
    std::string firstName;
    std::string lastName;
};

int main()
{
    std::vector<STUDENT_DATA> students;

    std::ifstream file("StudentData.txt");
    if (!file.is_open())
    {
        std::cout << "Could not open StudentData.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        STUDENT_DATA student;

        std::getline(ss, student.lastName, ',');
        std::getline(ss, student.firstName);

        // drop the space after the comma
        if (!student.firstName.empty() && student.firstName[0] == ' ')
            student.firstName.erase(0, 1);

        students.push_back(student);
    }

    file.close();
    return 0;
}