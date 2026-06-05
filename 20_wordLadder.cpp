//Leetcode = 127 | T.C = O(N∗M∗26) & S.C = T.C = O(N∗M∗26)
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> vis;
        vis.insert(beginWord);

        int level = 1;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int i = 0; i < word.size(); i++) {

                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        temp[i] = ch;

                        if (st.count(temp) && !vis.count(temp)) {
                            vis.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};