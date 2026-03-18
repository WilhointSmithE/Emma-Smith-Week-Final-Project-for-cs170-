// Section D- Programming Tasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

using namespace std;

#include <string>


int main() {

    // ===============
    // D1. Range Stats
    // =======================================================

  
    cout << "|========== D1 Range Stats ==========|" << endl;

    //======
    // int
    //==================

    int num;
    int count = 0;
    int sum = 0;
    int minVal, maxVal;


    //====================
    //messages 
    //===================================================

    cout << endl << "Enter numbers (enter 0 to stop): " << endl;
   
    cin >> num;

    if (num == 0)
    {
        
        cout << endl << endl; 
        cout << "----------- Range Stats -----------" << endl;
        cout << "Sorry, no numbers have been entered." << endl << "Please continue through the rest " << endl << "of the programming tasks. " << endl;
        

    }


    else
    {
        minVal = num;
        maxVal = num;

        while (num != 0)
        {
            count++;
            sum += num;

            if (num < minVal)
            {
                minVal = num;
            }
            if (num > maxVal)
            {
                maxVal = num;
            }

            cin >> num;
        }

        double average = (double)sum / count;


        //======================================
        // output message
        //=========================================

       
        cout << endl << endl;
        cout << "----------- Range Stats -----------" << endl;
        cout << "Count: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Min: " << minVal << endl;
        cout << "Max: " << maxVal << endl;
        cout << "Average: " << average << endl;
    }

    cout << endl;

    // ===========================================
    // D2. Array Analyzer
    // ==================================================
   
    cout << "|========  D2 Array Analyzer ========|" << endl;

  
    int n;
    cout << endl << "Enter size of array (1-100): " << endl; 
    cin >> n;

    int arr[100];
    int total = 0;

    cout << endl << "Enter " << n << " numbers: " << endl; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    int avg = total / n;

    cout << endl; 

    
    cout << "---------- Array Analyzer ----------" << endl;
    cout << "Average: " << avg << endl;

    cout << "Indices equal to average: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == avg)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    int greaterCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            greaterCount++;
        }
    }

    cout << "Elements greater than average: " << greaterCount << endl;

    cout << endl;

    // =========================
    // D3. String Utilities
    // =======================================================

    cout << "|=======  D3 String Utilities =======|" << endl;


    //=============================
    //Clear Leftovers
    //===============================

    cin.ignore();
    string text;

    //============
    // first message 
    //===========================================

    cout << endl << "Please enter a full sentence: " << endl;

    getline(cin, text);

    int vowels = 0;
    int words = 0;
    string longest = "";
    string current = "";

    for (int i = 0; i < text.length(); i++)
    {
        char c = tolower(text[i]);


        //=========================================
        // count 
        //======================================================================


        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels++;
        }

        //=================================================================
        // build 
        //===================================================


        if (text[i] != ' ')
        {
            current += text[i];
        }
        else
        {
            if (current.length() > 0)
            {
                words++;
                if (current.length() > longest.length())
                {
                    longest = current;
                }
                current = "";
            }
        }
    }

    //====================================================================
    // check 
    //==================================================

    if (current.length() > 0)
    {
        words++;
        if (current.length() > longest.length())
        {
            longest = current;
        }
    }

    //=============================================
    // last message 
    //=================================================
  
    cout << endl << endl; 
    cout << "--------- String Utilities ---------" << endl;
    cout << "Number of vowels used: " << vowels << endl;
    cout << "Number of words used: " << words << endl;
    cout << "Longest word typed: " << longest << endl;



    return 0;


}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
