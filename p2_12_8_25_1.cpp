#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;

struct address {
    char House_Number[15];
    char Street_Name[20];
    char City_Name[50];
    char State_Name[50];
    char Country_Name[50];
};

struct Student {
    char Roll_Number[7];
    char Student_Name[25];
    char Father_Name[25];
    char Mother_Name[25];
    char class_name[30];
    int sem;
    char branch[50];
    address AD;
};

void DV_Add_Record();
void DV_Delete_Record(const char* rollNo);
void DV_Search_Record();
void DV_display_By_Location();
void DV_Generate_Report();
int DV_Name_Checker(const char* Student_Name);
int DV_RollNo_Checker(const char* Roll_Number);
void DV_Show_Record(Student s);

void DV_Log_Event(const char* message) {
    FILE* logFile = fopen("LogFile.log", "a");
    if (!logFile) return;
    fprintf(logFile, " %s\n ", message);
    fclose(logFile);
}

int main() {
    int choice;
    while (1) {
        cout << "----STUDENT DATA ----" << endl;
        cout << "1. Add Record\n2. Delete Record\n3. Search Record by City/State/Country\n4. Display Records by Location\n5. Generate Report\n6. Exit\n Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: DV_Add_Record();
           break;
            case 2: {
                char roll[30];
                cout << "Enter which Roll Number realted record to delete: ";
                cin.getline(roll, 30);
                DV_Delete_Record(roll);
                break;
            }
            case 3: DV_Search_Record(); 
            break;
            case 4: DV_display_By_Location();
            break;
            case 5: DV_Generate_Report(); 
            break;
            case 6: exit(0);
            default: cout << "Invalid choice!!\n";
        }
    }
    return 0;
}

int DV_Name_Checker
(const char* Student_Name) {
    for (int i = 0; Student_Name[i]; i++) {
        if (isdigit(Student_Name[i])) return 0;
    }
    return 1;
}

int DV_RollNo_Checker
(const char* roll) {
    if (strlen(roll) != 7) return 0;
    if (strncmp(roll, "CO243", 5) != 0) return 0;
    if (!isdigit(roll[5]) || !isdigit(roll[6])) return 0;
    return 1;
}

void DV_Show_Record(Student s) {
    cout << "\nRoll Number: " << s.Roll_Number;
    cout << "\nStudent Name: " << s.Student_Name;
    cout << "\nFather's Name: " << s.Father_Name;
    cout << "\nMother's Name: " << s.Mother_Name;
    cout << "\nClass: " << s.class_name;
    cout << "\nSemester: " << s.sem;
    cout << "\nBranch: " << s.branch;
    cout << "\nAddress - House number: " << s.AD.House_Number;
    cout << "\n Street Name: " << s.AD.Street_Name;
    cout << "\n City_Name: " << s.AD.City_Name;
    cout << "\n State: " << s.AD.State_Name;
    cout << "\n Country: " << s.AD.Country_Name << "\n";
}

void DV_Add_Record() {
    Student s;
    cout << "Enter roll no.: ";
    cin.getline(s.Roll_Number, 30);

    if (!DV_RollNo_Checker(s.Roll_Number)) {
        cout << "Invalid Roll Number format! Must be CO243XX\n";
        return;
    }

    FILE* fp = fopen("database.dat", "rb");
    Student temp;
    int duplicate_found = 0;

    if (fp != NULL) {
        while (fread(&temp, sizeof(Student), 1, fp)) {
            if (strcmp(temp.Roll_Number, s.Roll_Number) == 0) {
                duplicate_found = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (duplicate_found) {
        cout << "Error: Roll number already exists!\n";
        return;
    }

    cout << "Enter Student Name: ";
    cin.getline(s.Student_Name, 50);
    if (!DV_Name_Checker(s.Student_Name)) {
        cout << "Invalid name!\n";
        return;
    }

    cout << "Enter Father's Name: ";
    cin.getline(s.Father_Name, 50);
    if (!DV_Name_Checker(s.Father_Name)) {
        cout << "Invalid father's name!\n";
        return;
    }

    cout << "Enter Mother's Name: ";
    cin.getline(s.Mother_Name, 50);
    if (!DV_Name_Checker(s.Mother_Name)) {
        cout << "Invalid mother's name!\n";
        return;
    }

    cout << "Enter Class: ";
    cin.getline(s.class_name, 30);

    cout << "Enter Semester: ";
    cin >> s.sem;
    cin.ignore();

    cout << "Enter Branch: ";
    cin.getline(s.branch, 50);

    cout << "Enter House No: ";
    cin.getline(s.AD.House_Number, 30);

    cout << "Enter Street Name: ";
    cin.getline(s.AD.Street_Name, 50);

    cout << "Enter City_Name: ";
    cin.getline(s.AD.City_Name, 50);

    cout << "Enter State: ";
    cin.getline(s.AD.State_Name, 50);

    cout << "Enter Country: ";
    cin.getline(s.AD.Country_Name, 50);

    fp = fopen("database.dat", "ab");
    if (fp == NULL) {
        cout << "Error opening file!\n";
        return;
    }

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    cout << "Record added successfully!\n";

    char log[100];
    sprintf(log, "Student added: %s", s.Roll_Number);
    DV_Log_Event(log);
}

void DV_Delete_Record(const char* Roll_Number
) {
    Student s;
    FILE* fin = fopen("database.dat", "rb");
    FILE* fout = fopen("tempfile.dat", "wb");
    int found = 0;

    if (fin == NULL || fout == NULL) {
        cout << "File error!\n";
        return;
    }

    while (fread(&s, sizeof(Student), 1, fin)) {
        if (strcmp(s.Roll_Number
, Roll_Number
) != 0) {
            fwrite(&s, sizeof(Student), 1, fout);
        } else {
            found = 1;
        }
    }

    fclose(fin);
    fclose(fout);

    remove("database.dat");
    rename("tempfile.dat", "database.dat");

    if (found) cout << "Record deleted successfully!\n";
    else cout << "Record not found!\n";

    char log[100];
if (found)
    sprintf(log, "Student deleted: %s", Roll_Number);
else
    sprintf(log, "Delete failed: %s not found", Roll_Number);
DV_Log_Event(log);

}

void DV_Search_Record() {
    Student s;
    FILE* fp = fopen("database.dat", "rb");
    if (!fp) {
        cout << "File error!\n";
        return;
    }

    char query[50];
    int option;
    cout << "Search by: 1. City_Name 2. State 3. Country: ";
    cin >> option;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(query, 50);

    int found = 0;

    while (fread(&s, sizeof(Student), 1, fp)) {
        if ((option == 1 && strcmp(s.AD.City_Name, query) == 0) ||
            (option == 2 && strcmp(s.AD.State_Name, query) == 0) ||
            (option == 3 && strcmp(s.AD.Country_Name, query) == 0)) {
            DV_Show_Record(s);
            found = 1;
        }
    }

    if (!found) cout << "No records found!\n";
    fclose(fp);
}

void DV_display_By_Location
() {
    DV_Search_Record(); }

void DV_Generate_Report() {
    Student s;
    FILE* fp = fopen("database.dat", "rb");
    if (!fp) {
        cout << "File error!\n";
        return;
    }

    int count = 0;
    cout << "\n ===== Student Report ===== \n";
    while (fread(&s, sizeof(Student), 1, fp)) {
        DV_Show_Record(s);
        count++;
    }
    cout << "\nTotal Students: " << count << endl;
    fclose(fp);
}