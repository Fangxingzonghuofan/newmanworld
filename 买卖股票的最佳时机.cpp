int maxProfit(int* prices, int pricesSize) {
    int minprices,maxprofit;
    minprices=prices[0];
    for (int i = 0; i < pricesSize; i++)
    {
        if (minprices>prices[i])
        {
            minprices=prices[i];
        }
        
        if (maxprofit<prices[i]-minprices)
        {
        maxprofit=prices[i]-minprices;
        }        
    }
    return maxprofit;
    
}