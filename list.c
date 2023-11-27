#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"clinic.h"

struct listnode * arr[5]={NULL};

void List_VoidInit (list*PL)
{
   PL->size=0;
   PL->head =NULL;
}
//////////////////////////////////////////////
 void List_VoidInsert(int pos,int id,int age,char name [],char gender [],list* PL)
 {

     listnode * PTR;
     listnode * PN = (listnode*)malloc(sizeof (listnode));
     PN->id=id;
     PN->age=age;
     strcpy(PN->name,name);
     strcpy(PN->gender,gender);

     if(pos==0)
     {
        PN->next=PL->head;
        PL->head=PN;
     }
     else
     {
        PTR=PL->head;
        for(int i=0;i<pos-1;i++)
        {
            PTR=PTR->next;
        }
        PN->next=PTR->next;
        PTR->next=PN;
        PL->size++;
     }

 }
 ////////////////////////////////////////////////////////////
 void List_VoidDelete(int pos,list * pl ,int * age,int *id )
 {
     listnode * ptr , * ptr2;
     if(List_intIsEmpty(pl))
	{
		printf("the list is empty\n");
	}
	else
    {

     if (pos==0)
     {
         *age=pl->head->age;
         *id=pl->head->id;
         ptr2=pl->head->next;
         free(pl->head);
         pl->head=ptr2;

     }
     else
    {
      ptr=pl->head;
      for(int i=0;i<pos-1;i++)
      {
          ptr=ptr->next;
      }
      *age=pl->head->age;
         *id=pl->head->id;
      ptr2=ptr->next->next;
      free(ptr2->next);
      ptr->next=ptr2;
    }
    pl->size--;
 }
 }
 ///////////////////////////

    void List_VoidPrint(list*pl)
    {

        listnode*ptr=pl->head;
        while(ptr!= NULL)
        {
            printf("ID is %d\n",ptr->id);
            printf("AGE is %d\n",ptr->age);
            fflush(stdin);
            printf("name is %s\n",ptr->name);
            printf("gender is %s\n",ptr->gender);

            ptr=ptr->next;
        }

    }
   ///////////////////////////////////
int  List_intIsEmpty(list* pl)
{
  return pl->head==NULL; //p1->size ==0

}
/////////////////////////////////////////
int  List_intSize(list* pl)
{
    return pl->size;
}
////////////////////////////////////////////

int checkpass (int pass)
{    int flag=0;
int x=0;

while(1)
{
    switch(pass)
    {
        case 1234:
    { printf("\nHello admin\n\n"); flag =1; return flag;}
    default: {printf("\nPassword is not correct");
     if(x==2){exit(1);}
     x++;
      printf ("\nPlease enter your password again  ");
      scanf("%d",&pass); break; }
    }
    }
return flag;
}
//////////////////////////
void list_VoidReplace_Age(int pos_toedit,list *pl,int newage)
{
  listnode*ptr;
  int i;
  for(ptr=pl->head, i=0;i<pos_toedit;i++)
  {
      ptr=ptr->next;
  }
ptr->age=newage;
}
////////////////////////////////////////////////////
void list_VoidReplace_ID(int pos_toedit,list *pl,int newid)
{
  listnode*ptr;
  int i;
  for(ptr=pl->head, i=0;i<pos_toedit;i++)
  {
      ptr=ptr->next;
  }
ptr->id=newid;
}
////////////////////////
void list_VoidReplace_name(int pos_toedit,list * pl, char newname[])
{
    listnode*ptr;
    int i;
     for(ptr=pl->head,i=0;i<pos_toedit;i++)
  {
      ptr=ptr->next;
  }
  strcpy(ptr->name,newname);

}
/////////////////////////////////////
void list_VoidReplace_gender(int pos_toedit,list * pl, char newgender[])
{
    listnode*ptr;
    int i;
     for(ptr=pl->head, i=0;i<pos_toedit;i++)
  {
      ptr=ptr->next;
  }
  strcpy(ptr->gender,newgender);
}
////////////////////Id search function al id mawgood wla laa
struct listnode * idsearch (int idkey , list * pl )
 {
     struct listnode*ptr;
     ptr=pl->head;

     while(ptr!=NULL)
     {
         if((ptr->id)==idkey)
            { return ptr;}
         ptr=ptr->next;

     }
      return NULL;
 }
 ////////////////////////////////////////////////
 void Reservation (int key ,int choice,list *pl)  ///key = id  //choice is date
{
	struct listnode * ptr;
	if(idsearch(key,pl)!=NULL)  //lw rag3 null so id doesnt exist
	{  //KEDA AL ID MAWGOOD
		if (choice==1) //////////////LW ALM3AD ALAWAL
		{
			ptr->date=choice;
			arr[0]=ptr;
		}
		else if (choice==2)
		{
			ptr->date=choice;
			arr[1]=ptr;
		}
		else if (choice==3)
		{
			ptr->date=choice;
			arr[2]=ptr;
		}
		else if (choice==4)
		{
			ptr->date=choice;
			arr[3]==ptr;
		}
		else if (choice==5)
		{
			ptr->date=choice;
			arr[4]==ptr;
		}
	}
	else if (idsearch(key,pl)==NULL)
	{
		printf("This Patient Is Not Registered -_-\n");
	}
}//8-check Reservation
//......................
void CheckReserv (int key,list * pl) //btakhod al id we lw 7agz hat3rd byanato lw msh 7agz y2olan id msh mawgpd fy al7agz
{
	struct listnode * ptr ;
    ptr=idsearch(key,pl);
	if(ptr!=NULL)//to check if the id is exist or not
	{
		if(arr[0]==ptr)//to check if the paitent reserve or not
		{
			printf("This ID Is Already Reserved (2:00-2:30)\n");
			patientdata(key,&L);//to display the paitent file
		}
		else if (arr[1]==ptr)
		{
			printf("This ID Is Already Reserved (2:30-3:00)\n");
			patientdata(key,&L);//to display the paitent file
		}
		else if (arr[2]==ptr)
		{
			printf("This ID Is Already Reserved (3:00-3:30)\n");
			patientdata(key,&L);//to display the paitent file
		}
		else if (arr[3]==ptr)
		{
			printf("This ID Is Already Reserved (3:30-4:00)\n");
			patientdata(key,&L);//to display the paitent file
		}
		else if (arr[4]==ptr)
		{
			printf("This ID Is Already Reserved (4:00-4:30)\n");
			patientdata(key,&L);//to display the paitent file
		}
		else{/*printf("This id didnt reserve before ")*/}
	}
	else if (ptr==NULL)
	{
		printf("This ID Is Not Exist -_-\n");
	}
}
////////////////////////////////////////////////
void CancelReserv (int key,int choice,list * pl)
{
	struct listnode * ptr;
	ptr=idsearch(key,pl); //keda ptr hyshawr 3la node aly fyha al id
	ptr->date=choice;
	if (ptr->date==1)
	{
		//it will empty the paitent fail
		arr[0]=NULL;
	}
	else if (ptr->date==2)
	{
		arr[1]=NULL;
	}
	else if (ptr->date==3)
	{
		arr[2]=NULL;
	}
	else if (ptr->date==4)
	{
		arr[3]=NULL;
	}
	else if (ptr->date==5)
	{
		arr[4]=NULL;
	}

}
////////////////////////////////////////
void patientdata (int key ,list * pl)
{
	struct listnode * ptr;
	int i;
	if(idsearch(key,pl)!=NULL)
	{
        ptr=idsearch(key,&L);
		printf("\n\nThe Paitent ID Is : %d",ptr->id);
		printf("\nThe Paitent Age Is : %d",ptr->age);
		printf("\nThe Paitent Gender Is : %s",ptr->gender);
		printf("\nThe Paitent name Is : %s",ptr->name);
		printf("\n");
		printf("\nThe Paitent Date Is : %d\n",ptr->date);
	}
    else if (idsearch(key,pl)==NULL)
	{
		printf("This Paitent Is Not Registered -_- \n");
	}
}
///////////////////
void CheckPrint (void)
{

	if (arr[0]==NULL)
	{
		printf("The First Date from 2PM T0 2:30PM To Choice Enter  1 : \n");
	}
	if (arr[1]==NULL)
	{
		printf("The Second Date From 2:30PM To 3PM To Choice Enter 2 : \n");
	}
	if (arr[2]==NULL)
	{
		printf("The Third Date From 3PM To 3:30PM To Choice Enter  3 : \n");
	}
	if (arr[3]==NULL)
	{
		printf("The Fourth Date From 3:30PM To 4PM To Choice Enter 4 : \n");
	}
	if (arr[4]==NULL)
	{
		printf("The Fifth Date From 4PM To 4:30PM To Choice Enter  5 : \n");
	}
}
///////////////////////////////////////////////////////
void displayreservations (list * pl)
{
    listnode*ptr;

   if (arr[0]!=NULL)
	{
	    ptr=arr[0];
		printf("\nID %d has a reservation at 2:00 to 2:30\n ",ptr->id);
	}
	   if (arr[1]!=NULL)
	{
	    ptr=arr[1];
		printf("\nID %d has a reservation at 2:30 to 3:00\n ",ptr->id);
	}
	   if (arr[2]!=NULL)
	{
	    ptr=arr[2];
		printf("\nID %d has a reservation at 3:00 to 3:30 \n",ptr->id);
	}
	   if (arr[3]!=NULL)
	{
	    ptr=arr[3];
		printf("\nID %d has a reservation at 3:30 to 4:00\n",ptr->id);
	}
	   if (arr[4]!=NULL)
	{
	    ptr=arr[4];
		printf("\nID %d has a reservation at 4:00 to 4:30\n ",ptr->id);
	}
}


