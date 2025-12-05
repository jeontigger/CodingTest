class Solution {
public:
    map<long, double> cache;
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(cache.find(n) != cache.end()) return cache[n];

        if(n > 0){
            if(n %2 != 0){
                return myPow(x, n-1) * x;
            }else{
                return cache[n] = myPow(x, n/2) * myPow(x, n/2);
            }
        }else{
            return 1/myPow(x, -n);
        }
    }
};