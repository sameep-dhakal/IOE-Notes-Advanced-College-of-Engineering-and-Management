#include<stdio.h>
#include<conio.h>
#include<time.h>
void main()
{
int cs=0,pro=0;
int run=5;
char key='a';
time_t t1,t2;

printf("Press a key(except q) to enter a process into critical section.");
printf(" \nPress q at any time to exit.");
//t1 = time(NULL) - 5;
while(key!='q')
	{
	while(!kbhit())
	{
	if(cs!=0)//1
		{
		t2 = time(NULL);//123334445+3
		if(t2-t1 > run)//
			{
			printf("Process%d ",pro-1);
			printf(" exits critical section.\n");
			cs=0;//
			}
		}
	}
    key = getch();
	if(key!='q')
		{
			if(cs!=0)//1
			
			printf("\nError: Another process is currently executing critical section Please wait till its execution is over.\n");
			else
			{
				printf("Process %d ",pro);//0
				printf(" entered critical section\n");
				cs=1;//
				pro++;
				t1 = time(NULL);//1234455788
			}
		}
	}
}