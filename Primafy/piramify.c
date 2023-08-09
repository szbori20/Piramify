#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Piramify(char* input, int numRows, int* output) {
    int i = 0;    
    int j = 0;
    int colCntr = 0;
    int rowCntr=0;
    int totalSum = 0;
    int concatenatedValue=0;
    int len = strlen(input); 
    int matrix[numRows][len];

    // Initialize the matrix with zeros
    for (i = 0; i < numRows; i++) {
        for (j = 0; j <= len; j++) {
            matrix[i][j] = 0;
        }
    }

    // Place the input values in the matrix
    while(colCntr < len) {

    if (colCntr == rowCntr) {
        matrix[rowCntr][colCntr] = input[colCntr]-'0';
        if(rowCntr < numRows-1) {
            rowCntr++;
        }
    }
    if ((colCntr >= numRows) && (colCntr < ((numRows*2)-1))){
        rowCntr--;
        matrix[rowCntr][colCntr] = input[colCntr]-'0';
    }
    if((rowCntr>=0) && (colCntr>=((numRows*2)-1))) {
        rowCntr++;
        matrix[rowCntr][colCntr] = input[colCntr]-'0'; 

    }
    
    colCntr++;
    }

    // Concatenate the values which are greater than 0 in each row and sum them
    for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < len; j++) {
        if(matrix[i][j]!=0){
            concatenatedValue = concatenatedValue * 10 + matrix[i][j];
        }
    }
    totalSum += concatenatedValue;
    concatenatedValue = 0;
    }

    //Print the constructed matrix but with spaces
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < len; j++) {
            if (matrix[i][j] == 0) {
                printf(" "); // Print space
            } else {
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }

    // Print the total sum
    printf("%d", totalSum);

    return totalSum;
}

void main() {
    char input[100] ={0};
    int numRows = 0;

    int output =0;

    // Read input string and number of rows
    printf("Enter the string containing digits (0-9): ");
    scanf("%s", input);

    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    output = Piramify(&input, numRows, &output);
}