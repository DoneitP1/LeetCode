bool isHappy(int n) {
    int current = n, sumOfSquares;
    while (current > 9) {
        sumOfSquares = 0;
        while (current > 0) {
            int digit = current % 10;
            sumOfSquares += digit * digit;
            current /= 10;
        }
        current = sumOfSquares;
    }
    return (current == 1 || current == 7);
}