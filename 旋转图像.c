void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int rows,cols;
    int tmp1;
    if (matrixSize%2==0)
    {
        rows=matrixSize/2;
        cols=matrixSize/2;
    }
    else if (matrixSize%2==1)
    {
        rows=matrixSize/2;
        cols=matrixSize/2+1;
    }
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            tmp1=matrix[r][c];
            matrix[r][c]=matrix[matrixSize-c-1][r];
            matrix[matrixSize-c-1][r]=matrix[matrixSize-r-1][matrixSize-c-1];
            matrix[matrixSize-r-1][matrixSize-c-1]=matrix[c][matrixSize-r-1];
            matrix[c][matrixSize-r-1]=tmp1;
        }
    }
    return;
}