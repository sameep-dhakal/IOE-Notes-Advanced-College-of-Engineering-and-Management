#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
int i,j,k;
int time=0;
char process[10][10];
int num,clock[10],b[10][10];
//clrscr();
printf("Enter the no. of physical clocks: ");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("\nNo. of nodes for physical clock %d: ",i+1);
scanf("%d",&clock[i]);
time=0;
for(j=0;j<clock[i];j++)
{
printf("\nEnter the name of process: ");
scanf(" %c",&process[i][j]);
b[i][j]=time + rand() % 10;
time=b[i][j]+1;
}
}
printf("\nPress a key for watching timestamp of physical clocks\n");
getch();
//clrscr();
for(i=0;i<num;i++)
{
printf("Physical Clock %d: ",i+1);
for(j=0;j<clock[i];j++)
{
printf("\nProcess: %c ",process[i][j]);
printf(" has P.T. : %d ",b[i][j]);
printf("\n");
}
}
printf("Press a key for watching timestamp of logical clocks\n");
getch();
//clrscr(); 
time=0; 

for(j=0;j<num;j++)
{

for(k=0;k<clock[j];k++)
{


time = rand() % 10 + time;
printf("Logical Clock Timestamp for process %c",process[j][k]);
printf(":%d ",time);
printf("\n");
}}
getch();
return;
}

