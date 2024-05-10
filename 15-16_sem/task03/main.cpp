#include <iostream>

/*
You are tasked with creating a program to manage a database 
of students' information. Each student record consists of the 
following fields: name, age, and grade. You need to implement 
a structure to represent a student record, including various 
overloaded operators for comparison and input/output operations.

In the main program, you should provide functionality to read 
student records from a file, add new records, delete existing 
records, modify records, and display all records. Additionally, 
you should implement the ability to save the updated database 
to a file.

Furthermore, you are required to store the collection of student 
records in a container such as a vector or any other appropriate 
container provided by the Standard Template Library (STL).

Your program should support the following operations:

Reading student records from a file and storing them in the database.
Adding a new student record to the database.
Deleting an existing student record from the database.
Modifying the information of an existing student record.
Displaying all student records.
Saving the updated database to a file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    double grade;

    friend std::istream& operator>>(std::istream& in, Student& student) {
        in >> student.name >> student.age >> student.grade;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade;
        return out;
    }
};

void readRecordsFromFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    Student student;
    while (file >> student) {
        students.push_back(student);
    }
    file.close();
}

void addRecord(std::vector<Student>& students) {
    Student student;
    std::cout << "Enter student name: ";
    std::cin >> student.name;
    std::cout << "Enter student age: ";
    std::cin >> student.age;
    std::cout << "Enter student grade: ";
    std::cin >> student.grade;
    students.push_back(student);
}

void deleteRecord(std::vector<Student>& students, int index) {
    if (index >= 0 && index < students.size()) {
        students.erase(students.begin() + index);
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void displayRecords(const std::vector<Student>& students) {
    for (const Student& student : students) {
        std::cout << student << std::endl;
    }
}

void writeRecordsToFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    for (const Student& student : students) {
        file << student.name << " " << student.age << " " << student.grade << std::endl;
    }
    file.close();
}

int main() {
    std::vector<Student> students;

    readRecordsFromFile("students.txt", students);

    addRecord(students);
    deleteRecord(students, 1);
    displayRecords(students);

    writeRecordsToFile("updated_students.txt", students);

    return 0;
}