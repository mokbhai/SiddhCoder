int binaryExp(long long x, int a){
    int ans = 1;
    while(a){
        if (a & 1) {
            ans = (x * ans) % mod;
        }

        x = (x * x) % mod;
        a >>= 1;
    }
    return ans;
}