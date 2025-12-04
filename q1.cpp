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
};

int main() {
    vector< MemoryCalculate<int, string> > students;

    students.push_back( MemoryCalculate<int, string>(1, "Preet") );
    students.push_back( MemoryCalculate<int, string>(2, "smit") );
    students.push_back( MemoryCalculate<int, string>(3, "yash") );


    for (auto &s : students) {
        s.display();
    }

    return 0;
}
