#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[50];
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll << " Name: " << name << " Marks: " << marks << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);
    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();
    cout << "Student added successfully!\n";
}

void viewStudents() {
    Student s;
    ifstream file("students.txt");
    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }
    file.close();
}

void searchStudent() {
    Student s;
    int r;
    cout << "Enter Roll Number to search: ";
    cin >> r;
    ifstream file("students.txt");
    while (file.read((char*)&s, sizeof(s))) {
        if (s.roll == r) {
            cout << "Record Found:\n";
            s.display();
            file.close();
            return;
        }
    }
    cout << "Record not found!\n";
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Search Student\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}