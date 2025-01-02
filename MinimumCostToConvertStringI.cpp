class Solution {
public:
    #define ll long long
    int d[26][26];
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //cost[i] = cost of changing orig[i] -> changed[i]

        fill(&d[0][0], &d[0][0]+26*26, INT_MAX);

        int n = original.size();
        for(int idx=0;idx<n;idx++)
        {
            int i = original[idx] -'a';
            int j = changed[idx] - 'a';
            d[i][j] = min(d[i][j], cost[idx]);
        }

        for(int i=0;i<26;i++)
            d[i][i] = 0;
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    d[j][k] = min((ll)(d[j][k]), (ll)d[j][i] + d[i][k]);
                }
            }
        }

        int len = source.size();
        ll ans = 0;
        for(int i=0;i<len;i++)
        {
            int a = source[i]-'a';
            int b = target[i]-'a';
            if(d[a][b]!=INT_MAX)
                ans+=d[a][b];
            else
                return -1;
        }
        return ans;
    }
};