#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;
};

class EmployeeManager {
private:
    fstream file;
    string filename;

public:
    EmployeeManager(const string& filename) : filename(filename) {}

    void openFile() {
        file.open(filename, ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            file.open(filename, ios::out | ios::binary);
            file.close();
            file.open(filename, ios::in | ios::out | ios::binary);
        }
    }

    void closeFile() {
        file.close();
    }

    void addEmployee(const Employee& emp) {
        file.seekp(0, ios::end);
        file.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
    }

    void deleteEmployee(int empID) {
        Employee emp;
        int pos = -1;
        while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
            if (emp.employeeID == empID) {
                pos = file.tellg();
                break;
            }
        }
        if (pos != -1) {
            file.seekp(pos - sizeof(Employee));
            Employee emptyEmp;
            file.write(reinterpret_cast<const char*>(&emptyEmp), sizeof(Employee));
            cout << "Employee with ID " << empID << " deleted successfully." << endl;
        } else {
            cout << "Employee with ID " << empID << " not found." << endl;
        }
    }

    void displayEmployee(int empID) {
        Employee emp;
        bool found = false;
        file.clear();
        file.seekg(0, ios::beg);
        while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
            if (emp.employeeID == empID) {
                found = true;
                cout << "Employee ID: " << emp.employeeID << endl;
                cout << "Name: " << emp.name << endl;
                cout << "Designation: " << emp.designation << endl;
                cout << "Salary: $" << fixed << setprecision(2) << emp.salary << endl;
                break;
            }
        }
        if (!found) {
            cout << "Employee with ID " << empID << " not found." << endl;
        }
    }
};

int main() {
    EmployeeManager empManager("employees.dat");
    empManager.openFile();

    int choice;
    do {
        cout << "1. Add Employee\n2. Delete Employee\n3. Display Employee\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee emp;
                cout << "Enter Employee ID: ";
                cin >> emp.employeeID;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, emp.name);
                cout << "Enter Designation: ";
                getline(cin, emp.designation);
                cout << "Enter Salary: ";
                cin >> emp.salary;
                empManager.addEmployee(emp);
                break;
            }
            case 2: {
                int empID;
                cout << "Enter Employee ID to delete: ";
                cin >> empID;
                empManager.deleteEmployee(empID);
                break;
            }
            case 3: {
                int empID;
                cout << "Enter Employee ID to display: ";
                cin >> empID;
                empManager.displayEmployee(empID);
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    empManager.closeFile();

    return 0;
}
