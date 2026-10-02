#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#define PRE_RELEASE

struct STUDENT_DATA
{
    std::string firstName;
    std::string lastName;
    std::string email;
};

int main()
{
#ifdef PRE_RELEASE
    std::cout << "Running PRE-RELEASE version" << std::endl;
#else
    std::cout << "Running STANDARD version" << std::endl;
#endif

    std::vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    std::ifstream file("StudentData_Emails.txt");
#else
    std::ifstream file("StudentData.txt");
#endif
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
        std::getline(ss, student.firstName, ',');
        std::getline(ss, student.email);

        // drop the space after the comma
        if (!student.firstName.empty() && student.firstName[0] == ' ')
            student.firstName.erase(0, 1);

        students.push_back(student);
    }

    file.close();

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students)
    {
        std::cout << student.firstName << " " << student.lastName;
#ifdef PRE_RELEASE
        std::cout << " - " << student.email;
#endif
        std::cout << std::endl;
    }
#endif

    return 0;
}