{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <fstream>\
#include <sstream>\
#include <vector>\
#include <string>\
\
using namespace std;\
\
struct Student \{\
    string name;\
    int rollno;\
    string address;\
    int div;\
\};\
\
class StudentData \{\
public:\
    Student record;\
    int num_students = 0;\
\
    void newFile();\
    void clearFile();\
    void modify();\
    void display();\
    void deleteRecord();\
    void add();\
    void search();\
\};\
\
void StudentData::newFile() \{\
    ofstream obj("studentDatabase.txt");\
    if (!obj) \{\
        cerr << "ERROR in creating new file" << endl;\
        return;\
    \}\
    obj << "RollNo\\tName\\tDivision\\tAddress\\n";\
    obj.close();\
    cout << "New file created successfully." << endl;\
\}\
\
void StudentData::add() \{\
    ofstream obj("studentDatabase.txt", ios::app);\
    if (!obj) \{\
        cerr << "ERROR in opening file for appending" << endl;\
        return;\
    \}\
\
    cout << "Enter Record " << num_students + 1 << ":\\n";\
    cout << "Roll No: ";\
    cin >> record.rollno;\
    cin.ignore();\
    cout << "Name: ";\
    getline(cin, record.name);\
    cout << "Division: ";\
    cin >> record.div;\
    cin.ignore();\
    cout << "Address: ";\
    getline(cin, record.address);\
\
    num_students++;\
    obj << record.rollno << "\\t" << record.name << "\\t" << record.div << "\\t" << record.address << "\\n";\
    obj.close();\
\
    cout << "\\nNew record appended successfully.\\n";\
\}\
\
void StudentData::clearFile() \{\
    ofstream obj("studentDatabase.txt", ios::trunc);\
    if (!obj) \{\
        cerr << "ERROR in clearing the file" << endl;\
        return;\
    \}\
    obj << "RollNo\\tName\\tDivision\\tAddress\\n";\
    obj.close();\
    cout << "File cleared successfully." << endl;\
\}\
\
void StudentData::display() \{\
    ifstream obj("studentDatabase.txt");\
    if (!obj) \{\
        cerr << "ERROR in opening file for display" << endl;\
        return;\
    \}\
    cout << "Contents of the file:\\n";\
    string line;\
    while (getline(obj, line)) \{\
        cout << line << endl;\
    \}\
    obj.close();\
\}\
\
void StudentData::deleteRecord() \{\
    int rn;\
    cout << "Enter Roll No to be deleted: ";\
    cin >> rn;\
\
    ifstream obj("studentDatabase.txt");\
    ofstream temp("temp.txt");\
    if (!obj || !temp) \{\
        cerr << "ERROR in opening files for deletion" << endl;\
        return;\
    \}\
\
    string line;\
    bool deleted = false;\
    while (getline(obj, line)) \{\
        stringstream ss(line);\
        int roll;\
        ss >> roll;\
\
        if (roll == rn) \{\
            deleted = true;\
            continue;\
        \}\
        temp << line << "\\n";\
    \}\
\
    obj.close();\
    temp.close();\
\
    remove("studentDatabase.txt");\
    rename("temp.txt", "studentDatabase.txt");\
\
    if (deleted) \{\
        cout << "Record deleted successfully." << endl;\
    \} else \{\
        cerr << "Record not found!" << endl;\
    \}\
\}\
\
void StudentData::modify() \{\
    int rn;\
    cout << "Enter Roll No to be modified: ";\
    cin >> rn;\
\
    ifstream obj("studentDatabase.txt");\
    ofstream temp("temp.txt");\
    if (!obj || !temp) \{\
        cerr << "ERROR in opening files for modification" << endl;\
        return;\
    \}\
\
    string line;\
    bool modified = false;\
    while (getline(obj, line)) \{\
        stringstream ss(line);\
        int roll;\
        ss >> roll;\
\
        if (roll == rn) \{\
            cout << "Enter new details:\\n";\
            cout << "Roll No: ";\
            cin >> record.rollno;\
            cin.ignore();\
            cout << "Name: ";\
            getline(cin, record.name);\
            cout << "Division: ";\
            cin >> record.div;\
            cin.ignore();\
            cout << "Address: ";\
            getline(cin, record.address);\
\
            temp << record.rollno << "\\t" << record.name << "\\t" << record.div << "\\t" << record.address << "\\n";\
            modified = true;\
        \} else \{\
            temp << line << "\\n";\
        \}\
    \}\
\
    obj.close();\
    temp.close();\
\
    remove("studentDatabase.txt");\
    rename("temp.txt", "studentDatabase.txt");\
\
    if (modified) \{\
        cout << "Record modified successfully." << endl;\
    \} else \{\
        cerr << "Record not found!" << endl;\
    \}\
\}\
\
void StudentData::search() \{\
    int rn;\
    cout << "Enter Roll No to search: ";\
    cin >> rn;\
\
    ifstream obj("studentDatabase.txt");\
    if (!obj) \{\
        cerr << "ERROR in opening file for search" << endl;\
        return;\
    \}\
\
    string line;\
    bool found = false;\
    while (getline(obj, line)) \{\
        stringstream ss(line);\
        int roll;\
        ss >> roll;\
\
        if (roll == rn) \{\
            string name, address;\
            int division;\
            ss >> name >> division >> address;\
\
            cout << "\\nRecord Found:\\n";\
            cout << "Roll No: " << roll << "\\nName: " << name << "\\nDivision: " << division << "\\nAddress: " << address << endl;\
            found = true;\
            break;\
        \}\
    \}\
\
    if (!found) \{\
        cerr << "\\nRecord not found!" << endl;\
    \}\
\
    obj.close();\
\}\
\
int main() \{\
    StudentData stud;\
    bool go = true;\
\
    while (go) \{\
        cout << "\\n------------ Menu ------------";\
        cout << "\\n1. Create New File";\
        cout << "\\n2. Add Record";\
        cout << "\\n3. Display Records";\
        cout << "\\n4. Delete Record";\
        cout << "\\n5. Search Record";\
        cout << "\\n6. Modify Record";\
        cout << "\\n7. Clear File";\
        cout << "\\n8. Exit";\
        cout << "\\nChoose an option: ";\
\
        int choice;\
        cin >> choice;\
\
        switch (choice) \{\
            case 1:\
                stud.newFile();\
                break;\
            case 2:\
                stud.add();\
                break;\
            case 3:\
                stud.display();\
                break;\
            case 4:\
                stud.deleteRecord();\
                break;\
            case 5:\
                stud.search();\
                break;\
            case 6:\
                stud.modify();\
                break;\
            case 7:\
                stud.clearFile();\
                break;\
            case 8:\
                go = false;\
                cout << "\\nThank you for using the system!" << endl;\
                break;\
            default:\
                cerr << "\\nInvalid input! Try again." << endl;\
        \}\
    \}\
\
    return 0;\
\}\
}