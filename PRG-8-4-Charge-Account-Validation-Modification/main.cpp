//
//  main.cpp
//  PRG-8-4-Charge-Account-Validation-Modification
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify the program you wrote for Problem 1 (Charge Account Validation) so it performs
//  a binary search to locate valid account numbers. Use the selection sort algorithm
//  to sort the array before the binary search is performed.

#include <iostream>

using namespace std;

const int INT_ARRAY_SIZE = 18;

void sortArray(int[]);
void displayArray(const int[]);
int getAccountNumber();
//int linearSearch(const int[], int, int);
int binarySearch(const int[], int);

int main()
{
    int int_Result;
    int int_Customer_Account_Number;
    int int_Account_Number_Array[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
        1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    
    sortArray(int_Account_Number_Array);
    
    displayArray(int_Account_Number_Array);
    
    int_Customer_Account_Number = getAccountNumber();
    
    //    int_Result = linearSearch(int_Account_Number_Array, INT_ARRAY_SIZE, int_Customer_Account_Number);
    
    int_Result = binarySearch(int_Account_Number_Array, int_Customer_Account_Number);
    
    if(int_Result == int_Customer_Account_Number)
    {
        cout << "You have entered a correct number.\n";
        cout << int_Result << endl;
    }
    else
    {
        cout << "That number was not found.\n";
        cout << int_Result << endl;
    }
    
    return 0;
}

void sortArray(int intArray[])
{
    int intMinIndex;
    int intMinValue;
    
    for(int start = 0 ; start < (INT_ARRAY_SIZE - 1) ; start++)
    {
        intMinIndex = start;
        intMinValue = intArray[start];
        for(int index = start + 1 ; index < INT_ARRAY_SIZE ; index++)
        {
            if(intArray[index] < intMinValue)
            {
                intMinValue = intArray[index];
                intMinIndex = index;
            }
        }
        int temp = intArray[intMinIndex];
        intArray[intMinIndex] = intArray[start];
        intArray[start] = temp;
    }
    
    cout << "Sort completed.\n";
}

void displayArray(const int intArray[])
{
    for(int i = 0 ; i < INT_ARRAY_SIZE ; i++)
    {
        cout << intArray[i] << endl;
    }
}

int getAccountNumber()
{
    int intCustomerAN;
    
    cout << "Please enter your 7-digit account number: ";
    cin >> intCustomerAN;
    while(!intCustomerAN || intCustomerAN < 1000000 || intCustomerAN > 9999999)
    {
        cout << "Please enter a valid 7-digit number: ";
        cin.clear();
        cin.ignore();
        cin >> intCustomerAN;
    }
    
    return intCustomerAN;
}

//int linearSearch(const int intArray[], int size, int value)
//{
//    int index = 0;
//    int position = -1;
//    bool found = false;
//
//    while(index < size && !found)
//    {
//        if(intArray[index] == value)
//        {
//            found = true;
//            position = index;
//        }
//        index++;
//    }
//    return intArray[position];
//}

int binarySearch(const int intArray[], int value)
{
    int first = 0;
    int last = INT_ARRAY_SIZE - 1;
    int middle;
    int position = -1;
    
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if(intArray[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if(intArray[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
        cout << intArray[middle] << endl;
    }
    
    return intArray[position];
}

