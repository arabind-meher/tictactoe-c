/**************************************************
---------------------------------------------------
NAME     : TIC TAC TOE
DESIGNER : ARABIND
VRRSION  : 2.0.1
---------------------------------------------------
**************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/**MATRIX FOR THE GRID**/
char ttt[11]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

/**FUNCTIONS TO MODIFY THE GRID**/
int winner();
void changeboard(char,char);
void showboard();
void newboard();
int compturn(char,char);
int compturn1(char);
int compturn2(char);

/**MAIN FUNCTION**/
void main()
{
    int i;
    char a,p1,p2;
    p1 = 'X';
    p2 = 'O';

    printf("\n\n..........WELCOME TO TIC TAC TOE..........\n\n");
    printf("\t  Player 1 = X\n");
    printf("\t  Player 2 = O\n\n");
    system("pause");

    re:
    showboard();

    changeboard(p1,p2);

    r:
    printf("\n\tWant to play again (y/n) : ");
    scanf("%s",&a);

    if(a=='y')
    {
        newboard();
        goto re;
    }
    else if(a=='n')
        printf("\n\n\t*****THANKX FOR PLAYING*****\n");
    else
        goto r;

    system("pause");
}

/**TO PLAY THE GAME**/
void changeboard(char p1, char p2)
{
    int i,a,turn=1,p,x[10],y=0,j;
        /*
            i =
            a = Number entered by user
            p = player (1 || 2)
            x = Entered values of a
            y = Number of data in x
            j = Address of x
            z = Entered by computer
        */

    showboard();

    do
    {
        showboard();

        printf("\n\tTurn %d :- \n",turn);

        {
            if(turn%2!=0)
                p=1;
            else
                p=0;
        }

        z:
        if(p==1)
        {
            printf("\tEnter the number : ",p);
            scanf("%d",&a);
        }
        else
            a=compturn(p1,p2);

        if(a>=1 && a<=9)
        {
            for(j=0;j<y;j++)
            {
                if(x[j]==a)
                {
                    printf("\tInvalid Number\n");
                    goto z;
                }
            }
            x[y]=a;
            y++;
        }
        else
        {
            printf("\tInvalid Number\n");
            goto z;
        }

        ttt[a]=(turn%2!=0)?p1:p2;

        showboard();

        i = winner();

        turn++;

        if(i==1 && p==1)
        {
            printf("\n\tWinner is Player 1.\n");
            break;
        }
        else if(i==1 && p==0)
        {
            printf("\n\tComputer Wins.\n");
            break;
        }
        else if(i==0)
        {
            printf("\n\tGame Draw.\n");
            break;
        }
    }while(i=-1);
}

/**FUNCTION TO CHECK THE GAME'S PROGRESS**/
int winner()
{
    if( ttt[1]==ttt[2] && ttt[2]==ttt[3])
        return 1;

    else if( ttt[4]==ttt[5] && ttt[5]==ttt[6])
        return 1;

    else if( ttt[7]==ttt[8] && ttt[8]==ttt[9])
        return 1;

    else if( ttt[1]==ttt[4] && ttt[4]==ttt[7])
        return 1;

    else if( ttt[2]==ttt[5] && ttt[5]==ttt[8])
        return 1;

    else if( ttt[3]==ttt[6] && ttt[6]==ttt[9])
        return 1;

    else if( ttt[1]==ttt[5] && ttt[5]==ttt[9])
        return 1;

    else if( ttt[3]==ttt[5] && ttt[5]==ttt[7])
        return 1;

    else if( ttt[1]!='1' && ttt[2]!='2' && ttt[3]!='3' && ttt[4]!='4' && ttt[5]!='5' && ttt[6]!='6' && ttt[7]!='7' && ttt[8]!='8' && ttt[9]!='9' )
        return 0;
    else
        return -1;
}

/**FUNCTION TO DISPLAY THE GRID**/
void showboard()
{
    system("CLS");

    printf("\t      _____TIC TAC TOE_____\n\n\n");

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c  \n",ttt[1],ttt[2],ttt[3]);
    printf("\t\t_____|_____|_____\n");

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c  \n",ttt[4],ttt[5],ttt[6]);
    printf("\t\t_____|_____|_____\n");

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c  \n",ttt[7],ttt[8],ttt[9]);
    printf("\t\t     |     |     \n\n");
}

/**NEW BOARD**/
void newboard()
{
    char a=49;
    int i;

    for(i=1;i<11;i++)
    {
        ttt[i]=a;
        a++;
    }

    showboard();
}

/**COMPUTER'S TURN**/
int compturn(char p1, char p2)
{
    int a,b,c,i=2;

    a=compturn1(p1);
    b=compturn2(p2);

    if(a==0 && b==0)
        return 1+rand()%9;

    if(ttt[b]=b+48)
    {
        ttt[b]=p2;
        i=winner();

        if(i==1)
            return b;

        else
            ttt[b]=b+48;
    }

    if(ttt[a]=a+48 && i!=1)
        return a;
    else
        return 1+rand()%9;
}

/**COMPUTER CHECKS FOR HIS ADVANTAGE**/
int compturn1(char p1)
{
    int p;

    if(ttt[1]==p1 && ttt[2]==p1)
        p=3;
    else if(ttt[1]==p1 && ttt[3]==p1)
        p=2;
    else if(ttt[2]==p1 && ttt[3]==p1)
        p=1;

    else if(ttt[4]==p1 && ttt[5]==p1)
        p=6;
    else if(ttt[4]==p1 && ttt[6]==p1)
        p=5;
    else if(ttt[5]==p1 && ttt[6]==p1)
        p=4;

    else if(ttt[7]==p1 && ttt[8]==p1)
        p=9;
    else if(ttt[7]==p1 && ttt[9]==p1)
        p=8;
    else if(ttt[8]==p1 && ttt[9]==p1)
        p=7;

    else if(ttt[1]==p1 && ttt[4]==p1)
        p=7;
    else if(ttt[1]==p1 && ttt[7]==p1)
        p=4;
    else if(ttt[4]==p1 && ttt[7]==p1)
        p=1;

    else if(ttt[2]==p1 && ttt[5]==p1)
        p=8;
    else if(ttt[2]==p1 && ttt[8]==p1)
        p=5;
    else if(ttt[5]==p1 && ttt[8]==p1)
        p=2;

    else if(ttt[3]==p1 && ttt[6]==p1)
        p=9;
    else if(ttt[3]==p1 && ttt[9]==p1)
        p=6;
    else if(ttt[6]==p1 && ttt[9]==p1)
        p=3;

    else if(ttt[1]==p1 && ttt[5]==p1)
        p=9;
    else if(ttt[1]==p1 && ttt[9]==p1)
        p=5;
    else if(ttt[5]==p1 && ttt[9]==p1)
        p=1;

    else if(ttt[3]==p1 && ttt[5]==p1)
        p=7;
    else if(ttt[3]==p1 && ttt[7]==p1)
        p=5;
    else if(ttt[5]==p1 && ttt[7]==p1)
        p=3;
    else
        return 0;

    if(ttt[p]==p+48)
        return p;
    else
        return 0;
}

/**COMPUTER CHECKS FOR PLAYERS ADVANTAGE**/
int compturn2(char p2)
{
    int p;

    if(ttt[1]==p2 && ttt[2]==p2)
        p=3;
    else if(ttt[1]==p2 && ttt[3]==p2)
        p=2;
    else if(ttt[2]==p2 && ttt[3]==p2)
        p=1;

    else if(ttt[4]==p2 && ttt[5]==p2)
        p=6;
    else if(ttt[4]==p2 && ttt[6]==p2)
        p=5;
    else if(ttt[5]==p2 && ttt[6]==p2)
        p=4;

    else if(ttt[7]==p2 && ttt[8]==p2)
        p=9;
    else if(ttt[7]==p2 && ttt[9]==p2)
        p=8;
    else if(ttt[8]==p2 && ttt[9]==p2)
        p=7;

    else if(ttt[1]==p2 && ttt[4]==p2)
        p=7;
    else if(ttt[1]==p2 && ttt[7]==p2)
        p=4;
    else if(ttt[4]==p2 && ttt[7]==p2)
        p=1;

    else if(ttt[2]==p2 && ttt[5]==p2)
        p=8;
    else if(ttt[2]==p2 && ttt[8]==p2)
        p=5;
    else if(ttt[5]==p2 && ttt[8]==p2)
        p=2;

    else if(ttt[3]==p2 && ttt[6]==p2)
        p=9;
    else if(ttt[3]==p2 && ttt[9]==p2)
        p=6;
    else if(ttt[6]==p2 && ttt[9]==p2)
        p=3;

    else if(ttt[1]==p2 && ttt[5]==p2)
        p=9;
    else if(ttt[1]==p2 && ttt[9]==p2)
        p=5;
    else if(ttt[5]==p2 && ttt[9]==p2)
        p=1;

    else if(ttt[3]==p2 && ttt[5]==p2)
        p=7;
    else if(ttt[3]==p2 && ttt[7]==p2)
        p=5;
    else if(ttt[5]==p2 && ttt[7]==p2)
        p=3;
    else
        p=0;

    if(ttt[p]==p+48)
        return p;
    else
        return 0;
}
