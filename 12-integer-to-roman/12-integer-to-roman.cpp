class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> mp;
        mp = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        string s = "";
        int n = mp.size()-1;
        while (num != 0){
            if (num >= mp[n].first){
                num = num -  mp[n].first;
                s = s + mp[n].second;
            }
            else n--;
        }
        
        return s;
        
    }
};