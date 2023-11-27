#ifndef clink.h
#define clink.h
#include<string.h>

typedef struct listnode
{
    int id ;
    int age;
    char name[30];
    char gender [30];
    struct listnode*next;
    int date;

}listnode;

typedef struct list
{
    int size;
    listnode* head; //points to first node

}list;
list L;

////////////////////////////////////////////////////////

void List_VoidInit (list*PL);
void List_VoidInsert(int pos,int id,int age,char name [],char gender [],list* PL);
void List_VoidDelete(int pos,list * pl ,int * age,int *id );
void List_VoidPrint(list*pl);
int  List_intSize(list* pl);
int checkpass (int pass);
void list_VoidReplace_Age(int pos_toedit,list *pl,int newage);
void list_VoidReplace_ID(int pos_toedit,list *pl,int newid);
void list_VoidReplace_name(int pos_toedit,list * pl, char newname[]);
void list_VoidReplace_gender(int pos_toedit,list * pl, char newgender[]);
void CheckPrint (void);
void patientdata (int key,list *pl);
void CancelReserv (int key,int choice,list * pl);
void CheckReserv (int key,list *pl);
void Reservation (int key ,int choice,list *pl);
struct listnode * idsearch (int idkey ,list *pl);
void displayreservations (list * pl);







#endif // clink
