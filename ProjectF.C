#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

    int matrix[10][10];
    int array[100];
    int i, j, k;
    int rows, columns;
    int temp, choice;

    void ascending(void);
    void descending(void);



void main() {

    int x=180,y=160,rad=150;
    int gd=DETECT, gm;
    initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");

    setcolor(YELLOW);
    circle(x,y,rad);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(x,y,YELLOW);

    gotoxy(7,9);
    printf("Welcome To Matrix Sorting Project");

    setcolor(YELLOW);
    circle(480,370,100);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(530,360,YELLOW);

    setcolor(GREEN);
    circle(330,270,120);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(330,300,GREEN);

    gotoxy(34,14);
    printf("-Made By Team FSB-");

    gotoxy(32,17);
    printf("Faaiz Amir CSC-23S-275");

    gotoxy(31,19);
    printf("Saad Ali Rao CSC-23S-306");

    gotoxy(33,21);
    printf("M. Bilal CSC-23S-271");

    gotoxy(55,23);
    printf("Requested By:");

    gotoxy(53,25);
    printf("Sir. Ameen Khuwaja");

    getch();
    closegraph();


    printf("\nEnter the number of rows: ");
    scanf("%d", &rows);

    printf("\nEnter the number of columns: ");
    scanf("%d", &columns);

    printf("\nEnter the elements of the matrix:\n");

    for (i = 0; i < rows; i++)
    {
	for (j = 0; j < columns; j++)
	{
	    scanf("%d", &matrix[i][j]);
	}
    }

    clrscr();

    printf("\nThe matrix you entered is:\n");

    for (i = 0; i < rows; i++)
    {
	for (j = 0; j < columns; j++)
	{
	    printf("[%d] ", matrix[i][j]);
	}
	printf("\n");
    }

    printf("\n\nQ) Do you want to sort the matrix in ascending or descending order?\n");
    printf("\nEnter [1] for ascending and [2] for descending: ");
    scanf("%d", &choice);

    clrscr();
    switch (choice) {
	case 1:

	ascending();

	    printf("\nThe matrix sorted in ascending order is:\n");
	    break;
	case 2:

	descending();

	    printf("\nThe matrix sorted in descending order is:\n");
	    break;
	default:
	    printf("Invalid choice!\n");
	    return 0;
    }

    for (i = 0; i < rows; i++)
    {
	for (j = 0; j < columns; j++)
	{
	    printf("[%d] ", matrix[i][j]);
	}
	printf("\n");
    }
    getch();

    printf("\nThank You For Your Time <3");


    getch();
  closegraph();
}

void ascending(void) {
	int index = 0;
    // Converting the matrix into an array
	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{
			array[index++] = matrix[i][j];
		}
	}

    // Sorting the array
	for(i=0; i < rows*columns; i++)
	{
		for(j=i+1; j < rows*columns; j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
    // Reshaping the matrix
	index*=0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{
			matrix[i][j] = array[index++];
		}
	}
    }

void descending(void){
	int index = 0;
    // Converting the matrix into an array
	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{
			array[index++] = matrix[i][j];
		}
	}

    // Sorting the array
	for(i=0; i < rows*columns; i++)
	{
		for(j=i+1; j < rows*columns; j++)
		{
			if(array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
    // Reshaping the matrix
	index*=0;
	for(i=0; i<columns; i++)
	{
		for(j=0; j<rows; j++)
		{
			matrix[i][j] = array[index++];
		}
	}
    }