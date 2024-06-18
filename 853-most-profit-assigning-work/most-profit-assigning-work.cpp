class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> pairvec(difficulty.size());
        for(int i = 0 ; i< difficulty.size(); i++){
            pairvec[i]= make_pair(difficulty[i],profit[i]);
        }
        sort(pairvec.begin(), pairvec.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
});
        int total = 0;
        for(int i = 0 ; i < worker.size() ; i++){
            for(int j= 0 ; j< pairvec.size();j++){
                if(worker[i]>=pairvec[j].first){
                    total+= pairvec[j].second;
                    cout<<pairvec[j].second<<endl;
                    break;
                }
            }
        }
        return total;

    }
};