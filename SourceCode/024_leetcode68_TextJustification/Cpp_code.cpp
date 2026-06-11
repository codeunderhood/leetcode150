class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> answer;

        int n = words.size();

        int i = 0;

        while (i < n) {

            //--------------------------------------------------
            // STEP 1:
            // Find all words that can fit in current line
            //--------------------------------------------------

            int lineLength = words[i].size();

            int j = i + 1;

            while (j < n &&
                   lineLength + 1 + words[j].size() <= maxWidth) {

                lineLength += 1 + words[j].size();
                j++;
            }

            //--------------------------------------------------
            // Words from i to j-1 belong to current line
            //--------------------------------------------------

            int totalWordsLength = 0;

            for (int k = i; k < j; k++) {
                totalWordsLength += words[k].size();
            }

            int numberOfWords = j - i;

            string line = "";

            //--------------------------------------------------
            // CASE 1:
            // Last line OR only one word
            //--------------------------------------------------

            if (j == n || numberOfWords == 1) {

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k != j - 1)
                        line += ' ';
                }

                while (line.size() < maxWidth)
                    line += ' ';
            }

            //--------------------------------------------------
            // CASE 2:
            // Fully justify
            //--------------------------------------------------

            else {

                int totalSpaces =
                    maxWidth - totalWordsLength;

                int gaps = numberOfWords - 1;

                int spacesPerGap =
                    totalSpaces / gaps;

                int extraSpaces =
                    totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k == j - 1)
                        break;

                    int currentGapSpace =
                        spacesPerGap;

                    if (extraSpaces > 0) {
                        currentGapSpace++;
                        extraSpaces--;
                    }

                    line += string(currentGapSpace, ' ');
                }
            }

            answer.push_back(line);

            i = j;
        }

        return answer;
    }
};
