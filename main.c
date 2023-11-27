#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"clinic.h"
int PosOfId [1000];
int po=0;
int user;


int main()
{
    while(1)
    {
    printf("FOR ADMIN MODE PRESS 1\n\t********************\nFOR USER MODE PRESS 2\n\t********************\n");
    scanf("%d",&user);
    switch (user)
    {
    case 1:
    {/////////////////////ADMIN MODE
            printf("\t\tADMIN MODE\n");


    ////PASSOWRD CHECK
    int pass, z;
    int key,choice,key1,choice1;

    printf ("\nPlease enter your passowrd  ");
    scanf("%d",&pass);
    if(z=checkpass(pass))
    {
        ////z=1 passowrd is correct
    }
    else exit(1);
////////////////////////////if pass correct you are in admin mode
    int x=1;

    int operation,id,age,pos;
    char names[30];
    char gender[30];

    int id_toedit;
    int pos_toedit;
    List_VoidInit(&L);

    while(x)
    {

    printf("\nTo add new patient record press 0\nTo print press 1 \nto exit press 2\nTo delete pos press 3\nTo edit patient record press 4\nTo reserve a slot with a doctor press 5\nTo cancel a reservation press 6  \n");
    scanf("%d",&operation);

    switch (operation)
{
///////////////////////////////////////////////////////////////////////////////////////////////////
    case 0:
    {
     printf("\nplease enter the ID  \n");
     scanf("%d",&id);
     printf("\nplease enter the age  \n");
     scanf("%d",&age);
    printf("\nplease enter the name  \n");
    scanf("%s",&names);
    printf("\nplease enter the gender  \n");
    scanf("%s",&gender);
    List_VoidInsert(po,id,age,names,gender,&L);
    PosOfId[po]=id;
    po++;
    break;
    }
//////////////////////////////////////////////////////////////////////
    case 1:
        {

    List_VoidPrint(&L);
    break;
        }
////////////////////////////////////////////////////////////////////
    case 2:
        {
        x=0;
        break;
        }
        /////////////////////////////////////////////////////////////
    case 3:
        {
            int id_todelete;
            printf("\nplease enter ID you want to delete  ");
            scanf("%d",&id_todelete);
            for(int i=0;i<po;i++)
            {
                if(PosOfId[i]==id_todelete)
                {
                    id_todelete=i;
                }

            }

            int age;
            int id;
            List_VoidDelete(id_todelete,&L,&age,&id);
            break;
        }
        ///////////////////////////edit patient record/////////////////////////////////////////////////////////////////////////////////////
    case 4:
        {
            int edit_operation;
            int newage;
            int newid;
            char newname [30];
            char newgender [30];

            printf("\nPress the ID of the patient you want to edit  ");
            scanf("%d",&id_toedit);
            for(int i=0;i<po;i++)
            {
                if(PosOfId[i]==id_toedit)
                {
                    pos_toedit=i;
                }

            }

            printf ("\nTo edit Age press 1 \nTo edit Id press 2\nTo edit name press 3\nTo edit gender press 4 \n");
            scanf("%d",&edit_operation);
            switch (edit_operation)
          {
           ////edit age
           case 1: { printf("\nEnter the new age  \n"); scanf("%d",&newage); list_VoidReplace_Age(pos_toedit,&L,newage); break;}
           ///////// edit id
           case 2:
            { printf("\nEntet the new ID  \n"); scanf("%d",&newid);
           PosOfId[pos_toedit]=newid;
           list_VoidReplace_ID(pos_toedit,&L,newid); break;}
           /////edit name
           case 3: {printf("\nPlease enter new name  \n"); scanf("%s",&newname);
           list_VoidReplace_name(pos_toedit,&L,newname); break;}

           ////edit gender
           case 4:
           { printf("\nPlease enter new gender  \n"); scanf("%s",&newgender);
               list_VoidReplace_gender(pos_toedit,&L,newgender); break;}
            ////////////////////////////////
            }
            ///////////to reserve with a doctor
        break;}
          case 5:
               {
               CheckPrint();
					printf("Please Enter The Paitent ID : ");
					scanf("%d",&key);
					if(idsearch(key,&L)!=NULL)
					{
					    printf("Please Enter The Date : ");
					    scanf("%d",&choice);
					    CheckReserv(key,&L);
					    Reservation(key,choice,&L);
					    patientdata(key,&L);
					    //still not finished
					}
					else if (idsearch(key,&L)==NULL)
					{
						printf("This ID Is Not Exist -_-\n");
					}
					break ;
               }
          case 6:
            {
                printf("Please Enter paitent ID : ");
					scanf("%d",&key1);
					if (idsearch(key1,&L)!=NULL)
					{
						printf("Please Enter The Date You Want To Cancel ");
						scanf("%d",&choice1);
						CancelReserv(key1,choice1,&L);
					}
					else if (idsearch(key1,&L)==NULL)
					{
						printf("This ID Is Not Exist -_-\n");
					}
					break;
            }


               }

               }
 break;}/////////END OF ADMIN MODE
    case 2:
        {/////////USER MODE
            printf("\t\tUSER MODE\n");

            while(1)
            {
            int useroperation;
    printf("\nTo view patient record press 1\nTo View todays reservation press 2\nTo end press 3 \n");
    scanf("%d",&useroperation);

    switch(useroperation)
    {
        int ID;
        case 1:{ /////////view patient record
        printf("TO view patient record please enter its id \n");
        scanf("%d",&ID);
        patientdata(ID,&L);
        break;}

        case 2:{ ////View todays reservation

        displayreservations(&L);

        break ;}
        case 3: break;
    }
    }









         break;}///////////END OF USER MODE
        }
    }
}//main




