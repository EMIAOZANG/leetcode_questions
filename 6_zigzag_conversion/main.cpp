class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> res(numRows, "");
        int N = numRows - 1;
        for (int i = 0; i < s.length(); i++) {
            res[N - abs((i / (2 * N)) * (2 * N) + N - i)] += s[i]; //The key is to find the correct conversion formula
        }
        string target = "";
        for (int i = 0; i < res.size(); i++) {
            target += res[i];
        }
        return target;
    }
};
