class Solution {
public:
  bool isPrime(int n){
      for(int i=2;i<=sqrt(n);i++)if(n%i==0)return false;
      return true;
  }
    bool isThree(int n) {
        return n!=1 and n!=2 and (int)sqrt(n)*sqrt(n)==n and isPrime(sqrt(n));
    }

};