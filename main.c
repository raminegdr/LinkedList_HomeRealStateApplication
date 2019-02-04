#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define  NIL (struct homedata*)NULL
#include <ctype.h>

/* This is a console application for Home real state which is written with c language programming and is implemented by linked list and file reader and writer.
There is a file named "data" which all information home is there.
Application read data each home in during program execution.

 This application has 4 function :
 1.add new home
 2.edit home data before
 3.delete home
 4.getting report
 5.save data into data.txt
 @Zohreh Ghaderi
*/
struct homedata
{
    float area;
    int nom;
    int room;
    int state;
    int cost;
    struct homedata*next;

}*first,*last,*node,*last1,*last2;

void enter_add();
void display();
void delet();
int menu(),report();
void update();
void clsrcr(),readfile(FILE *read),writing(FILE *writ);
void costing(),rooming(),area(),state();

//main function
int main()
{
    FILE *read,*writ,*read1;

    read1=fopen("data.txt","a+");

    if(read1==NULL)
        printf("the file could not be open\n");

    read=fopen("data.txt","r+");
    if(read==NULL)
        printf("the file could not be open\n");

    first=NIL;
    readfile(read);

    while(1)
        switch(menu())
        {

        case 1:
            enter_add();
            break;
        case 2:
        {

            delet();
            display();
        }
        break;
        case 3:
        {
            update();

        }
        break;
        case 4:
            report();
            break;

        case 5:
        {
            writing(writ);
            exit (0);
        }
        break;


        }
    return 0;

}
/****************************************************************************************************************/
//start menu
int menu()
{
    int choice;
    system("cls");

    printf("          <<<select one of item>>>\n");
    printf("if want to add to home display enter (1)\n");
    printf("if want to delete item home enter (2)\n");
    printf("if want to update item home enter(3)\n");
    printf("if want to report item home enter (4)\n");
    printf("if want to save item home into data.txt enter (5)\n");

    printf("your choice is:");
    scanf("%d",&choice);
    printf("****************************************************************************\n");
    return choice;

}
/*****************************************************************************************************************/
//this function get data and add to link list
void enter_add()
{
    system("cls");


    node=(struct homedata*)malloc(sizeof(struct homedata));
    node->next=NIL;
    if(first==NIL)
        first=last=node;
    else
    {
        last->next=node;
        last=node;
    }
    printf("\nenter code of home:");
    scanf("%d",&last->nom);
    printf("\nenter state of home:(tent=1,sale=2)");
    scanf("%d",&last->state);
    printf("\nenter area of home:");
    scanf("%f",&last->area);
    printf("\nenter cost of home:");
    scanf("%d",&last->cost);
    printf("\nenter number of room:");
    scanf("%d",&last->room);






}
/****************************************************************************************************************/
//this function show all home information.
void display()
{


    if(first==NIL)
    {
        printf("\n\n <<the display is empty.");
        getch ();
        return ;
    }
    last=first;


    printf("\n\ncode     state     area      cost      room     \n");
    printf("-------------------------------------------------------\n");

    do
    {

        printf("%d",last->nom);

        printf("        %1d",last->state);

        printf("       %4.3f",last->area);

        printf("       %6d",last->cost);

        printf("       %1d\n",last->room);

        last=last->next;
    }
    while(last!=NIL);

    printf("*********************************************************\n\n");
    return 0;


}
/*****************************************************************************************************************/
// this function delete selected home
void delet()
{
    system("cls");
    int nom;
    display();
    printf("enter code of home for delete");
    scanf("%d",&nom);
    last=node=first;
    while(last!=NIL)
    {
        if(last->nom!=nom)
        {
            node=last;
            last=last->next;
            continue;
        }
        else
        {
            if(last==first)
            {
                first=last->next;
                free(last);
                free(node);
                break;
            }
            else
            {
                node->next=last->next;
                free(last);
                break;

            }

        }
    }
    return 0;
}
/*****************************************************************************************************************/
//this function show report for selected home information
int report()
{
    int i;
    system("cls");


    while(1)
    {
        printf("\n            <<reporting>>\n");
        printf("for shows all of the information enter (1)\n");
        printf("for shows all information based on the cost enter(2)\n");
        printf("for shows all information based on the room enter(3)\n");
        printf("for shows all information based on the state enter(4)\n");
        printf("for shows all information based on the area enter(5)\n");
        printf("for return to previous menu(6)\n");
        printf("your choice is:");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            display();
            break;
        case 2:
            costing();
            break;
        case 3:
            rooming();
            break;
        case 4:
            state();
            break;
        case 5:
            area();
            break;
        case 6:
            return 1;
            break;
        }

    }
    return 0;

}
/*****************************************************************************************************************/
// this function get desired cost and find best result for it.

void costing()
{
    int cost;
    system("cls");
    printf(" your desired cost");
    scanf("%d",&cost);
    if(first==NIL)
    {
        printf("\n <<the display is empty.");
        getch ();
        return ;
    }
    last=first;


    printf("code     state     area      cost      room     \n");
    printf("-------------------------------------------------------\n");

    do
    {
        if(last->cost<=cost)

        {

            printf("%d",last->nom);

            printf("        %1d",last->state);

            printf("       %4.3f",last->area);

            printf("       %6d",last->cost);

            printf("       %1d\n",last->room);

            last=last->next;
        }

    }
    while(last->next!=NIL);

    printf("*********************************************************\n");



}
/*****************************************************************************************************************/
// this function update selected home information
void update ()
{
    system("cls");
    display();
    int nom;
    printf("enter number of home for update:");
    scanf("%d",&nom);
    last=node=first;
    while(last!=NIL)
    {
        if(last->nom!=nom)
        {
            node=last;
            last=last->next;
            continue;
        }
        else
        {
            printf("\n enter your parameter for update:");
            printf("\n enter new area:");
            scanf("%f",&last->area);
            printf("\n enter new cost: ");
            scanf("%d",&last->cost);
            printf("\n enter new number of room:");
            scanf("%d",&last->room);
        }
        break;
        display();
    }

}
/*****************************************************************************************************************/
// this function get desired room and find best result for it.
void rooming()
{
    int room;
    system("cls");
    printf(" your desired room");
    scanf("%d",&room);
    if(first==NIL)
    {
        printf("\n <<the display is empty.");
        getch ();
        return ;
    }
    last=first;


    printf("code     state     area      cost      room     \n");
    printf("-------------------------------------------------------\n");

    do
    {
        if(last->room<=room)

        {

            printf("%d",last->nom);

            printf("        %1d",last->state);

            printf("       %4.3f",last->area);

            printf("       %6d",last->cost);

            printf("       %1d\n",last->room);

            last=last->next;
        }
    }
    while(last!=NIL);

    printf("*********************************************************\n");



}

/******************************************************************************************************************/
// this function get desired state and find best result for it.

void state ()
{
    int state;
    system("cls");
    printf("your desired state");
    scanf("%d",&state);
    if(first==NIL)
    {
        printf("\n <<the display is empty.");
        getch ();
        return ;
    }
    last=first;
    printf("code     state     area      cost      room     \n");
    printf("-------------------------------------------------------\n");

    do
    {
        if(last->state==state)
        {
            printf("%d",last->nom);

            printf("        %1d",last->state);

            printf("       %4.3f",last->area);

            printf("       %6d",last->cost);

            printf("       %1d\n",last->room);

            last=last->next;
        }
    }
    while(last!=NIL);

    printf("*********************************************************\n");
}
/*******************************************************************************************************/
// this function get desired area and find best result for it.
void  area()
{
    int area;
    system("cls");
    printf(" your desired area");
    scanf("%d",&area);
    if(first==NIL)
    {
        printf("\n <<the display is empty.");
        getch ();
        return ;
    }
    last=first;


    printf("code     state     area      cost      room     \n");
    printf("-------------------------------------------------------\n");

    do
    {
        if(last->area<=area)

        {

            printf("%d",last->nom);

            printf("        %1d",last->state);

            printf("       %4.3f",last->area);

            printf("       %6d",last->cost);

            printf("       %1d\n",last->room);

            last=last->next;
        }
    }
    while(last!=NIL);

    printf("*********************************************************\n");





}
/************************************************************************************************************/
//Readfile function get reader file pointer and read data home from data.txt

void readfile(FILE *read)
{
    int i=0;
    last1=(struct homedata*)malloc(sizeof(struct homedata));
    for(i=0; !feof(read); i++)
        fscanf(read,"%d %d %f %d %d",&last1->nom ,&last1->state,&last1->area,&last1->cost,&last1->room);

    fseek(read,0L,SEEK_SET);
    i--;
    while (i>=1)
    {
        node=(struct homedata*)malloc(sizeof(struct homedata));
        node->next=NIL;
        if(first==NIL)
            first=last=node;
        else
        {
            last->next=node;
            last=node;
        }
        fscanf(read,"%d %d %f %d %d",&last->nom ,&last->state,&last->area,&last->cost,&last->room);
        i--;
    }


    printf("%d",i);
}
/************************************************************************************************/
//writing function get writer file pointer and write data home into data.txt
void writing(FILE *writ)
{
    writ=fopen("data.txt","w+");

    if(writ==NULL)
        printf("the file could not be open\n");
    last2=first;

    if(last2)
    {
        fprintf(writ,"%d    %d      %f    %d    %d    \n",last2->nom,last2->state,last2->area,last2->cost,last2->room);

        while (last2->next!=NIL)
        {
            last2=last2->next;
            fprintf(writ,"%d %d %f %d %d \n",last2->nom,last2->state,last2->area,last2->cost,last2->room);
        }
    }
}

