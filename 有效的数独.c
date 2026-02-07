#include <stdbool.h>
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    boardSize=9;
    *boardColSize=9;
    int rows[9][9]={0};
    int cols[9][9]={0};
    int ninebox[3][3][9]={0};
    for (int i = 0; i <9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j]!='.')
            {
                rows[i][board[i][j]-'0'-1]++;
                cols[j][board[i][j]-'0'-1]++;
                ninebox[i/3][j/3][board[i][j]-'0'-1]++;
            }
            
        }
    }
    for (int i = 0; i <9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (rows[i][j]>1||cols[i][j]>1)
            {
                return 0;
            }
            
        }
    }
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            for (int t= 0; t <9; t++)
            {
                if (ninebox[i][j][t]>1)
                {
                    return 0;
                }
                
            }
        }
        
    }
    return 1;
}