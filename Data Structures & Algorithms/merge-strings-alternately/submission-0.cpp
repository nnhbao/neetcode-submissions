class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string merge;
        int i;
        for (i=0 ; i < min(word1.size(), word2.size()); i++){
            merge = merge + word1[i] + word2[i];
        }

        while(i < word1.size()) {
            merge = merge + word1[i];
            i++;
        }
        while(i < word2.size()) {
            merge = merge + word2[i];
            i++;
        }
        return merge;
    }
};