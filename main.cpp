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
    cout << "請輸入學生學號>> ";
    cin >> id;
    for (const auto& s : stu) {
        if (s.id == id) {
            cout << "學號已存在，請重新輸入。\n";
            return;
        }
    }
    cout << "請輸入學生姓名>> ";
    cin >> name;
    cout << "請輸入學生分數>> ";
    cin >> score;
    stu.push_back({id, name, score});
}

void showInfo(const vector<Student>& stu){
    if (stu.empty()) {
        cout << "沒有學生資料。\n";
        return;
    }
    for (const auto& s : stu) {
        cout << "學號: " << s.id << ", 姓名: " << s.name << ", 分數: " << s.score << endl;
    }
}

void sortbyScore(vector<Student>& stu){
    sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; // 降序排序
    });
}

void searchbyID(const vector<Student>& stu){
    string id;
    cout << "請輸入要查詢的學號: ";
    cin >> id;
    if (stu.empty()) {
        cout << "沒有學生資料。\n";
        return;
    }
    for (const auto& s : stu) {
        if (s.id == id) {
            cout << "找到學生！學號: " << s.id << ", 姓名: " << s.name << ", 成績: " << s.score << endl;
            return;
        }
    }
    cout << "找不到該學號的學生！\n";
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
        cout << "沒有學生資料。\n";
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

    cout << "平均分數: " << averageScore << endl;
    cout << "最高分: " << maxScore << endl;
    cout << "最低分: " << minScore << endl;
    cout << "及格人數: " << passCount << endl;
    cout << "不及格人數: " << failCount << endl;
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