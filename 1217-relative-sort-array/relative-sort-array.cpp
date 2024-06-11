class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end());
        map<int,int> a,d;
        for(int i = 0 ; i < arr2.size(); i++){
            a[arr2[i]]= 1;
        }
        for(int i = 0 ; i < arr1.size(); i++){
            d[arr1[i]]++;
        }
        vector<int> b,c;
        for(int i = 0 ; i < arr2.size(); i++){
            if(d[arr2[i]]>0){
                for(int j = 0 ; j< d[arr2[i]]; j++){
                b.push_back(arr2[i]);
                }
            }
        }
        for(int i = 0 ; i < arr1.size(); i++){
            if(a[arr1[i]]==0){
                c.push_back(arr1[i]);
            }
        }
        for(int i = 0 ; i < c.size(); i++){
            b.push_back(c[i]);
        }
        return b;
    }
};