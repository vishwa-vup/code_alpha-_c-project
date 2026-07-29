
#include <iostream>

using namespace std;

const int SIZE = 9;

class SudokuSolver
{
private:
    int board[SIZE][SIZE];

public:
    SudokuSolver()
    {
        int defaultBoard[SIZE][SIZE] =
        {
            {3,0,6,5,0,8,4,0,0},
            {5,2,0,0,0,0,0,0,0},
            {0,8,7,0,0,0,0,3,1},
            {0,0,3,0,1,0,0,8,0},
            {9,0,0,8,6,3,0,0,5},
            {0,5,0,0,9,0,6,0,0},
            {1,3,0,0,0,0,2,5,0},
            {0,0,0,0,0,0,0,7,4},
            {0,0,5,2,0,6,3,0,0}
        };

        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                board[i][j]=defaultBoard[i][j];
            }
        }
    }

    void printBoard()
    {
        cout<<"\n-------------------------------\n";

        for(int i=0;i<SIZE;i++)
        {
            if(i%3==0 && i!=0)
                cout<<"-------------------------------\n";

            for(int j=0;j<SIZE;j++)
            {
                if(j%3==0)
                    cout<<"| ";

                if(board[i][j]==0)
                    cout<<". ";
                else
                    cout<<board[i][j]<<" ";
            }

            cout<<"|\n";
        }

        cout<<"-------------------------------\n";
    }

    bool isSafe(int row,int col,int num)
    {
        for(int x=0;x<SIZE;x++)
        {
            if(board[row][x]==num)
                return false;
        }

        for(int x=0;x<SIZE;x++)
        {
            if(board[x][col]==num)
                return false;
        }

        int startRow=row-row%3;
        int startCol=col-col%3;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[startRow+i][startCol+j]==num)
                    return false;
            }
        }

        return true;
    }

    bool solve()
    {
        int row=-1;
        int col=-1;
        bool empty=false;

        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                if(board[i][j]==0)
                {
                    row=i;
                    col=j;
                    empty=true;
                    break;
                }
            }

            if(empty)
                break;
        }

        if(!empty)
            return true;

        for(int num=1;num<=9;num++)
        {
            if(isSafe(row,col,num))
            {
                board[row][col]=num;

                if(solve())
                    return true;

                board[row][col]=0;
            }
        }

        return false;
    }

    void startSolver()
    {
        cout<<"=============================\n";
        cout<<"     SUDOKU SOLVER\n";
        cout<<"   CodeAlpha Project\n";
        cout<<"=============================\n";

        cout<<"\nOriginal Puzzle\n";
        printBoard();

        if(solve())
        {
            cout<<"\nSolved Puzzle\n";
            printBoard();
        }
        else
        {
            cout<<"\nNo solution exists.\n";
        }
    }
};