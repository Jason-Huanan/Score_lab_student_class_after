#include<iostream>
#include"Calculus.h"
#include<iomanip>
#include"StudentManager.h"

int readScore() {
    int score;
    do {
        std::cout << "Input score (0-100): ";
        std::cin >> score;
        if (score < 0 || score>100) {
            std::cout << "Invalid score. Try again.\n";
        }
    } while (score < 0 || score>100);
    return score;
}

// 六、指向数组的指针：scores 指向“含 3 个 int 的一整行”
void inputScores(int (*scores)[SUBJECT_COUNT], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < SUBJECT_COUNT; ++j) {
            std::cout << "  " << subjectNames[j] << " - ";
            scores[i][j] = readScore();
        }
    }
}

void showScores(const int (*scores)[SUBJECT_COUNT], int n) {
    std::cout << "\n=== Score List ===\n";
    for (int i = 0; i < n; ++i) {
        // rowPtr 是“指向数组的指针”，不是“指针数组”
        const int (*rowPtr)[SUBJECT_COUNT] = scores + i;
        std::cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < SUBJECT_COUNT; ++j) {
            std::cout << subjectNames[j] << "=" << (*rowPtr)[j] << "  ";
        }
        std::cout << "\n";
    }
}

// 七、普通指针：用 int* 定位、修改某一个成绩
void modifyScore(int (*scores)[SUBJECT_COUNT], int n) {
    int studentNo, subjectNo;
    std::cout << "Student number (1-" << n << "): ";
    std::cin >> studentNo;
    std::cout << "Subject number (1-" << SUBJECT_COUNT << "): ";
    std::cin >> subjectNo;
    if ((studentNo > n || studentNo < 1) || (subjectNo > SUBJECT_COUNT || subjectNo < 1))
    {
        std::cout << "Invalid student/subject number.\n";
        return;
    }
    int* pScore = &scores[studentNo - 1][subjectNo - 1];
    *pScore = readScore();
    std::cout << "Score updated.\n";
}

// 八、函数指针 + switch：运行时选统计函数
void analyzeStudent(const int (*scores)[SUBJECT_COUNT], int n) {
    int studentNo, op;
    std::cout << "Student number (1-" << n << "): ";
    std::cin >> studentNo;
    if (studentNo < 1 || studentNo > n) {
        std::cout << "Invalid student number.\n";
        return;
    }
    std::cout << "Statistic: 1=Sum, 2=Average, 3=Maximum: ";
    std::cin >> op;
    StatFunction action = 0;
    switch (op) {
    case 1: action = calcSum; break;
    case 2: action = calcAverage; break;
    case 3: action = calcMax; break;
    default:
        std::cout << "Invalid statistic option.\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Result: " << (*action)(scores[studentNo - 1], SUBJECT_COUNT) << "\n";
}

// 九、双重 for：统计每门课程的班级平均分
void showSubjectAverage(const int (*scores)[SUBJECT_COUNT], int n) {
    std::cout << "\n=== Subject Averages ===\n";
    for (int j = 0; j < SUBJECT_COUNT; ++j) {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += scores[i][j];
        }
        std::cout << subjectNames[j] << ": " << std::fixed << std::setprecision(2)
            << sum / n << "\n";
    }
}