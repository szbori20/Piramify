#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Piramify(char* input, int numRows, int* output) {
    int totalSum = 0;
    int concatenatedValue=0;
    int len = strlen(input); 
    int matrix[numRows][len];
    int numCols = len;

    // Initialize the matrix with zeros
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= len; j++) {
            matrix[i][j] = 0;
        }
    }

    int nrRepeatPattern = ((numRows-1)*2);
    
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            int mod = (col % nrRepeatPattern);
            if (mod >= numRows)
            {
                mod -= numRows;
                mod = ((numRows - 1) - (mod + 1));
            }

            if (mod == row)
            {
                matrix[row][col] = input[col]-'0';
            }
            else
            {
                //do nothing
            }
        }
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
