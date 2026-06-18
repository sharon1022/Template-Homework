#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    string id;
    string name;
    int score;
};

void addInfo(vector<Student>& stu){
    string id, name;
    int score;
    cout << "Please enter student ID: ";
    cin >> id;
    for (const auto& s : stu) {
        if (s.id == id) {
            cout << "Student ID already exists. Please enter a different ID.\n";
            return;
        }
    }
    cout << "Please enter student name: ";
    cin >> name;
    cout << "Please enter student score: ";
    cin >> score;
    stu.push_back({id, name, score});
}

void showInfo(const vector<Student>& stu){
    if (stu.empty()) {
        cout << "No student information available.\n";
        return;
    }
    for (const auto& s : stu) {
        cout << "Student ID: " << s.id << ", Name: " << s.name << ", Score: " << s.score << endl;
    }
}

void sortbyScore(vector<Student>& stu){
    sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; // 降序排序
    });
}

void searchbyID(const vector<Student>& stu){
    string id;
    cout << "Please enter the student ID to search for: ";
    cin >> id;
    if (stu.empty()) {
        cout << "No student information available.\n";
        return;
    }
    for (const auto& s : stu) {
        if (s.id == id) {
            cout << "Student found! ID: " << s.id << ", Name: " << s.name << ", Score: " << s.score << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

template<class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template<class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

void statistics(const vector<Student>& stu){
    
    if (stu.empty()) {
        cout << "No student information available.\n";
        return;
    }

    int totalScore = 0;
    int maxScore = stu[0].score;
    int minScore = stu[0].score;
    int passCount = 0;
    int failCount = 0;

    for (const auto& s : stu) {
        totalScore += s.score;
        maxScore = getMax(maxScore, s.score);
        minScore = getMin(minScore, s.score);
        if (s.score >= 60) {
            passCount++;
        } else {
            failCount++;
        }
    }

    double averageScore = static_cast<double>(totalScore) / stu.size();

    cout << "Average Score: " << averageScore << endl;
    cout << "Highest Score: " << maxScore << endl;
    cout << "Lowest Score: " << minScore << endl;
    cout << "Number of Students who passed: " << passCount << endl;
    cout << "Number of Students who failed: " << failCount << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "1. Add student\n";
        cout << "2. List all students\n";
        cout << "3. Sort by score\n";
        cout << "4. Search by id\n";
        cout << "5. Show statistics\n";
        cout << "0. Exit\n";
        cout << "Please select an operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addInfo(students);
                break;
            case 2:
                showInfo(students);
                break;
            case 3:
                sortbyScore(students);
                showInfo(students);
                break;
            case 4:
                searchbyID(students);
                break;
            case 5:
                statistics(students);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}