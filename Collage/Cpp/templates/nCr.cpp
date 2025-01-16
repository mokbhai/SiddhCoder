class nCr {
    private:
    int mod = le9+7;
    public:
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

    int inv(int x){
        return binaryExp(x, mod-2);
    }

    int nCr(int n, int r){
        long ans = 1;

        for(int i=1;i<=r;i++){
            ans = (ans * (n - i + 1)) % mod;
            ans = (ans * inv(i)) % mod;
        }

        return ans;
    }
}