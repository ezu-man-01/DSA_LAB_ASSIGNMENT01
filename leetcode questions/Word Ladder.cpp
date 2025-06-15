class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string currentWord = q.front();
                q.pop();
                if (currentWord == endWord) return ladderLength;

        
                for (int j = 0; j < currentWord.size(); ++j) {
                    char originalChar = currentWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        currentWord[j] = c;
                        if (wordSet.count(currentWord)) {
                            q.push(currentWord);
                            wordSet.erase(currentWord); 
                        }
                    }
                    currentWord[j] = originalChar; 
                }
            }
            ladderLength++;
        }

        return 0;
    }
};