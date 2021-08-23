// Author: Dhruv Shetty

#include "float.h"


// Function that takes a pointer integer's decimal value, converts it into bits, then places those bits into an array.
void float_to_binary(int arr[], int * f, int size){
	int i;

    for (i = size-1; i >= 0; i--) {
        arr[i] = *f % 2;
        *f = *f / 2;
    }
}

// Function that takes a negative pointer integer's decimal value, converts it into bits, then places those bits into an array.
void neg_float_to_pos_binary(int arr[], int * num, int size){
    int i;

    // Make the negative number positive
    *num=*num*(-1);

    // Transform positive decimal into binary form and places it into an array
    float_to_binary(arr, num, size);

    // Invert bits
    for (i=31; i>=0; i--){
        if (arr[i]==0){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }

    // Add 1 to least signifigant bit and adjusts the binary number
    int ind = 31;
    if (arr[ind]==0){
        arr[ind]=1;
    }
    else{
        while(arr[ind-1]==1){
            arr[ind]=0;
            ind--;
        }
        arr[ind]=0;
        arr[ind-1]=1;
    }
}

// Function to convert a binary number in an array into a decimal.
int binarytodec(int arr[], int size, int base) {
    int i;
    int result = 0;

    // Loops through the array storing the binary, each time multiplying the base by 2.
    // If there is a 1, then it adds that power of 2 to the sum (result).
    for (i = size-1; i >= 0; i--) {
        if (arr[i] == 1) {
            result += base;
        }
        base *= 2;
    }

    return result;
}

// Function to convert a fractional binary number in an array into a decimal.
float binaryfractodec(int arr[], int size, float base) {
    int i;
    float result = 0;

    // Loops through the array storing the binary, each time dividing the base by 2.
    // If there is a 1, then it adds that power of (1/2) to the sum (result).
    for (i = 0; i < size; i++) {
        if (arr[i] == 1) {
            result += base;
        }
        base *= .5;
    }

    return result;
}