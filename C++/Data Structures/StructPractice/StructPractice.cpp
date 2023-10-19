// StructPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Dog {

    string name;
    int age;
    float weight;

};

void fillDog(Dog& dog);
void printDog(const Dog& dog);

int main()
{

    Dog d1;
    Dog d2;

    fillDog(d1);
    fillDog(d2);

    printDog(d1);
    printDog(d2);

}

void fillDog(Dog& dog) {

    cout << "Enter the dogs name: \n";
    cin >> dog.name;

    cout << "Enter the dog's age: \n";
    cin >> dog.age;

    cout << "Enter the dog's weight: \n";
    cin >> dog.weight;

}
void printDog(const Dog& dog) {

    cout << "Dog's name is " << dog.name << "\n";
    cout << "Dog's age is " << dog.age << "\n";
    cout << "Dog's weight is " << dog.weight << "\n";

}