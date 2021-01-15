/// <summary>
/// Greedy approach (using stack)
/// https://leetcode.com/problems/valid-parenthesis-string/
/// </summary>
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        for (auto& c : s) {
            st.push(c);

            if (c == ')') {
                int cS = 0;
                char last = '\0';
                while (!st.empty()) {
                    last = st.top();
                    st.pop();
                    if (last == '*') ++cS;
                    else if (last == '(') break;
                }
                if (last != '(') {
                    if (cS == 0) return false;
                    else --cS;
                }

                while (cS-- > 0) st.push('*');
            }
        }

        vector<char> ve(st.size());
        while (not st.empty()) {
            ve.insert(ve.begin(), st.top());
            st.pop();
        }

        for (auto it = ve.begin(); it != ve.end(); ++it) {
            if (*it == '(') {
                auto fit = find(it, ve.end(), '*');
                auto cpyIt = it;
                if (fit != ve.end()) {
                    ve.erase(fit);
                    ve.erase(cpyIt);
                    --it;
                }
                else return false;
            }
        }
        return true;
    }
};