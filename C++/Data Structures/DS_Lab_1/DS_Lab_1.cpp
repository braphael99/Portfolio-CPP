// DS_Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void getName(string* p_name);
void getGrade(double* p_grade);
double getAverage(double** grades, int numGrades);

int main()
{
    string studentName;

    getName(&studentName);

    double grade1;
    double grade2;
    double grade3;

    getGrade(&grade1);
    getGrade(&grade2);
    getGrade(&grade3);

    double* grades[3] = { &grade1, &grade2, &grade3 };

    getAverage(grades, 3);


    return 0;
}

void getName(string* p_name) {

    cout << "Enter a student name: ";
    cin >> *p_name;

    cout << "\n\nStudent name is " << *p_name << "\n";
}

void getGrade(double* p_grade) {

    cout << "\nEnter a grade: ";
    cin >> *p_grade;

}

double getAverage(double** grades, int numGrades) {

    double sum = 0.0;
    for (int i = 0; i < numGrades; i++) {

        sum += *(grades[i]);

    }

    return sum / numGrades;

}