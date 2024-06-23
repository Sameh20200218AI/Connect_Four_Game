#include <iostream>
#include<windows.h>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
class Game
{
private:
    char board[6][7];
public:

    int cnt=0;
    Game()
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<7;j++){
                board[i][j]=' ';
            }
        }
    }
    void print()
    {
         SetConsoleTextAttribute(h,3);
        cout <<endl;
        cout <<"    0      1      2      3      4      5      6"<<endl;
        cout <<"--------------------------------------------------"<<endl;

        for(int i=0;i<6;i++)
        {
            cout <<"|  ";
            for(int j=0;j<7;j++)
            {
                if(board[i][j]=='X')
                {
                    SetConsoleTextAttribute(h,14);
                    cout << board[i][j] ;
                }
                else if(board[i][j]=='O')
                {
                    SetConsoleTextAttribute(h,10);
                    cout << board[i][j] ;
                }
                else
                {
                 SetConsoleTextAttribute(h,3);
                    cout << " " ;
                }

                 SetConsoleTextAttribute(h,3);
                cout <<"   |  ";
            }
            cout <<endl;
              cout <<"--------------------------------------------------"<<endl;

        }

    }
    bool isFull()
    {
        for(int i=0;i<7;i++)
        {
            if(board[0][i]==' ')
                return false;
        }
        return true;
    }
    void insert_At_Board()
    {
        cnt++;
        int col;
        if(cnt%2 !=0 )   // player x is insert
        {
             SetConsoleTextAttribute(h,14);
            cout <<"PLayer X : enter a number of column : "<<endl;
            cin >> col;
            while(col >6 || col <0)
            {
                 cout <<"PLayer X : invalid this number of column !!!!!!! "<<endl;
                  cout <<"PLayer X : enter a number of column again : "<<endl;
                  cin >> col;
            }

            while(board[0][col]!=' ')
            {
                cout <<"The col "<< col <<" is full !!!"<<endl;
                cout <<"PLayer X : enter a number of column again : "<<endl;
                cin >> col;
                while(col >6 || col <0)
                {
                    cout <<"PLayer X : invalid this number of column !!!!!!! "<<endl;
                     cout <<"PLayer X : enter a number of column again : "<<endl;
                    cin >> col;
                }
            }


                for(int i=5;i>=0;i--)
                {
                    if(board[i][col]==' ')
                    {
                        board[i][col] = 'X';
                        break;
                    }
                }

        }
        else
        {
             SetConsoleTextAttribute(h,10);
            cout <<"PLayer O : enter a number of column : "<<endl;
            cin >> col;
            while(col >6 || col <0)
            {
                 cout <<"PLayer O : invalid this number of column !!!!!!! "<<endl;
                  cout <<"PLayer O : enter a number of column again : "<<endl;
                  cin >> col;
            }

            while(board[0][col]!=' ')
            {
                cout <<"The col "<< col <<" is full !!!"<<endl;
                cout <<"PLayer O : enter a number of column again : "<<endl;
                cin >> col;
                while(col >6 || col <0)
                {
                    cout <<"PLayer O : invalid this number of column !!!!!!! "<<endl;
                     cout <<"PLayer O : enter a number of column again : "<<endl;
                    cin >> col;
                }
            }


                for(int i=5;i>=0;i--)
                {
                    if(board[i][col]==' ')
                    {
                        board[i][col] = 'O';
                        break;
                    }
                }

        }

    }
    bool is_Win()
    {
        for(int i=0;i<6;i++) // horizontalchecking
        {
            int c=1;
            for(int j=4;j<7;j++)
            {
                if(board[i][3]==board[i][j] &&board[i][3]!=' '&&board[i][j]!=' ')
                {
                    c++;
                }
                else
                    break;
            }
            for(int j=2;j>=0;j--)
            {
              if(board[i][3]==board[i][j] &&board[i][3]!=' '&&board[i][j]!=' ')
                {
                    c++;
                }
                else
                    break;
            }
            if(c>=4)
                return true;
            c=1;

        }
        // check for cardinality
        for(int i=0;i<7;i++)
        {
            int c=1;
            for(int j=4;j<7;j++)
            {
                if(board[3][i]==board[j][i] &&board[3][i]!=' '&&board[j][i]!=' ')
                {
                    c++;
                }
                else
                    break;
            }
            for(int j=2;j>=0;j--)
            {
              if(board[3][i]==board[j][i] &&board[3][i]!=' '&&board[j][i]!=' ')
                {
                    c++;
                }
                else
                    break;
            }
            if(c>=4)
                return true;
            c=1;

        }
        // checking for \\ diagonal
        for(int i=0;i<6;i++)
        {
            int k = i;
            int cnt =1;
            for(int j = 3;j<6&& k<5;j++)
            {

                if(board[i][3]==board[k+1][j+1]&&board[i][3]!=' '&&board[k+1][j+1]!=' ')
                {
                    cnt++;
                    k++;
                }
                else
                    break;
            }
             if(cnt>=4)
                return true;
            k=i;
            for(int j=3;j>0&&k>0;j--)
            {
                if(board[i][3]==board[k-1][j-1]&&board[i][3]!=' '&&board[k-1][j-1]!=' ')
                {
                    cnt++;
                    k--;
                }
                else
                    break;
            }
            k=i;
            if(cnt>=4)
                return true;
            cnt=1;
        }
         // checking for // diagonal
        for(int i=0;i<6;i++)
        {
            int k = i;
            int cnt =1;
            for(int j = 3;j<6&& k>0;j++)
            {

                if(board[i][3]==board[k-1][j+1]&&board[i][3]!=' '&&board[k-1][j+1]!=' ')
                {
                    cnt++;
                    k--;
                }
                else
                    break;
            }
             if(cnt>=4)
                return true;
            k=i;
            for(int j=3;j>0&&k<5;j--)
            {
                if(board[i][3]==board[k+1][j-1]&&board[i][3]!=' '&&board[k+1][j-1]!=' ')
                {
                    cnt++;
                    k++;
                }
                else
                    break;
            }
            k=i;
            if(cnt>=4)
                return true;
            cnt=1;
        }
        return false;
    }

};
int main()
{
    SetConsoleTextAttribute(h,3);
   Game sameh_raouf;
   while(sameh_raouf.isFull()==false)
   {
      sameh_raouf.print();
      sameh_raouf.insert_At_Board();
      if(sameh_raouf.is_Win()==true)
      {
          sameh_raouf.print();
          if(sameh_raouf.cnt%2==0)
          {
               SetConsoleTextAttribute(h,10);
              cout <<"player O is the winner "<<endl;
          }
          else
          {
               SetConsoleTextAttribute(h,14);
               cout <<"player X is the winner "<<endl;
          }

            SetConsoleTextAttribute(h,7);
            return 0;
      }
   }
  sameh_raouf.print();
   SetConsoleTextAttribute(h,4);
  cout <<"---------------------"<<endl;
  cout <<"|     Draw Game     |"<<endl;
   cout <<"---------------------"<<endl;
   SetConsoleTextAttribute(h,7);
    return 0;
}
