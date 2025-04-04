#include <iostream>
using namespace std;

class Studentaccount {
    private:
    string name;
    int id;
    int registeredcredit;
    float tuitionpercredit;
    float totalfee;
    public:
    Studentaccount() {
        name = "";
        id = 0;
        registeredcredit = 0;
        tuitionpercredit = 200;
        totalfee = 0;
    }
    void setInfo(string n, int i) {
        this -> name = n;
        this -> id = i;
    }
    int addcredits(int credits) {
        registeredcredit += credits;
    }
    double calculatefee() {
        totalfee += tuitionpercredit * registeredcredit;
    }
    double gettotalfee() {
        return totalfee;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Registered credits: " << registeredcredit << endl;
        cout << "Tuition percredit: " << tuitionpercredit << endl;
        cout << "Total fee: " << totalfee << endl;
    }
};

class Course {
private:
    string courseNames[5];
    int creditHours[5];

public:
    Course() {
        courseNames[0] = "Calculus";
        creditHours[0] = 3;

        courseNames[1] = "Physics";
        creditHours[1] = 4;

        courseNames[2] = "Statistics";
        creditHours[2] = 2;

        courseNames[3] = "Programming";
        creditHours[3] = 3;

        courseNames[4] = "Ideology";
        creditHours[4] = 3;
    }
    void display() {
        for (int i = 0; i < 5; i++) {
            cout << courseNames[i] << endl;
            cout << creditHours[i] << endl;
        }
    }
    int getcredit(int coursetype) {
        return creditHours[coursetype];
    }
};

class Registration {
    public:
    void registercourse(Studentaccount &student,Course & courselist,int coursetype) {
        int credits = courselist.getcredit(coursetype);
        student.addcredits(credits);
        cout << "Course registered successfully! Added " << credits << " credit hours";
    }
};

int main() {
    Studentaccount student;
    Course courseList;
    Registration reg;

    string name;
    int id;
    int choice;

    cout << "=== Course Registration System ===\n";
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student ID: ";
    cin >> id;
    student.setInfo(name, id);

    cout << "\nMenu:\n";
    cout << "1. View Available Courses\n";
    cout << "2. Register for a Course\n";
    cout << "3. View Total Fee\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. View Available Courses\n";
        cout << "2. Register for a Course\n";
        cout << "3. View Total Fee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            courseList.display();
        } else if (choice == 2) {
            int courseIndex;
            courseList.display();
            cout << "Enter course number to register (0-4): ";
            cin >> courseIndex;
            reg.registercourse(student, courseList, courseIndex);
        } else if (choice == 3) {
            student.calculatefee();
            student.display();
        } else if (choice == 4) {
            cout << "Thank you! Exiting...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);


    

    return 0;
}
