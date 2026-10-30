#pragma once
// 一、变量、常量、指针数组
const int SUBJECT_COUNT = 3;
const int MAX_STUDENTS = 10;
inline const char* subjectNames[SUBJECT_COUNT] = { "C++", "Math", "English" };

// 二、枚举类型：为主菜单操作命名
enum MenuOption {
    EXIT = 0,
    SHOW = 1,
    ANALYZE = 2,
    MODIFY = 3,
    SUBJECT_AVG = 4
};

// 三、指向函数的指针：可指向“两个参数、返回 double”的统计函数
typedef double (*StatFunction)(const int*, int);