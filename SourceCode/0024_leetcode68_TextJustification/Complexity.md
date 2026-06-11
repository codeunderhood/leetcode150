# ⚡ Time Complexity ✅ O(n × maxWidth)

Why?

Every word is processed once while forming lines.
While building each line, we may insert up to maxWidth characters (words + spaces).
Total work across all lines is proportional to the total output size.

# ⚡ Space Complexity ✅ O(n × maxWidth)

Why?

We must store all justified output lines.
The output itself contains number_of_lines × maxWidth characters.
Apart from the output, only a few variables are used (O(1) extra space).
