int commonFactors(int a, int b)
{
    int e=0;
    for(int i=1;i<=(a>b?b:a);i++)
    {
        if(a%i==0 && b%i==0)
        e++;
    }
    return e;
}