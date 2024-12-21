#include <iostream>  
#include <iomanip>  
#include <string>  
#include <cstdlib> // De sus dung system ("cls")  

using namespace std;

const int MAX_STUDENTS = 1000; // Kich thuoc toi da cua mang hoc sinh  

// Khai bao cac mang tĩnh  
string studentIDs[MAX_STUDENTS];
string studentNames[MAX_STUDENTS];
float midtermGrades[MAX_STUDENTS];
float finalGrades[MAX_STUDENTS];
float averageGrades[MAX_STUDENTS];
int studentCount = 0; // Dem so luong hoc sinh da nhap  

void clearScreen() {
    system("cls"); // Xoa man hinh console  
}

int inputStudentInfo() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return -1; // Khong the them hoc sinh  
    }

    cout << "Enter student ID: ";
    cin >> studentIDs[studentCount];
    cout << "Enter student name: ";
    cin.ignore(); // De bo qua ky tu newline sau khi nhap ID  
    getline(cin, studentNames[studentCount]);

    midtermGrades[studentCount] = 0.0; // Diem giua ky khoi tao  
    finalGrades[studentCount] = 0.0;   // Diem cuoi ky khoi tao  
    averageGrades[studentCount] = 0.0;  // Diem trung binh khoi tao  
    studentCount++;
    return studentCount; // Tra ve so luong hoc sinh da nhap  
}

int inputMidtermGrades() {
    for (int i = 0; i < studentCount; i++) {
        cout << "Enter midterm grade for " << studentNames[i] << ": ";
        cin >> midtermGrades[i];
    }
    return studentCount; // Tra ve so luong hoc sinh  
}

int inputFinalGrades() {
    for (int i = 0; i < studentCount; i++) {
        cout << "Enter final grade for " << studentNames[i] << ": ";
        cin >> finalGrades[i];
    }
    return studentCount; // Tra ve so luong hoc sinh  
}

int calculateAverage() {
    for (int i = 0; i < studentCount; i++) {
        averageGrades[i] = (midtermGrades[i] * 0.4) + (finalGrades[i] * 0.6);
    }
    return studentCount; // Tra ve so luong hoc sinh  
}

int statistics() {
    if (studentCount == 0) {
        cout << "No students to evaluate." << endl;
        return 0; // Khong co hoc sinh  
    }

    float minGrade = averageGrades[0];
    float maxGrade = averageGrades[0];
    float totalGrade = 0.0;

    for (int i = 0; i < studentCount; i++) {
        if (averageGrades[i] < minGrade) minGrade = averageGrades[i];
        if (averageGrades[i] > maxGrade) maxGrade = averageGrades[i];
        totalGrade += averageGrades[i];
    }

    float average = totalGrade / studentCount;
    cout << fixed << setprecision(2);
    cout << "Minimum average grade: " << minGrade << endl;
    cout << "Maximum average grade: " << maxGrade << endl;
    cout << "Overall average grade: " << average << endl;
    return studentCount; // Tra ve so luong hoc sinh  
}

int filterStudents() {
    float threshold;
    cout << "Enter threshold for average grade: ";
    cin >> threshold;

    cout << "Students with average grade less than " << threshold << ":" << endl;
    int countFiltered = 0; // Đếm số học sinh bị lọc  
    for (int i = 0; i < studentCount; i++) {
        if (averageGrades[i] < threshold) {
            cout << "ID: " << studentIDs[i] << ", Name: " << studentNames[i] << ", Average Grade: " << averageGrades[i] << endl;
            countFiltered++;
        }
    }
    return countFiltered; // Tra ve so luong hoc sinh bi loc  
}

int searchStudents() {
    string query;
    cout << "Enter Student ID or Name to search: ";
    cin.ignore(); // Bo qua ky tu newline con lai  
    getline(cin, query);

    cout << "Search Results:" << endl;
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (studentIDs[i] == query || studentNames[i] == query) {
            cout << "ID: " << studentIDs[i] << ", Name: " << studentNames[i]
                << ", Midterm Grade: " << midtermGrades[i]
                << ", Final Grade: " << finalGrades[i]
                << ", Average Grade: " << averageGrades[i] << endl;
            found = true;
        }
    }
    return found ? 1 : 0; // Tra ve 1 neu tim thay, 0 neu khong  
}

int main() {
    int choice;
    do {
        clearScreen();
        cout << "1. Input Student Info" << endl;
        cout << "2. Input Midterm Grades" << endl;
        cout << "3. Input Final Grades" << endl;
        cout << "4. Calculate Statistics" << endl;
        cout << "5. Calculate Final Grades" << endl;
        cout << "6. Filter Students" << endl;
        cout << "7. Search Students" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: inputStudentInfo(); break;
        case 2: inputMidtermGrades(); break;
        case 3: inputFinalGrades(); break;
        case 4: calculateAverage(); statistics(); break;
        case 5: calculateAverage(); break;
        case 6: filterStudents(); break;
        case 7: searchStudents(); break;
        case 0: cout << "Exiting program." << endl; break;
        default: cout << "Invalid option!" << endl; break;
        }
        cin.ignore(); // Cho nguoi dung truoc khi xoa man hinh  
    } while (choice != 0);

    return 0;
}