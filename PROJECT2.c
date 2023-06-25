#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  list
{
    char name[100];
    char phone[15];
    char email[100];
    char add[100];

} li,check;

int main()
{
    int choice;
    printf("\n\t\t      <   MENU  >       ");
    printf("\n\n");
    printf("\n\t[1] Add Contact");
    printf("\n\t[2] Search Contact");
    printf("\n\t[3] List Of Contacts");
    printf("\n\t[4] Add To Favourites");
    printf("\n\t[5] List Of Favourites");
    printf("\n\t[0] Exit");
    printf("\n");
    printf("\n\tEnter your Choice: ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
    case 1:
        addcontact();
        break;
    case 2:
        searchcontact();
        break;
    case 3:
        listcontact();
        break;
    case 4:
        addfav();
        break;
    case 5:
        viewfav();
        break;
    case 0:
        return 0;
        break;
    default:
        printf("\t\t Enter correct choice");
    }
}


void addcontact()
{
    printf("\t Enter Name:  ");
    scanf("%s",li.name);
    printf("\t Enter Phone number:  ");
    scanf("%s",li.phone);
    printf("\t Email: ");
    scanf("%s",li.email);
    printf("\t Enter Address:  ");
    scanf("%s",li.add);

    int len=strlen(li.phone);
    if(len == 11)
    {
        FILE *fp;
        fp=fopen("contact.txt","a");
        fputs(li.name,fp);
        fprintf(fp,"\t");
        fputs(li.phone,fp);
        fprintf(fp,"\t");
        fputs(li.email,fp);
        fprintf(fp,"\t");
        fputs(li.add,fp);
        fprintf(fp,"\n");
        printf("\n\t Contact Added Successfully");
        fclose(fp);
    }
    else
    {
        printf("\t Enter 11 Digit Phone Number Only");
    }
    main();
}

void listcontact()
{
    int f=0;
    FILE *fp;
    fp = fopen("contact.txt","r");


    printf("\t\t       <LIST OF CONTACTS>       \n");


    while(fscanf(fp,"%s %s %s %s\n",li.name,li.phone,li.add,li.email) != EOF)
    {
        f=1;
        printf("\t\tName: %s\n",li.name);
        printf("\t\tPhone: %s\n",li.phone);
        printf("\t\tAddress: %s\n",li.add);
        printf("\t\tEmail: %s\n",li.email);
        printf("\n");
    }
    fclose(fp);
    if(f == 0)
    {
        printf("\t\t No Record Found \n\n");

    }
    main();
}

void searchcontact()
{
    int f=0;
    FILE *fp;
    fp = fopen("contact.txt","r");

    printf("\t\t       <SEARCH CONTACT>       \n");
    printf("\t\tEnter name : ");
    fflush(stdin);
    gets(check.name);

    while(fscanf(fp,"%s %s %s %s\n",li.name,li.phone,li.add,li.email) != EOF)
    {
        if(strcmpi(check.name,li.name)==0)
        {
            f=1;
            printf("\t\tName    : %s\n",li.name);
            printf("\t\tPhone   : %s\n",li.phone);
            printf("\t\tAddress : %s\n",li.add);
            printf("\t\tEmail   : %s\n",li.email);

            break;
        }

    }
    fclose(fp);
    if(f == 0)
    {
        printf("\t\tCould not found the name\n\n");

    }
    main();
}

void addfav()
{
    int f=0;
    FILE *fp;
    FILE *fv;
    fp = fopen("contact.txt","r");

    printf("\t\t       <ADD FAVOURITE>       \n");
    printf("\t\tEnter name : ");
    fflush(stdin);
    gets(check.name);

    while(fscanf(fp,"%s %s %s %s\n",li.name,li.phone,li.add,li.email) != EOF)
    {
        if(strcmpi(check.name,li.name)==0)
        {
            f=1;
            fv = fopen("fav.txt","a") ;
            fprintf(fv,"%s ",li.name);
            fprintf(fv,"%s ",li.phone);
            fprintf(fv,"%s ",li.add);
            fprintf(fv,"%s ",li.email);
            fprintf(fv,"\n");
            printf("\t Successfully Added to Favourite");
            fclose(fv);
            break;
        }

    }
    fclose(fp);
    if(f == 0)
    {
        printf("\t\tCould not found the name\n\n");
    }
    main();
}

void viewfav()
{
    int f=0;
    FILE *fp;
    fp = fopen("fav.txt","r");


    printf("\t\t       <LIST OF FAVOURITES>      \n");

    while(fscanf(fp,"%s %s %s %s\n",li.name,li.phone,li.add,li.email) != EOF)
    {
        f=1;
        printf("\t\tName: %s\n",li.name);
        printf("\t\tPhone: %s\n",li.phone);
        printf("\t\tAddress: %s\n",li.add);
        printf("\t\tEmail: %s\n",li.email);
        printf("\n");
    }
    fclose(fp);
    if(f == 0)
    {
        printf("\t\t No Record Contact\n\n");
    }
    main();

}

