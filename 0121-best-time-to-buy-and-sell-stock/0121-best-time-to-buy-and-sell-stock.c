int maxProfit(int* prices, int pricesSize) {
    int min= INT_MAX;
    int sol=0;
    for(int i=1;i<pricesSize;i++){
        min=(min<prices[i-1]?min:prices[i-1]);
        int currentProfit = prices[i]-min;
        sol=(sol>currentProfit) ? sol:currentProfit;
    }
    return sol;
}