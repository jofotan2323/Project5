//
//  main.cpp
//  JOfotan_Pr5
//
//  Created by Jade Ofotan on 7/3/24.
//
/*
 * Class: CMSC140 CRN
 * Instructor: Ara Kechiantz
 * Project #5
 * Description: Write a program that simulates a magic square using 3 one dimensional parallel arrays of integer type. Using a two-dimensional array is not allowed in this Project.
 * Due Date: 07/05/24
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Jade Ofotan
*/

#include<iostream>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main() {
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    char tryAgain;

    do {
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS)) {
            cout << "This is a Lo Shu Magic Square." << endl;
        } else {
            cout << "This is not a Lo Shu Magic Square." << endl;
        }

        cout << "Do you want to try again? (y/n): ";
        cin >> tryAgain;
    } while (tryAgain == 'y' || tryAgain == 'Y');

    return 0;
}

// Function definitions

// Function that fills array
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 0 and column " << i << ": ";
        cin >> arrayRow1[i];
    }
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 1 and column " << i << ": ";
        cin >> arrayRow2[i];
    }
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 2 and column " << i << ": ";
        cin >> arrayRow3[i];
    }
}

// Function that displays array content
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arrayRow1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arrayRow2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arrayRow3[i] << " ";
    }
    cout << endl;
}

// Function that returns true or false
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) && checkUnique(arrayRow1, arrayRow2, arrayRow3, size) && checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) && checkColSum(arrayRow1, arrayRow2, arrayRow3, size) && checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
}

// Function that checks range
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        if (arrayRow1[i] < min || arrayRow1[i] > max ||
            arrayRow2[i] < min || arrayRow2[i] > max ||
            arrayRow3[i] < min || arrayRow3[i] > max) {
            return false;
        }
    }
    return true;
}

// Function that checks if unique
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    bool unique[MAX + 1] = {false};
    for (int i = 0; i < size; i++) {
        if (unique[arrayRow1[i]] || unique[arrayRow2[i]] || unique[arrayRow3[i]]) {
            return false;
        }
        unique[arrayRow1[i]] = true;
        unique[arrayRow2[i]] = true;
        unique[arrayRow3[i]] = true;
    }
    return true;
}

// Function that checks row sum
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += arrayRow1[i];
        sum2 += arrayRow2[i];
        sum3 += arrayRow3[i];
    }
    return (sum1 == sum2 && sum2 == sum3);
}

// Function that checks column sum
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; i++) {
        int colSum = arrayRow1[i] + arrayRow2[i] + arrayRow3[i];
        if (colSum != 15) {
            return false;
        }
    }
    return true;
}

// Function that checks diagonal sum
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int diag1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int diag2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
    return (diag1 == 15 && diag2 == 15);
}
