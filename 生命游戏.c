void gameOfLife(int** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j <*boardColSize; j++)
        {
            int livecells=0;
            if (i+1<boardSize&&(board[i+1][j]==1||board[i+1][j]==-1)) livecells++;
            if (i-1>=0&&(board[i-1][j]==1||board[i-1][j]==-1)) livecells++;
            if (j+1<*boardColSize&&(board[i][j+1]==1||board[i][j+1]==-1)) livecells++;
            if (j-1>=0&&(board[i][j-1]==1||board[i][j-1]==-1)) livecells++;
            if (i+1<boardSize&&j+1<*boardColSize&&(board[i+1][j+1]==1||board[i+1][j+1]==-1)) livecells++;
            if (i+1<boardSize&&j-1>=0&&(board[i+1][j-1]==1||board[i+1][j-1]==-1)) livecells++;
            if (i-1>=0&&j+1<*boardColSize&&(board[i-1][j+1]==1||board[i-1][j+1]==-1)) livecells++;
            if (i-1>=0&&j-1>=0&&(board[i-1][j-1]==1||board[i-1][j-1]==-1)) livecells++;
            if (board[i][j]==1&&(livecells!=2&&livecells!=3))
            {
                board[i][j]=-1;
            }
            else if(board[i][j]==0&&livecells==3)
            {
                board[i][j]=2;
            }
        }
    }
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            if (board[i][j]==2)
            {
                board[i][j]=1;
            }
            else if (board[i][j]==-1)
            {
                board[i][j]=0;
            }
        }
    }
    return ;
    
}