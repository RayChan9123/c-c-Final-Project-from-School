#include "student-2.h"
#include "curses.h"

char menu(char option)
{
	puts("(A)dd a Student");
	puts("(C)hange a Student's Grade");
	puts("(L)ist All Students");
	puts("(E)nd");

	scanf(" %c", &option);
	return option;
}

struct studentInfo CreateStudent()
{
	
	struct studentInfo studentData;

	puts("Please enter the Student Name!");
	scanf(" ");
	gets(studentData.name);
	puts("Please enter the Student Number!");
	scanf(" %d", &studentData.studentNum);
	puts("Please enter the Grade!");
	scanf(" %lf", &studentData.grade);

	while (1)
	{
		if (studentData.grade < 0 || studentData.grade > 100)
		{
			puts("ERROR! Please Enter a valid Grade between 0 - 100! ");
			scanf(" %lf", &studentData.grade);
		}
		else
		{
			return studentData;//{studentData.name, studentData.studentNum, studentdata.grade
		}
	} 
} 

void printStuInfo(struct studentInfo studentData[], int index)
{
    int i;
    
    for (i = 0; i <= index; i++)
    {
       printf("%s \t\t\t\t", studentData[i].name);
       printf("%09d \t\t\t\t", studentData[i].studentNum);
       printf("%.1lf %c\n", studentData[i].grade, '%');
    }
}
//stage2
void ChangeStudentGrade(struct studentInfo *studentData)
{
    char yesOrNo;
    double newGrade;
    
    printf(" The current grade of the student is %.1lf %c \n", studentData->grade, '%');//(*studentData).grade
    printf(" Would you like to change the grade of the student? Please input Y/N");
    scanf(" %c", &yesOrNo );
    printf("\n");
    
    if (toupper(yesOrNo) == 'Y')
    {
        while(1)
        {
            printf("What is the new grade the student is getting?");
            scanf(" %lf", &newGrade);
        
            if (newGrade < 0 || newGrade > 100)
            {
                puts("Invalid input, please input a number within the range of 0 - 100");
            }
            else
            {
                studentData->grade = newGrade;
                printf("The new grade is now %.2lf", studentData->grade);
                break;
            }
        }
    }
}
//stage3
void WriteStudents(struct studentInfo studentData[], int index)
{
    FILE *fout;
    int i;
    int numOfStu = index;
    
    
    fout = fopen("STUDENT.DAT", "wb+");//+random access
        
    if (!fout)
    {
        printf("Oopsss! cannot open the file STUDENT.DAT to WRITE somthing for some reasons");
        _getch();
        exit(1);
    }

    fwrite(&numOfStu, sizeof(int), 1, fout);//The behavior of fwrite is undefined if the values in data are too large to fit in the specified precision??

    for (i = 0; i < numOfStu; i++)
    {
        fwrite(&studentData[i], sizeof(studentData[i]), 1, fout);
    }

    fclose(fout);

}

int ReadStudents(struct studentInfo studentData[])
{
    FILE *fin;
    int numOfStu;
    int i;

    fin = fopen("STUDENT.DAT", "rb+");

    if (!fin)
    {
        printf("Oopsss! cannot open the file STUDENT.DAT to READ somthing for some reasons, Press any key to continue \n ");
        _getch();
        return 0;
    }

    fread(&numOfStu, sizeof(int), 1, fin);

    for (i = 0; i < numOfStu; i++)
    {
        fread(&studentData[i], sizeof(studentData[i]), 1, fin);
    }

    fclose(fin);
    return numOfStu;
}
