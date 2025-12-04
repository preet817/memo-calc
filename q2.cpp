#include <iostream>
#include <vector>
using namespace std;

template <class T, class U>
class MemoryCalculate {
private:
    T id;
    U name;

public:

    MemoryCalculate(T id, U name) {
        this->id = id;
        this->name = name;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    T getId() { return id; }
    U getName() { return name; }
};

int main() {
    vector< MemoryCalculate<int, string> > students;
    int choice;

    while (true) {
        cout << "\n= Student Management Using Template & Vector =\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;

            students.push_back( MemoryCalculate<int, string>(id, name) );
            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            cout << "\n---- All Students ----\n";
            if (students.empty())
                cout << "No students found.\n";
            else
                for (auto &s : students)
                    s.display();
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to Remove: ";
            cin >> id;

            bool found = false;
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->getId() == id) {
                    students.erase(it);
                    cout << "Student Removed Successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student with ID " << id << " not found.\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to Search: ";
            cin >> id;

            bool found = false;
            for (auto &s : students) {
                if (s.getId() == id) {
                    cout << "Student Found:\n";
                    s.display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Student with ID " << id << " not found.\n";
        }

        else if (choice == 5) {
            cout << "Exiting Program...\n";
            break;
        }

        else {
            cout << "Invalid Choice. Try Again.\n";
        }
    }

    return 0;
}
