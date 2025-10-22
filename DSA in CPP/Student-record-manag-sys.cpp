
// Student Record Management System (Beginner – Arrays + Searching + Sorting)
// Concepts used: Arrays, Linear/Binary Search, Bubble/Selection Sort
// Features:
// Add, delete, and update student records
// Sort by name or marks
// Search by roll number
// Display top 3 scorers
// You’ll practice sorting and searching algorithms in a real-world scenario.

#include <iostream>
using namespace std;

int sized = 0;
struct student
{
    int roll;
    string name;
    int marks;
};

void add(student s[])
{
    cout << "Enter name: ";
    cin >> s[sized].name;
    cout << "Enter Roll no: ";
    cin >> s[sized].roll;
    cout << "Enter Marks: ";
    cin >> s[sized].marks;
    sized++;
    cout << "The student is successfully add" << endl;
}
void remove(student s[])
{
    if (sized == 0)
    {
        cout << "No Record Left" << endl;
        return;
    }
    sized--;
    cout << "Last student deleted successfully!" << endl;
}
void sort(student s[])
{
    for (int i = 0; i < sized; i++)
    {
        for (int j = i + 1; j < sized; j++)
        {
            if (s[i].roll > s[j].roll)
            {
                student temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
void update(student s[])
{
    int no;
    cout << "Enter roll no for update";
    cin >> no;
    int low = 0;
    int high = sized - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (s[mid].roll == no)
        {
            cout << "Update the record => " << endl;
            cout << "Enter name: ";
            cin >> s[mid].name;
            cout << "Enter Roll no: ";
            cin >> s[mid].roll;
            cout << "Enter Marks: ";
            cin >> s[mid].marks;
            break;
        }
        if (no < s[mid].roll)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
}
void display(student s[])
{
    if (sized==0)
    {
        cout<<"Record Not found"<<endl;
        return;
    }
    
    for (int i = 0; i < sized; i++)
    {
        cout << "Roll no : " << s[i].roll << endl;
        cout << "Name : " << s[i].name << endl;
        cout << "Marks : " << s[i].marks << endl;
    }
}
int main()
{
    student s[10];
    int n;
    while (true)
    {
        cout << "1.ADD student\n2.Delete student\n3.Update student\n4.Display students\n5.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "***************************Add Student *****************************" << endl;
            add(s);
            break;
        case 2:
            cout << "***************************Remove Student *****************************" << endl;
            remove(s);
            break;
        case 3:
            cout << "***************************Update Student *****************************" << endl;
            update(s);
            break;
        case 4:
            cout << "***************************Display Students *****************************" << endl;
            display(s);
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }

    return 0;
}