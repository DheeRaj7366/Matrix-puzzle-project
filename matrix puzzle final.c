#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<dos.h>
#include<conio.h>
int matrix[16];
int Final_matrix[4][4];//random matrix
int winning_matrix[4][4]={{1,2,3,4},{5,6,7,8,},{9,10,11,12},{13,14,15,16}};//winning condition matrix
void fill_random(int a[16],int max);//create one-D array with 1-16 uniquely
void array_convert(int a[16]);//one-D array to matrix conversion
void display_matrix(int mat[4][4]);//for printing matrix
void print_rule_and_welcome();//printing rule and welcome with different colors
void print_lose_page();//printing lose page
void delay(unsigned int);//printing invalid move for a short time
int main()
{
    char player[20];//creating player
    char choice='y';
    while(choice=='y')//this loop will execute till we want to play
    {
     system("cls");
     printf("\n\n\n");
     printf("Player name: ");
     fgets(player,20,stdin);//getting player name
     player[strlen(player)-1]='\0';
     system("cls");
     print_rule_and_welcome();
     printf("press any key to start.....");
     getch();
     system("cls");
     int move=10;//number of moves we want to try
    srand(time(NULL));
    int min,max,i,temp=0;
    min=1;
    max=min+16;
    fill_random(matrix,max);
    array_convert(matrix);
    while(move)
    {
        system("cls");
        printf("\n\n  Player name: %s , Move remaining : %d\n\n",player,move);
        display_matrix(Final_matrix);
        int key,i,j,flag=0;
        key=getch();
        switch(key)
        {
            case 77:
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       if(Final_matrix[i][j]==16)
                     {
                          temp=Final_matrix[i][j-1];
                         if(j-1==-1)
                         {
                             printf("invalid move");
                             delay(500);
                             system("cls");
                             break;
                         }
                         else
                         {
                            Final_matrix[i][j-1]=16;
                            Final_matrix[i][j]=temp;
                            move--;
                            flag=1;
                            system("cls");
                            break;
                         }
                     }
                    }
                    if(flag==1)
                        break;
                }
            break;
            case 75:
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       if(Final_matrix[i][j]==16)
                     {
                          temp=Final_matrix[i][j+1];
                         if(j+1==4)
                         {
                             printf("invalid move");
                             delay(500);
                             system("cls");
                             break;
                         }
                     else
                     {
                         Final_matrix[i][j+1]=16;
                      Final_matrix[i][j]=temp;
                      flag=1;
                        move--;
                        system("cls");
                      break;
                     }

                     }
                    }
                    if(flag==1)
                        break;

                }

            break;
             case 80:
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       if(Final_matrix[i][j]==16)
                     {
                      temp=Final_matrix[i-1][j];
                      if(i-1==-1)
                      {
                          printf("invalid move");
                          delay(500);
                          system("cls");
                          break;
                      }
                      else
                      {
                          printf("%d",temp);
                        Final_matrix[i-1][j]=16;
                        Final_matrix[i][j]=temp;
                        flag=1;
                        move--;
                        system("cls");
                        break;
                      }

                     }
                    }
                    if(flag==1)
                        break;

                }
            break;
            case 'e': exit(0);
            case 'E': exit(0);    
             case 72:
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(Final_matrix[i][j]==16)
                        {
                            temp=Final_matrix[i+1][j];
                            if(i+1==4)
                            {
                                printf("invalid move");
                                delay(500);
                                system("cls");
                                break;
                            }
                            else
                            {
                               Final_matrix[i+1][j]=16;
                               Final_matrix[i][j]=temp;
                               flag=1;
                               move--;
                               system("cls");
                            break;
                            }

                        }
                    }
                    if(flag==1)
                        break;
                }
                break;
        }
        //checking the situation
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(Final_matrix[i][j]==winning_matrix[i][j])
                {
                    system("cls");
                    printf("You Won");
                    break;
                }
                else break;
            }
        }

        if(move==0)
            break;
    }
           print_lose_page();
            printf("enter 'y' to play again: ");
           choice = getch();
    }

    return 0;
}
void fill_random(int matrix[16],int max)
{
    int temp,i,j;
    for(i=0;i<16;i++)
    {
            temp=rand()%max;
            for(j=0;j<=i-1;j++)
            {
                if(temp==matrix[j])
                    break;
                if(temp==0)
                    break;
            }
            if(i==j)
                matrix[i]=temp;
            else
                i--;
        }

    }

void array_convert(int matrix[16])
{
    int b[4][4];
    int i,j,temp=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            b[i][j]=matrix[4*i+j];
        }
    }
    temp=b[3][3];
     for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
           if(b[i][j]==16)
           {
               b[i][j]=temp;
           }
        }
    }
    b[3][3]=16;

     for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
         Final_matrix[i][j]=b[i][j];
        }
    }

}
void display_matrix(int mat[4][4])
{
    int i,j;
      printf("---------------------\n");
     for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {

            if(mat[i][j]==16)
             printf("|%3c ",' ');
            else
             printf("|%3d ",mat[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");

}

void print_rule_and_welcome()
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    printf("%30s\n\n","MATRIX PUZZLE");
    SetConsoleTextAttribute(h,4);
    printf("    %29s\n\n","RULE OF THIS GAME");
    printf(" 1. You can move only 1 step at a time by arrow key\n");
    SetConsoleTextAttribute(h,15);
    printf("        Move Up    : by Up arrow key\n");
    printf("        Move Down  : by Down arrow key\n");
    printf("        Move Left  : by Left arrow key\n");
    printf("        Move Right : by Right arrow key\n");
    SetConsoleTextAttribute(h,4);
    printf(" 2. You can move number at an empty position only\n\n");
    printf(" 3. For each valid move : your total number of move will decreased by 1\n");
    printf(" 4. Winning situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    SetConsoleTextAttribute(h,15);
    printf("              Winning situation:\n");
    SetConsoleTextAttribute(h,6);
    display_matrix(winning_matrix);
    printf("\n");
    SetConsoleTextAttribute(h,4);
    printf(" 5. You can exit the game at any time by pressing 'E' or 'e'\n So Try to win in minimum no of move\n\n");
     SetConsoleTextAttribute(h,15);
    printf("         Happy gaming , Good Luck ");
    SetConsoleTextAttribute(h,14);
    printf("%c %c %c\n\n",2,2,2);
    SetConsoleTextAttribute(h,15);
}
void delay(unsigned int m_second)
{
    clock_t goal = m_second + clock();
    while(goal>clock());
}

void print_lose_page()
{
    system("cls");
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n");
     SetConsoleTextAttribute(h,4);
     printf("             YOU LOSE !\n\n");
     SetConsoleTextAttribute(h,2);
     printf("want to play again ?\n");
     SetConsoleTextAttribute(h,15);
}
