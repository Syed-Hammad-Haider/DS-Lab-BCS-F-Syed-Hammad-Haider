/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor
and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

#include <iostream>
#include <string>
using namespace std;

class Exam {
public:
    string stdName;
    string examDate;
    int *score;

    Exam(string name, string date, int sc) {
        stdName = name;
        examDate = date;
        score = new int(sc);
    }
    ~Exam() {
        delete score;
    }
    void display() {
        cout<<"Student: "<<stdName<<endl;
        cout<<"Date: "<<examDate<<endl;
        cout<<"Score: "<<*score<<endl;
    }
};

int main() {
Exam exam1("Hammad", "2025-08-24", 82);
cout << "Original Object (exam1):" << endl;
exam1.display();
Exam exam2 = exam1;
cout << "Copied Object (exam2):" << endl;
exam2.display();
}
