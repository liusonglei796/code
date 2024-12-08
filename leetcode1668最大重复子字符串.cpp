class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string s = word;
        while (sequence.find(s)!= string::npos) {
            count++;
            s += word;
        }
        return count;
    }
};