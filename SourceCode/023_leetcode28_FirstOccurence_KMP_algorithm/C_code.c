#include <stdio.h>
#include <string.h>

/*
    STEP 1: BUILD LPS ARRAY
    lps[i] = longest proper prefix which is also suffix
*/
void buildLPS(char *pat, int m, int lps[]) {

    int len = 0;   // length of previous longest prefix-suffix
    lps[0] = 0;    // first value is always 0 (no proper prefix possible)

    int i = 1;     // start from second character

    // We build LPS for each index of pattern
    while (i < m) {

        // CASE 1: characters match → extend prefix-suffix
        if (pat[i] == pat[len]) {
            len++;              // increase matching length
            lps[i] = len;      // store it in LPS array
            i++;               // move forward
        }

        // CASE 2: mismatch occurs
        else {

            // If we previously had some match, we try to fall back
            if (len != 0) {
                len = lps[len - 1];  // fallback using previous LPS value
                // IMPORTANT: we do NOT move i here
            }

            // If no previous match exists
            else {
                lps[i] = 0;  // no prefix-suffix match
                i++;          // move forward
            }
        }
    }
}

/*
    STEP 2: KMP SEARCH FUNCTION
*/
int strStr(char *txt, char *pat) {

    int n = strlen(txt);
    int m = strlen(pat);

    int lps[m];                 // LPS array for pattern
    buildLPS(pat, m, lps);     // preprocess pattern

    int i = 0;  // pointer for TEXT (haystack)
    int j = 0;  // pointer for PATTERN (needle)

    // MAIN LOOP: scan entire text
    while (i < n) {

        // CASE 1: characters match → move both pointers
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        // CASE 2: full pattern matched
        if (j == m) {
            return i - j;  // starting index of match
        }

        // CASE 3: mismatch occurs
        else if (i < n && txt[i] != pat[j]) {

            // If j is not at start, use LPS to avoid rechecking
            if (j != 0) {
                j = lps[j - 1];  // jump back intelligently
            }

            // If j is already at 0, move text pointer forward
            else {
                i++;
            }
        }
    }

    // If no match found
    return -1;
}

int main() {

    char txt[] = "ababcabcabababd";
    char pat[] = "ababd";

    printf("Index: %d\n", strStr(txt, pat));

    return 0;
}
