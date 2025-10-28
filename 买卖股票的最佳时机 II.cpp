int maxProfit(int* prices, int pricesSize) {
    int maxpro;
    for (int p=0; p<pricesSize-1;)
    {
        if (prices[++p]>prices[p-1])
        {
            maxpro+=prices[p]-prices[p-1];
        }
    }
    return maxpro;
}