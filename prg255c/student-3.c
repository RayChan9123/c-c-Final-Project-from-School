/*
 Author: Ray Chan
 Date: 10/08/2022
 Version:1.3
 Description: The purpose of the program is to create a student data system which allows storing students' data, modifying data, listing data, reading data from an input file and writing data to an output file when exit.
 */


//#include "functions.c" // no need to include as it is in the same folder
#include "studenttutils.c"

int main()
{
    char option = 'Z';
	struct studentInfo studentData[MAX];
	int index = 0;
    int index2 = 0;
    int studentId;
    
    index = ReadStudents(studentData);//&studentData[0]
    
	while (1)
	{
		option = toupper(menu(option));

		if (option == 'A' || option == 'C' || option == 'L' )
		{
			switch (option)
			{
				case 'A':
					studentData[index] = CreateStudent();
					index++;
					break;

				case 'C':
                    
                    
                    printf("Please input the student number for grade changing.");
                    scanf(" %d", &studentId);
                                        
                    for (index2 = 0; index2 <= index; index2++)
                    {
                        if ( studentId == studentData[index2].studentNum)
                        {
                            ChangeStudentGrade(&studentData[index2]);
                            break;
                        }
                    }
                    
                    if ( studentId == studentData[index2].studentNum)
                    {
                        break;
                    }
                    else
                    {
                        printf("Sorry student number not found!");
                        system("pause");
                        break;
                    }
                    
				case 'L':
                    puts("Student Name \t\t\t Student Number \t\t\t Grade");
					printStuInfo(studentData, index - 1);
					break;
			}
		}
		else {
            WriteStudents(studentData, index);
			break;
		}
	}
	printf("yeah out of loop");

	system("pause");
	return 0;
}
