class Solution {
public:
    int passThePillow(int n, int time) {
        int mod=time%(2*n-2);
        if(mod<n){
            return mod+1;
        }
        else{
            return n-(mod-n+1);
        }
    }
};