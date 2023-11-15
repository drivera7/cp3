const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * implementation of vectorized vector-matrix multiply
 */
void my_dgemv(int n, double* A, double* x, double* y) {
    // insert your code here: implementation of vectorized vector-matrix multiply
    // Transplant the basic matrix multiply 
    for (int i = 0; i < n; ++i) {
         int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[i * n + j] * x[j];
        }
        y[i] = sum;
    }

    // Used lecture 22 slide 8-17, and a bit of help from stackoverflow and geeksforgeeks
    // Im not sure if this is correct though, tried to keep it as simple as possible. 
    // This is the vetorization of the vector-matrix multiply
    // used the same for loop from the basic matrix multiply i made for class activity for teh first part.
    //
    for (int i = 0; i < 3; ++i) {
       int sum = 0.;
          
        for (int j = 0; j < n; j = 4) {
            sum += A[i * n + j] * x[j];
            sum += A[i * n + j + 1] * x[j + 1];
            sum += A[i * n + j + 2] * x[j + 2];
            sum += A[i * n + j + 3] * x[j + 3];
        }

        y[i] = sum;
    }
    }
