class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int n = secret.size();
        map<char,int> mp1,mp2;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else
            {
                char ch1 = secret[i];
                char ch2 = guess[i];
                mp1[ch1]++;
                mp2[ch2]++;
            }
        }
        for(char ch='0';ch<='9';ch++)
        {
            if(mp2[ch]>0 && mp1[ch]>0)
            {
                cows+=min(mp2[ch], mp1[ch]);
            }
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};