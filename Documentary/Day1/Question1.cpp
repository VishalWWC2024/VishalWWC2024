#include <iostream>
using namespace std;

int main() {
    // Biodata information
    string name = "Vishal Sah";
    string uid = "22BCS16978";
    string section = "BE-CSE-A";
    string interest = "Data Science";
    int age = 21;
    float cgpa = 7.1;
    string dob = "06-11-2003";
    string hometown = "Uttarakhand";

    // Display biodata
    cout << "==================== Academic Bio Data ====================\n";
    cout << "Name            : " << name << endl;
    cout << "UID             : " << uid << endl;
    cout << "Section         : " << section << endl;
    cout << "Area of Interest: " << interest << endl;
    cout << "Age             : " << age << endl;
    cout << "Last Year CGPA  : " << cgpa << endl;
    cout << "Date of Birth   : " << dob << endl;
    cout << "Hometown        : " << hometown << endl;
    cout << "==========================================================\n";

    return 0;
}
