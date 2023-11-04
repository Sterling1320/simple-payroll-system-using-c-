#include <iostream>
#include <vector>
using namespace std;
// Define a struct to represent an employee
struct Employee
{
    string name;
    int EmployeeId;
    double DailyWage;
    int DaysWorked;
};

// Function to calculate the salary of an employee
double calculateSalary(const Employee &emp)
{
    double baseSalary = emp.DailyWage * emp.DaysWorked;
    // Add logic for calculating overtime, deductions, and benefits here.
    return baseSalary;
}

int main()
{
    int choice;
    vector<Employee> employees;
    Employee emp;
    cout << "\nYou have started the payroll system" << endl;
    do
    {
        cout << "\n"<< endl;
        cout << "What would you like to perform-" << endl;
        cout << "1. Enter New Employee Record" << endl;
        cout << "2. Compute Salary Of All employees " << endl;
        cout << "3. Edit Record" << endl;
        cout << "4. List All Employees" << endl;
        cout << "5. Exit" << endl;
        cout<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter EmployeeID:" << endl;
            cin >> emp.EmployeeId;
            cout << "Enter Full Name of New Employee (First and Last Name):" << endl;
            cin.ignore(); 
            getline(cin, emp.name);
            cout << "Enter Daily Wage Amount:" << endl;
            cin >> emp.DailyWage;
            cout << "Number of Days Worked:" << endl;
            cin >> emp.DaysWorked;
            employees.push_back(emp);
            cout << "\nRecord Inserted Successfully!" << endl;
            break;
        case 2:
            if (employees.empty())
            {
                cout << "\nNo employee records found. Please add records To compute salary" << endl;
            }
            else
            {
                cout<<"\n";
                for (const Employee &emp : employees)
                {
                    double salary = calculateSalary(emp);
                    cout << "Name: " << emp.name << ", EmployeeID: " << emp.EmployeeId << ", Salary: Rs." << salary << endl;
                }
            }
            cout << "Total Employees- " << employees.size() << endl;
            break;
        case 3:
            if (employees.empty())
            {
                cout << "\nNo employee records found. Please add records before editing." << endl;
            }
            else
            {
                cout << "\nSelect an employee to edit:" << endl;
                for (size_t i = 0; i < employees.size(); ++i)
                {
                    cout << i + 1 << ". " << employees[i].name << " (ID: " << i + 1 << ")" << endl;
                }

                int editIndex;
                cout << "\nEnter the ID of the employee record you want to edit: ";
                cin >> editIndex;

                if (editIndex >= 1 && editIndex <= static_cast<int>(employees.size()))
                {
                    // Adjust for 1-based indexing
                    editIndex--;

                    cout << "\nWhat would you like to edit for " << employees[editIndex].name << "?" << endl;
                    cout << "\n1. Name" << endl;
                    cout << "2. Daily Wage" << endl;
                    cout << "3. Days Worked" << endl;
                    int editChoice;
                    cin >> editChoice;

                    switch (editChoice)
                    {
                    case 1:
                        cout << "\nEnter the new name: "<<endl;
                        cin.ignore();
                        getline(cin, employees[editIndex].name);
                        cout << "\nName updated successfully!" << endl;
                        break;
                    case 2:
                        cout << "\nEnter the new daily wage: "<<endl;
                        cin >> employees[editIndex].DailyWage;
                        cout << "Daily wage updated successfully!" << endl;
                        break;
                    case 3:
                        cout << "\nEnter the new number of days worked: "<<endl;
                        cin >> employees[editIndex].DaysWorked;
                        cout << "Days worked updated successfully!" << endl;
                        break;
                    default:
                        cout << "\nInvalid choice for editing." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "\nInvalid employee ID. Please enter a valid ID." << endl;
                }
            }
            break;
        case 4:
            if (employees.empty())
            {
                cout << "No employee records found. Kindly Add records first" << endl;
            }
            else
            {
                cout << "\nHere is the list of all Employees:" << endl;
                cout<<"\n";
                for (size_t i = 0; i < employees.size(); ++i)
                {
                    cout << i + 1 << ". " << employees[i].name << " (ID: " << i + 1 << ")" << endl;
                }
            }
            cout << "Total Employees- " << employees.size() << endl;
            break;
        case 5:
            cout << "\nExited Successfully!" << endl;
            break;
        default:
            cout << "Invalid Input! Please Choose the right option" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
