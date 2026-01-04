/** \file bugExample.cpp
 *  \brief     A program with a few logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then commit
 *                   the code with a comment on the fix you did
 *                3) There are a four functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Konstantinos Stefanides
 *  \version   0.1
 *  \date      14/11/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
bool avgOddArray(const int[], const int, int&);
void revertNumbers(int arr[], const int size);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if the program ends safely.
 */
int main() {
  int choice;
  const int SIZE = 10;

  // Initialize array price
  int price[SIZE] = {12, 4, 8, 1, 17, 2, 4, 2, 9, 1};
  // Declare array quantity and total
  int quantity[SIZE], total[SIZE];

  // Interactive menu
  do {
    choice = printMenu();

    switch (choice){
      // Enter quantity
      case 1:
        fillInArray(quantity, SIZE);
        break;
      // Calculate total
      case 2:
        multArrays(quantity, price, total, SIZE);
        break;
      // Print total
      case 3:
        displayArray(total, SIZE);
        break;
      // Print the sum of all odd numbers in total
      case 4:
        cout << "\nThe sum of all odd numbers in total: " << sumOddArray(total, SIZE) << endl;
        break;
      // Checks wether all numbers in total are positive or not
      case 5:
        if (isAllPositive(total, SIZE))
          cout << "\nAll numbers are positive!";
        else
          cout << "\nNegative number found!";
        break;
      // Exit
      case 0:
        // No code needed
        break;
      default:
        assert(true);
    }
  } while (choice != 0);

  cout << "\nHave a nice day:)" << endl;
  return 0;
}

/**
 * <code>printMenu</code> prints a menu and returns the choice of the user.
 * <BR>
 * @return Returns the user's choice (int)
 */
int printMenu(){
  int choice;

  do {
    cout << "\n == MENU ==";
    cout << "\n1) Enter quantity";
    cout << "\n2) Calculate total";
    cout << "\n3) Print total";
    cout << "\n4) Print the sum of all Odds";
    cout << "\n5) Positive number checker";
    cout << "\n0) Exit";

    cout << "\nEnter the choice: ";
    cin >> choice;

    if (choice < 0 || choice > 5){
      cout << "\nWrong choice, try again.";
    }
  } while (choice < 0 || choice > 5);
  return choice;
}

/**
 * <code>fillInArray</code> is a function that fills in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size){
  assert(size <= 10);

  for (int i = 0; i < size; i++){
    cout << "\nEnter an element for the array at " << i+1 << ": ";
    cin >> arr[i];
  }
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to a corresponding value of the price array in a new total array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrQuantity The array containing the source elements.
 * @param arrPrice The array containing the destination elements.
 * @param arrTotal The array that gains the multiplied elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size){
  assert (size <= 10);

  for (int i = 0; i < size; i++){
    arrTotal[i] = arrQuantity[i] * arrPrice[i];
  }
}

/**
 * <code>displayArray</code> prints the value of each element in the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 */
void displayArray(const int arr[], int size){
  assert(size <= 10);
  int sum = 0;

  for (int i = 0; i < size; i++){
    cout << "\nValue at " << i+1 << ": " << arr[i];
    sum += arr[i];
  }

  cout << "\nThe total is: " << sum;
}

/**
 * <code>sumOddArray</code> Prints the total of all odd numbers in the total array
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 * @return returns the sum of all the odd numbers in total
 */
int sumOddArray(const int arr[], const int size){
  assert(size <= 10);
  int sum = 0;

  for (int i = 0; i < size; i++){
    if (arr[i] % 2 != 0)
      sum += arr[i];
  }
  return sum;
}

/**
 * <code>isAllPositive</code> Returns true if all elements in the total array are positive numbers
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 * @return returns true if all elements in the array are positive, otherwise false.
 */
bool isAllPositive(const int arr[], const int size){
  assert(size <= 10);

  for (int i = 0; i < size; i++){
    if (arr[i] < 0)
      return false;
  }
  return true;
}

// Finds the average of all the odd numbers in the array and stores this in the last argument
// returns false if there are no odd numbers in the array, true otherwise.
bool avgOddArray(const int arr[], const int size, int& avgOdd){
  //@TODO: You will need to complete this. Including making the appropriate comment header
  return false;
}

// You revert the numbers (in place) of the array. I.e. if your array have the values [1, 3, 4, 7, 11] then
// after calling this function the values in the array should be [11, 7, 4, 3, 1]
void revertNumbers(int arr[], const int size) {
  //@TODO: You will need to complete this. Including making the appropriate comment header
}