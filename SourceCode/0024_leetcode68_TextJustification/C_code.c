#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words,
                   int wordsSize,
                   int maxWidth,
                   int* returnSize)
{
    char** result =
        (char**)malloc(wordsSize * sizeof(char*));

    int count = 0;

    int i = 0;

    while (i < wordsSize)
    {
        //------------------------------------------------
        // Find words that fit in one line
        //------------------------------------------------

        int lineLength = strlen(words[i]);

        int j = i + 1;

        while (j < wordsSize &&
               lineLength + 1 +
               strlen(words[j]) <= maxWidth)
        {
            lineLength +=
                1 + strlen(words[j]);

            j++;
        }

        //------------------------------------------------
        // Calculate total word characters
        //------------------------------------------------

        int totalWordLength = 0;

        for (int k = i; k < j; k++)
        {
            totalWordLength += strlen(words[k]);
        }

        int numWords = j - i;

        char* line =
            (char*)malloc((maxWidth + 1) *
                          sizeof(char));

        int pos = 0;

        //------------------------------------------------
        // Last line or single word
        //------------------------------------------------

        if (j == wordsSize || numWords == 1)
        {
            for (int k = i; k < j; k++)
            {
                int len = strlen(words[k]);

                memcpy(line + pos,
                       words[k],
                       len);

                pos += len;

                if (k != j - 1)
                {
                    line[pos++] = ' ';
                }
            }

            while (pos < maxWidth)
            {
                line[pos++] = ' ';
            }
        }

        //------------------------------------------------
        // Fully justified line
        //------------------------------------------------

        else
        {
            int totalSpaces =
                maxWidth - totalWordLength;

            int gaps = numWords - 1;

            int spacesPerGap =
                totalSpaces / gaps;

            int extraSpaces =
                totalSpaces % gaps;

            for (int k = i; k < j; k++)
            {
                int len = strlen(words[k]);

                memcpy(line + pos,
                       words[k],
                       len);

                pos += len;

                if (k == j - 1)
                    break;

                int currentSpaces =
                    spacesPerGap;

                if (extraSpaces > 0)
                {
                    currentSpaces++;
                    extraSpaces--;
                }

                while (currentSpaces--)
                {
                    line[pos++] = ' ';
                }
            }
        }

        line[pos] = '\0';

        result[count++] = line;

        i = j;
    }

    *returnSize = count;

    return result;
}
