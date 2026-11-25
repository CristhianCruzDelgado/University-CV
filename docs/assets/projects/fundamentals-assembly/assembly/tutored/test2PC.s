Make the following change to your code:
Write a function called sort_row that receives two integer arguments: the memory
address of the structure that holds the matrix to process, and a row index (which is
assumed to have been checked by the caller to lie between zero and the total number of
rows minus one). The function returns no value, but sorts the given
row using the bubble sort method. The function must
use the swap function required in the assignment statement.
You must also add a new option to the program (option 2) called “(2)
Sort a row\n” that asks for the row of the matrix to sort, checks that the index is
valid and, if it is, calls the sort_row function (if the
index is invalid, it must proceed as the other options do, that is, with
an error).

The C++ code of the function to write is the following:
void sort_row(structMat* mat, int indF) {
    int nFil = mat->nFil;
    int nCol = mat->nCol;
    float* elem = mat->elementos;
    float* e1;
    float* e2;
    for(int i = 0; i < nCol-1 ; i++) {
        for(int j = 0; j < nCol-1-i; j++) {
            if ( elem[indF*nCol + j] > elem[indF*nCol + j+1] ) {
                e1 = &elem[indF*nCol+j];
                e2 = &elem[indF*nCol+j+1];
                swap(e1,e2);
            }
        }
    }
}

NOTE: to check the results, you can change the values of the matrices and
check whether the row is sorted correctly.
