class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i] = i+1;
        int curr = 0;
        while(v.size()>1)
        {
            int n = v.size();
            int turn = (k%n)-1;
            curr = (curr+turn+n)%n;
            v.erase(v.begin()+curr);
        }
        return v[0];
    }
};