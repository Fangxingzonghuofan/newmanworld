void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows[matrixSize];
    int cols[matrixColSize[0]];
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (matrix[i][j]==0)
            {
                rows[i]=1;
                cols[j]=1;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j <*matrixColSize; j++)
        {
            if (rows[i]==1||cols[j]==1)
            {
                matrix[i][j]=0;
            }
        }
    }
    return;
}