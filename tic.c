#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char a[3][3]={'o','o','o','o','o','o','o','o','o'},truth=1;

void display()
{
    int i,j;
    printf("\n\n\tTHE CURRENT STACKING\n\n\n");
    for(i=0;i<3;i++)
    {
        printf("\t-------------------\n\t");
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='o')
            {
                printf("|     ");
            }
            else
            {
                printf("|  %c  ",a[i][j]);
            }
        }
        printf("|");
        printf("\n");
    }
    printf("\t-------------------\n\t");

}

void turn(int player)
{
    int r,c;
    x:
    switch(player)
    {
        case 0 :    printf("\n\n\tPLAYER A : ");
                    r = (int)getch() - 48;
                    printf("%d ",r);
                    c = (int)getch() - 48;
                    printf("%d ",c);
                    if( r>0 && r<=3 && c>0 && c<=3 && a[r-1][c-1]=='o')
                        a[r-1][c-1]='A';
                    else
                    {
                        system("CLS");
                        printf("________________________________________________________________________________");
                        printf("\n\n\tINVALID OPTION\n");
                        display();
                        goto x;
                    }
                    break;
        case 1 :    printf("\n\n\tPLAYER B : ");
                    r = (int)getch() - 48;
                    printf("%d ",r);
                    c = (int)getch() - 48;
                    if( r>0 && r<=3 && c>0 && c<=3 && a[r-1][c-1]=='o')
                        a[r-1][c-1]='B';
                    else
                    {
                        system("CLS");
                        printf("________________________________________________________________________________");
                        printf("\n\n\tINVALID OPTION\n");
                        display();
                        goto x;
                    }
                    break;
    }
}
void check_row()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        int counta=0;
        int countb=0;
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='A')
                counta++;
            if(a[i][j]=='B')
                countb++;
        }
        if(counta==3)
        {
            system("CLS");
            printf("________________________________________________________________________________\n\n\n");
            display();
            printf("\n\n\tPLAYER A WINS!!");
            truth=0;
            break;
        }
        if(countb==3)
        {
            system("CLS");
            printf("________________________________________________________________________________\n\n\n");
            display();
            printf("\n\n\tPLAYER B WINS!!");
            truth=0;
            break;
        }
    }
}

void check_column()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        int counta=0;
        int countb=0;
        for(j=0;j<3;j++)
        {
            if(a[j][i]=='A')
                counta++;
            if(a[j][i]=='B')
                countb++;
        }
        if(counta==3)
        {
            system("CLS");
            printf("________________________________________________________________________________\n\n\n");
            display();
            printf("\n\n\tPLAYER A WINS!!");
            truth=0;
            break;
        }
        if(countb==3)
        {
            system("CLS");
            printf("________________________________________________________________________________\n\n\n");
            display();
            printf("\n\n\tPLAYER B WINS!!");
            truth=0;
            break;
        }
    }
}

void check_diagonal1()
{
    int i,j;
    int counta=0;
    int countb=0;
    for(j=0;j<3;j++)
    {
        if(a[j][j]=='A')
            counta++;
        if(a[j][j]=='B')
            countb++;
    }
    if(counta==3)
    {
        system("CLS");
        printf("________________________________________________________________________________\n\n\n");
        display();
        printf("\n\n\tPLAYER A WINS!!");
        truth=0;
    }
    if(countb==3)
    {
        system("CLS");
        printf("________________________________________________________________________________\n\n\n");
        display();
        printf("\n\n\tPLAYER B WINS!!");
        truth=0;
    }

}

void check_diagonal2()
{
    int i,j;
    int counta=0;
    int countb=0;
    for(j=0,i=2;j<3;j++,i--)
    {
        if(a[j][i]=='A')
            counta++;
        if(a[j][i]=='B')
            countb++;
    }
    if(counta==3)
    {
        system("CLS");
        printf("________________________________________________________________________________\n\n\n");
        display();
        printf("\n\n\tPLAYER A WINS!!");
        truth=0;
    }
    if(countb==3)
    {
        system("CLS");
        printf("________________________________________________________________________________\n\n\n");
        display();
        printf("\n\n\tPLAYER B WINS!!");
        truth=0;
    }

}

void main()
{
    system("COLOR FC");
    int i;
    for(i=0;truth==1;i++)
    {
        system("CLS");
        printf("________________________________________________________________________________\n\n\n");
        display();
        turn(i%2);
        check_row();
        check_column();
        check_diagonal1();
        check_diagonal2();
        if(i==8 && truth ==1)
        {
            system("CLS");
            printf("________________________________________________________________________________\n\n\n");
            display();
            printf("\n\n\tTHIS MATCH IS A DRAW ");
            break;
        }
    }
    printf("\n\n\n\t");
    system("PAUSE");
}
