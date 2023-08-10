#ifndef STUDENT_H
#define STUDENT_H
#define MAX 500

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  //for window only
#include <curses.h>
#include <ctype.h>

struct studentInfo
{
	char name[100];
	int studentNum;
	double grade;
};

char menu(char option);
struct studentInfo CreateStudent(void);
void printStuInfo(struct studentInfo studentData[], int index);
void ChangeStudentGrade(struct studentInfo *studentData);
void WriteStudents(struct studentInfo studentData[], int index);
int ReadStudents(struct studentInfo studentData[]);
#endif
