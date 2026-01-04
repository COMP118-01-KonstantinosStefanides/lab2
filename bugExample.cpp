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
  int quantity[SIZE] = {0}, total[SIZE] = {0};
  //Initialize average of all odds variable
  int avgOdds = 0;

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
        // Checks for odd numbers and print the average of them if any.
        case 6:
        if (avgOddArray(total, SIZE, avgOdds))
          cout << "\nOdd numbers found. The average of all odd numbers is: " << avgOdds << endl;
        else
          cout << "\nNo odd numbers were found.";
        break;
        //reverses the total array
        case 7:
        revertNumbers(total, SIZE);
        break;
      // Exit
      case 0:
        // No code needed
        break;
      default:
        assert(true);
    }
  } while (choice != 0);

  cout << "\nHave a nice day." << endl;
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
    cout << "\n6) Average of all odds checker";
    cout << "\n7) Reverse Numbers";
    cout << "\n0) Exit";

    cout << "\nEnter the choice: ";
    cin >> choice;

    if (choice < 0 || choice > 7){
      cout << "\nWrong choice, try again.";
    }
  } while (choice < 0 || choice > 7);
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
 * <code>sumOddArray</code> Prints the total of all odd numbers in the array
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
 * <code>isAllPositive</code> Returns true if all elements in the array are positive numbers
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

/**
 * <code>avgOddArray</code> Sums up all the odd numbers in the array and finds the average.
 * Additionally it returns false if it doesnt find any odds or true if it does find odds.
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 * @param avgOdd the variable that stores the average of all odd numbers in total
 * @return returns true if odd numbers are in the array, otherwise false.
 */
bool avgOddArray(const int arr[], const int size, int& avgOdd){
  assert(size <= 10);

  int sum = 0;
  int temp = 0;
  
  for (int i = 0; i < size; i++){
    if (arr[i] % 2 != 0){
      sum += arr[i];
      temp++;
    }
  }
  if (temp == 0)
    return false;
  else {
    assert(temp != 0);
    avgOdd = sum / temp;
    return true;    
  }
}

/**
 * <code>revertNumbers</code> Reverses the given array and prints it
 * <BR>
 * @param arr The array to be reversed.
 * @param size The size of the array.
 */
void revertNumbers(int arr[], const int size) {
  assert(size <= 10);
  int temp = 0;

  for (int i = 0; i < size / 2; i++){
    temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }
  cout << "\nThe reversed array: ";
  for (int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
}