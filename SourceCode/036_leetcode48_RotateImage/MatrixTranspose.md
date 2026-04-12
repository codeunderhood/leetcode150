# ✅ For m × n matrix

You must do:

for (i = 0; i < m; i++) {
    // need to store all elements in new matrix, as the in-place swap would not work with irregular size matrix,
    // where m/n does not exist for any position --> for example (0,2) does not mean (2,0) should exist in case of mxn matrix.
    for (j = 0; j < n; j++) {

        result[j][i] = matrix[i][j];
    
    }

}

👉 Yes — full traversal (i=0, j=0 to end), writing into a new matrix, not swapping


# ✅ For n × n:
    for (int i = 0; i < n; i++) {
    // check only upper half triangle, as it will swap automatically lower half triangle, diagonal not needed
        for (int j = i + 1; j < n; j++) { 

            swap(matrix[i][j], matrix[j][i]);
        }
    }

✔ in-place
✔ only half needed
