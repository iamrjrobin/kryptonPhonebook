#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct contacts
{
    char name[10];
    char name1[10];
    char address[35];
    char email[20];
    char notes[50];
    char bg[3];
    char phone[15];
    int day;
    int month;
    int year;
} c;
int count;
add()
{
    printf("ADD NEW CONTACT\n\n");
    FILE *rma;
    rma=fopen("PB.txt","a+");
    if (rma==NULL)
    {
        printf("Error");
        exit(1);
    }
    getc(stdin);
    printf("First name:");
    gets(c.name);
    printf("\nLast name:");
    gets(c.name1);
    printf("\nPhone number:");
    gets(c.phone);
    printf("\nAddress:");
    gets(c.address);
    printf("\nEmail:");
    gets(c.email);
    printf("\nBlood group:");
    gets(c.bg);
    printf("\nNotes:");
    gets(c.notes);
    printf("\nDate of birth");
    printf("\nEnter birth day:");
    scanf("%d",&c.day);
    printf("\nEnter birth month:");
    scanf("%d",&c.month);
    printf("\nEnter birth year:");
    scanf("%d",&c.year);
    fwrite(&c,sizeof(c),1,rma);
    fclose(rma);
}
display()
{
    FILE *rma;
    rma=fopen("PB.txt","r");
    system("cls");
    if (rma==NULL)
    {
        printf("Error");
        exit(1);
    }
    while(fread(&c,sizeof(c),1,rma))
        printf("Name:%s %s\nPhone:%s\nAddress:%s\nEmail:%s\nBlood group:%s\nNotes:%s\nDate of birth:%d-%d-%d\n\n",c.name,c.name1,c.phone,c.address,c.email,c.bg,c.notes,c.day,c.month,c.year);
    fclose(rma);
}
search()
{
    char a[15];
    char a1[15];
    char n[15];
    char n1[15];
    char bg1[3];
    char tbg[3];
    char tname[15];
    char tname1[15];
    FILE *rma;
    rma=fopen("PB.txt","r");
    system("cls");
    if (rma==NULL)
    {
        printf("Error");
        exit(1);
    }
    getc(stdin);
    printf("Enter the name you want/Blood group you want to search\n");
    gets(a);
    strcpy(a1,strlwr(a));
    while(fread(&c,sizeof(c),1,rma))
    {
        strcpy(tname,c.name);
        strcpy(tname1,c.name1);
        strcpy(tbg,c.bg);
        strcpy(n,strlwr(tname));
        strcpy(n1,strlwr(tname1));
        strcpy(bg1,strlwr(tbg));
        if((strcmp(n,a1)==0)||((strcmp(n1,a1)==0))||(strcmp(bg1,a1)==0))
        {
            printf("Name:%s %s\nPhone:%s\nAddress:%s\nEmail:%s\nBlood group:%s\nNotes:%s\nDate of birth:%d-%d-%d\n\n",c.name,c.name1,c.phone,c.address,c.email,c.bg,c.notes,c.day,c.month,c.year);

        }
        else
        {
            //printf("Contact not found in list\n");

        }
    }
    fclose(rma);

}
emergency()
{
    int ems;
    system("cls");
    printf("Emergency numbers\n\n");
    printf("Press 1 for security numbers\nPress 2 for fire department numbers\nPress 3 for hospital numbers\nPress 4 to go back to main menu\n");
    scanf("%d",&ems);
    switch(ems)
    {
    case 1:
    {
        printf("RAB 1\n01777710199\n\nRAB 2\n01777710299\n\nRAB 3\n01777710399\nRAB 4\n01777710499\n\nRAB 5\n01777710599\n\nRAB 5\n01777710699\n\nRAB 7\n01777710799\n\nRAB 8\n01777710899\n\nRAB 9\n01777710999\n\nRAB 10\n01777711099\n\nRAB 11\n01777711199\n\nRAB 12\n01777711199\n\nRAB 13\n01777711399\n\nRAB 14\n01777711499\n");
        printf("\n\nUniversal emergency number of Bangladesh - 999\n\n");
        break;
    }
    case 2:
    {
        printf("(02) 9555555, 9556666, 9556667\n");
        printf("\n\nUniversal emergency number of Bangladesh - 999\n\n");
        break;
    }
    case 3:
    {
        printf("Red Cresent\n9330188-89\n\nAnju-Man-E-Mufidull Islam\n7411660, 9336611, 7410786\n\nApan Ambulance\n9125420\nBARDEM\n9661551-60, 8616641-50\n\nDhaka Medical College\n9668690\n\nGreen Ambulance Service\n8612412\n\nHoly Family Hospital\n8311721-25\n\nHeart Hospital\n9801874, 9803302\n\nI C D D R B (Mohakhali)\n8311721-25, 8811751-59\n\nMarkazul-AI-lslam\n9127867, 8114980\n\nMedinova Medical\n8620353\n\nNational Heart\n8114806, 9122560-72\n\nRafa Ambulance\n9110663\n\nShishu Hospital\n8116061-2, 9113512\n\nSouth Asian Hospital\n8616565, 8618282");
        printf("\n\nUniversal emergency number of Bangladesh - 999\n\n");
        break;
    }
    case 4:
    {
        main();
    }
    default:
    {
        emergency();
        break;
    }
    }
}

delete()
{
    char a[15];
    char a1[15];
    struct contacts t, c;
    //int count=0;
    int found=0, count=0;
    FILE *rma, *trma;
    rma=fopen("PB.txt","r");
    trma=fopen("temp.txt","w");
    system("cls");
    if (rma==NULL)
    {
        printf("Error");
        exit(1);
    }
    getc(stdin);
    printf("Enter the name you want to delete\n");
    printf("Enter first name\n");
    gets(a);
    printf("Enter last name\n");
    gets(a1);
    while(fread(&t,sizeof(t),1,rma))
    {
        if((strcmp(t.name,a)==0)&&((strcmp(t.name1,a1)==0)))
        {
            found=1;
            //fwrite(&t,sizeof(t),1,trma);
        }
        else
        {
            fwrite(&t,sizeof(t),1,trma);
        }

    }
    fclose(rma);
    fclose(trma);
    rma=fopen("PB.txt","w");
    trma=fopen("temp.txt","r");
    if(found==0)
    {
        printf("No record found\n");
        while(fread(&t,sizeof(t),1,trma))
        {
            fwrite(&t,sizeof(t),1,rma);
        }
    }
    else
    {
        while(fread(&t,sizeof(t),1,trma))
        {
            fwrite(&t,sizeof(t),1,rma);
        }

        printf("******Deletion successful******\n");
    }
    fclose(rma);
    fclose(trma);
}
mod()
{
    char a[15];
    char a1[15];
    struct contacts t, c;
    int found=0, count=0;
    FILE *rma, *trma;
    rma=fopen("PB.txt","r");
    trma=fopen("temp.txt","w");
    system("cls");
    if (rma==NULL)
    {
        printf("Error");
        exit(1);
    }
    getc(stdin);
    printf("Enter the name you want to modify\n");
    printf("Enter first name\n");
    gets(a);
    printf("Enter last name\n");
    gets(a1);
    while(fread(&t,sizeof(t),1,rma))
    {
        if((strcmp(t.name,a)==0)&&((strcmp(t.name1,a1)==0)))
        {
            found=1;
            printf("Name:%s %s\nPhone:%s\nAddress:%s\nEmail:%s\nBlood group:%s\nNotes:%s\nDate of birth:%d-%d-%d\n\n",t.name,t.name1,t.phone,t.address,t.email,t.bg,t.notes,t.day,t.month,t.year);

            //fwrite(&t,sizeof(t),1,trma);
        }
        else
        {
            fwrite(&t,sizeof(t),1,trma);
        }

    }
    fclose(rma);
    fclose(trma);
    rma=fopen("PB.txt","w");
    trma=fopen("temp.txt","r");
    if(found==0)
    {
        printf("No record found\n");
        while(fread(&t,sizeof(t),1,trma))
        {
            fwrite(&t,sizeof(t),1,rma);
        }
    }
    else
    {
        //getc(stdin);
        printf("First name:");
        gets(t.name);
        printf("\nLast name:");
        gets(t.name1);
        printf("\nPhone number:");
        gets(t.phone);
        printf("\nAddress:");
        gets(t.address);
        printf("\nEmail:");
        gets(t.email);
        printf("\nBlood group:");
        gets(t.bg);
        printf("\nNotes:");
        gets(t.notes);
        printf("\nDate of birth:");
        printf("\nEnter birth day:");
        scanf("%d",&c.day);
        printf("\nEnter birth month:");
        scanf("%d",&c.month);
        printf("\nEnter birth year:");
        scanf("%d",&c.year);
        fwrite(&t,sizeof(t),1,rma);
        fclose(rma);
        rma=fopen("PB.txt","a+");
        while(fread(&t,sizeof(t),1,trma))
        {
            fwrite(&t,sizeof(t),1,rma);
        }

        printf("\n******Modification successful******\n");
    }
    fclose(rma);
    fclose(trma);
}
reminder()
{
    int chkmonth,chkday;
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    chkmonth=tm.tm_mon+1;
    chkday=tm.tm_mday;
    FILE *rma;
    rma=fopen("PB.txt","r");
    //system("cls");
    if (rma==NULL)
    {
        printf("Error");
        exit(1);
    }
    printf("\t\t      **********Today's birthday event(s)**********\n");
    while(fread(&c,sizeof(c),1,rma))
    {
        if((c.day==chkday)&&(c.month==chkmonth))
        {
            //printf("Name:%s %s\nPhone:%s\nAddress:%s\nEmail:%s\nBlood group:%s\nNotes:%s\nDate of birth:%s\n\n",c.name,c.name1,c.phone,c.address,c.email,c.bg,c.notes,c.day,c.month,c.year);
            printf("\a\a\t\t\t\t%s %s's birthday\n\n\n",c.name,c.name1);
        }
    }
    fclose(rma);
}
main()
{
    system("cls");
    //system("COLOR F");
    system("COLOR 1F");
    int option;
    option=1;
    printf("\n\n");
    while (option==1)
    {
        system("cls");
        reminder();
        printf("\t\t\t\tPress 1 to add new contacts\n\t\t\t\tPress 2 to see all contacts\n\t\t\t\tPress 3 to search a contact\n\t\t\t\tPress 4 to delete contacts\n\t\t\t\tPress 5 to modify contacts\n\t\t\t\tPress 6 for emergency numbers\n\t\t\t\tPress 0 to exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            system("cls");
            add();
            break;
        }
        case 2:
        {
            system("cls");
            display();
            break;
        }
        case 3:
        {
            system("cls");
            search();
            break;
        }
        case 4:
        {
            system("cls");
            delete();
            break;
        }
        case 5:
        {
            system("cls");
            mod();
            break;
        }
        case 6:
        {
            system("cls");
            emergency();
            break;
        }
        case 0:
        {
            exit(1);
        }
        default :
        {
            //system("cls");
            printf("Wrong input\n");
            main();
        }
        }
        printf ("\nDo you want to continue(1=Y, any to exit)?\n");
        scanf    ("%d", &option);
    }
}
