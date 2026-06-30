#include <iostream>
#include <vector>
#include <string>
using namespace std;

class teacher
{
private: // can't access data out of class
    double salary;

public:
    double *cgpaptr;
    // can access data anywhere
    teacher(){// non-parametric constructor
              cout << "I am costructor"} teacher(string name, string d)
    {                      // parametric constructor
        this->name = name; // this pointer also return an *(this).name
        dept = d;
    }
    // parametric constructor
    teacher(string n, double cgaptr)
    {
        cgpaptr = new double; // dynamically allocation of memory
        *cgpaptr = cgpa;
    }
    // copy constructor
    teacher(teacher &orgobj)
    {
        this->name = orgobj.name;
        this->dept = orgobj.dept;
    }
    // destroctor
    ~teacher()
    {
        cout << "I delete everything\n";
        delete cgpaptr; // deletes the value assign to cgpaptr.
    }
    string name;
    string dept;
    string subject; // object

    // methods/member function
    void changeDept(string newDept)
    {
        dept = newDept;
    }
};

int main()
{
    teacher t1("Aditya", "civil"); // automatically "Aditya","civil" initialised in name and dept resp.
    t1.subject = "c++";
    teacher t2(t1); // default copy constructor ,coping all parameters of t1.
                    // if we initialised copy constructor in class then also we have to write this

    cout << t1.subject; // c++
    cout << t1.dept;    // civil
}
