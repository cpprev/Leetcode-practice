/// <summary>
/// Store occurences in hashmap approach
/// https://leetcode.com/problems/count-good-meals
/// </summary>
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<long, long> nbOccs;
        for (int i = 0; i < deliciousness.size(); ++i) {
            long elem = deliciousness[i];
            nbOccs[elem]++;
        }

        long res = 0;
        for (const auto& e : nbOccs) {
            long curElem = e.first;
            long nbOcc = e.second;
            for (int p = 0; p <= 21; ++p) {
                long matching = (long)pow(2, p) - curElem;
                auto it = nbOccs.find(matching);
                if (it != nbOccs.end()) {
                    if (curElem != matching) {
                        res += nbOcc * it->second;
                    }
                    else {
                        res += (nbOcc - 1) * nbOcc;
                    }
                }
            }
        }
        return (res / 2) % ((long)1e9 + 7);
    }
};