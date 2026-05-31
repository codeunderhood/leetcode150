#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* convert(char* s, int numRows)
{
    int n = strlen(s);

    if(numRows == 1 || numRows >= n)
        return strdup(s);

    char** rows = (char**)malloc(numRows * sizeof(char*));

    for(int i = 0; i < numRows; i++)
    {
        rows[i] = (char*)calloc(n + 1, sizeof(char));
    }

    int* len = (int*)calloc(numRows, sizeof(int));

    int currRow = 0;
    bool goingDown = true;

    for(int i = 0; i < n; i++)
    {
        rows[currRow][len[currRow]++] = s[i];

        if(currRow == 0)
            goingDown = true;
        else if(currRow == numRows - 1)
            goingDown = false;

        if(goingDown)
            currRow++;
        else
            currRow--;
    }

    char* result = (char*)malloc(n + 1);

    int k = 0;

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < len[i]; j++)
        {
            result[k++] = rows[i][j];
        }
    }

    result[k] = '\0';

    for(int i = 0; i < numRows; i++)
        free(rows[i]);

    free(rows);
    free(len);

    return result;
}
