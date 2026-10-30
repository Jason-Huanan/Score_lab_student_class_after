#pragma once
#include"Constant.h"
int readScore();
void inputScores(int (*scores)[SUBJECT_COUNT], int n);
void showScores(const int (*scores)[SUBJECT_COUNT], int n);
void modifyScore(int (*scores)[SUBJECT_COUNT], int n);
void analyzeStudent(const int (*scores)[SUBJECT_COUNT], int n);
void showSubjectAverage(const int (*scores)[SUBJECT_COUNT], int n);