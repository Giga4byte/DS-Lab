#include <stdio.h>

// Function to convert a normal matrix into triplet form
void NormalToSparse(int normal[][50], int sparse[][3], int rows, int cols) {
    int nonZero = 0;
    int counter = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (normal[i][j] != 0) {
                nonZero++;
                sparse[counter][0] = i;
                sparse[counter][1] = j;
                sparse[counter][2] = normal[i][j];
                counter++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;
}

void printMatrixC(int mat[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    int nonZero = mat[0][2];

    printf("Matrix C:\n");
    printf("%d %d %d", rows, cols, nonZero);
    printf("\n");
    for (int i = 1; i <= nonZero; i++) {
        printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

void printTransposeMatrix(int mat[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    int nonZero = mat[0][2];

    printf("%d %d %d", rows, cols, nonZero);
    printf("\n");
    for (int i = 1; i <= nonZero; i++) {
        printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

void AddSparseMatrix(int A[][3], int B[][3], int C[][3]) {
    int p = 1, q = 1, r = 1;

    while (p <= A[0][2] && q <= B[0][2]) {
        if (A[p][0] < B[q][0]) {
            C[r][0] = A[p][0];
            C[r][1] = A[p][1];
            C[r][2] = A[p][2];
            p++;
            r++;
        } else if (A[p][0] > B[q][0]) {
            C[r][0] = B[q][0];
            C[r][1] = B[q][1];
            C[r][2] = B[q][2];
            q++;
            r++;
        } else {
            if (A[p][1] < B[q][1]) {
                C[r][0] = A[p][0];
                C[r][1] = A[p][1];
                C[r][2] = A[p][2];
                p++;
                r++;
            } else if (A[p][1] > B[q][1]) {
                C[r][0] = B[q][0];
                C[r][1] = B[q][1];
                C[r][2] = B[q][2];
                q++;
                r++;
            } else {
                C[r][0] = A[p][0];
                C[r][1] = A[p][1];
                C[r][2] = A[p][2] + B[q][2];
                p++;
                q++;
                r++;
            }
        }
    }

    while (p <= A[0][2]) {
        C[r][0] = A[p][0];
        C[r][1] = A[p][1];
        C[r][2] = A[p][2];
        p++;
        r++;
    }

    while (q <= B[0][2]) {
        C[r][0] = B[q][0];
        C[r][1] = B[q][1];
        C[r][2] = B[q][2];
        q++;
        r++;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    C[0][2] = r - 1;
}

void TransposeSparseMatrix(int mat[][3], int transposed[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    int nonZero = mat[0][2];

    // Initialize an array to store the number of non-zero elements in each column
    int columnCounts[cols];
    for (int i = 0; i < cols; i++) {
        columnCounts[i] = 0;
    }

    // Count the number of non-zero elements in each column
    for (int i = 1; i <= nonZero; i++) {
        int col = mat[i][1];
        columnCounts[col]++;
    }

    // Calculate the starting position for each column in the transposed matrix
    int startingPosition[cols];
    startingPosition[0] = 1;
    for (int i = 1; i < cols; i++) {
        startingPosition[i] = startingPosition[i - 1] + columnCounts[i - 1];
    }

    // Transpose the matrix
    transposed[0][0] = cols;
    transposed[0][1] = rows;
    transposed[0][2] = nonZero;

    for (int i = 1; i <= nonZero; i++) {
        int col = mat[i][1];
        int pos = startingPosition[col];
        transposed[pos][0] = col;
        transposed[pos][1] = mat[i][0];
        transposed[pos][2] = mat[i][2];
        startingPosition[col]++;
    }
}

int main() {
    int ch;
    int A[50][3], B[50][3], C[100][3], transposed[100][3];
    int rowsA, colsA, rowsB, colsB;

    do {
        printf("\nMenu:\n");
        printf("1. Sparse Matrix Addition\n");
        printf("2. Sparse Matrix Transpose\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of rows and columns for Matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                int normalMatrixA[50][50];

                printf("Enter the elements of Matrix A (%d x %d):\n", rowsA, colsA);
                for (int i = 0; i < rowsA; i++) {
                    for (int j = 0; j < colsA; j++) {
                        scanf("%d", &normalMatrixA[i][j]);
                    }
                }

                NormalToSparse(normalMatrixA, A, rowsA, colsA);

                printf("Enter the number of rows and columns for Matrix B: ");
                scanf("%d %d", &rowsB, &colsB);
                int normalMatrixB[50][50];

                printf("Enter the elements of Matrix B (%d x %d):\n", rowsB, colsB);
                for (int i = 0; i < rowsB; i++) {
                    for (int j = 0; j < colsB; j++) {
                        scanf("%d", &normalMatrixB[i][j]);
                    }
                }

                NormalToSparse(normalMatrixB, B, rowsB, colsB);

                printf("MATRIX A in Sparse Form:\n");
                printTransposeMatrix(A);

                printf("MATRIX B in Sparse Form:\n");
                printTransposeMatrix(B);

                AddSparseMatrix(A, B, C);
                printf("Resultant Sparse Matrix C (A + B):\n");
                printMatrixC(C);
                break;

            case 2:
                printf("Enter the number of rows and columns for the matrix: ");
                scanf("%d %d", &rowsA, &colsA);
                int normalMatrix[50][50];

                printf("Enter the elements of the matrix (%d x %d):\n", rowsA, colsA);
                for (int i = 0; i < rowsA; i++) {
                    for (int j = 0; j < colsA; j++) {
                        scanf("%d", &normalMatrix[i][j]);
                    }
                }

                NormalToSparse(normalMatrix, A, rowsA, colsA);

                printf("Original Matrix in Sparse Form:\n");
                printMatrixC(A);

                TransposeSparseMatrix(A, transposed);
                printf("Transposed Sparse Matrix:\n");
                printTransposeMatrix(transposed);
                break;

            case 3:
                printf("Quitting the program.\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 3);

    return 0;
}
