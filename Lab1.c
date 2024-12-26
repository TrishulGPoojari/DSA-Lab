# include <stdio.h>
//# include <string.h> 
# include <stdlib.h>
# define DAYS 3
    
typedef struct 
{
    char *nday;
    int dday;
    char *desc;
}Plan;

int i;
Plan *cal=NULL;

void create();
void read();
void display();

void main()
{
    create( );
    read();
    display();
}

void create()
{
    cal = (Plan *)malloc(sizeof(Plan)*7);
    if (cal == NULL)
    { 
        printf("Sufficient memory not allocated\n"); exit(0) ; 
    }
}

void read()
{
    for(i=0;i<DAYS;i++)
    {
    cal[i].nday = (char *) malloc(9);
    printf("Enter name of the day "); scanf(" %s",cal[i].nday);
    printf("Enter date of the day "); scanf("%d",&(cal[i].dday));
    getchar();        //used to remove the newline character from the input buffer
    // used before taking the string input using scanf or fgets( after scanf for any datatype) 
    printf("Enter description of the activity ");
    cal[i].desc = (char *) malloc(400);
    scanf(" %399[^\n]",cal[i].desc);  //char set for taking input till 399 character or next line
    //cal[i].desc = (char *) realloc(cal[i].desc,strlen(cal[i].desc)+1);
    }
}

void display()
{
    printf("\n**** Activity description for %d days ****\n",DAYS);
    for(i=0;i<DAYS;i++)
    {
        printf("\nName of the day : %s", cal[i].nday);
        printf("\nDate of the day : %d", cal[i].dday);
        printf("\nActivity description :%s \n", cal[i].desc);
    }
}
