class Solution {
public:
    bool permutation_of(string s1, string s2){
        unordered_map<char, int> u;
        for(char c : s1) 
            u[c]++;
        for(char c : s2)
            u[c]--;
        for(auto a : u)
            if(u[a.first]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        for(int i=0; i <= s2.size() - s1.size(); i++)
            if(permutation_of(s1, s2.substr(i, s1.size())))
                return true;
        return false;
        
    }
};