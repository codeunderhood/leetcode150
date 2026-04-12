# ✅ For m × n matrix

You must do:

for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
        result[j][i] = matrix[i][j];
    }
}

👉 Yes — full traversal (i=0, j=0 to end), writing into a new matrix, not swapping


# ✅ For n × n:
swap(matrix[i][j], matrix[j][i]);

✔ in-place
✔ only half needed
