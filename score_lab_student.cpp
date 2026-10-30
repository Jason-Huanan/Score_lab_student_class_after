#include <iostream>
#include<iomanip>
#include"Constant.h"
#include"StudentManager.h"
#include"Calculus.h"

// 十、new/delete + while + switch：完整菜单主流程
int main() {
    int n;
    do {
        std::cout << "Student count (1-" << MAX_STUDENTS << "): ";
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            n = -1;
        }
        if (n<1||n>MAX_STUDENTS) {
            std::cout << "Invalid count. Try again.\n";
        }
    } while (n<1||n>MAX_STUDENTS);

    // new 创建 n 行、每行 SUBJECT_COUNT 个 int 的二维动态数组
    int (* scores)[SUBJECT_COUNT] = new int[n][SUBJECT_COUNT];
    inputScores(scores, n);

    int choice = -1;
    while(choice != EXIT) {
        std::cout << "\n0=Exit  1=Show  2=Analyze  3=Modify  4=SubjectAvg\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
    switch (choice) {
    case SHOW:
        showScores(scores, n);
        break;
    case ANALYZE:
        analyzeStudent(scores, n);
        break;
    case MODIFY:
        modifyScore(scores, n);
        break;
    case SUBJECT_AVG:
        showSubjectAverage(scores, n);
        break;
    case EXIT:
        std::cout << "Goodbye!\n";
        break;
    default:
        std::cout << "Invalid menu option.\n";
        break;
        }
    }

    delete[] scores;
    scores = 0;
    return 0;
}