class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int res=0,points=0,i=0,j=token.size()-1;
        while(i<=j)
        {
            if(power>=token[i])
            {
                power-=token[i++];
                res=max(res,++points);
            }
            else if(points>0)
            {
                points--;
                power+=token[j--];
            }
            else
                break;
        }
        return res;
    }
};