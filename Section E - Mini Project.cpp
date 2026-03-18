// Section E - Mini Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <string>
#include <fstream>


// =========================
// Calculate Grade
// =================================

char getGrade(double avg)

{
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// ======================================
// Show Students
// =======================================================================


void showAll(string names[], double avg[], char grades[], int n)
{
    cout << endl << "=========== Student List ===========" << endl;
   
    for (int i = 0; i < n; i++) 
    {
        
        cout << names[i] << " | Avg: " << avg[i] << " | Grade: " << grades[i] << endl << endl;

    }
}

// ============================================================================================
//  Class Stats
// =====================================

void showStats(double avg[], int n) 
{
    double sum = 0;
    double min = avg[0];
    double max = avg[0];

    for (int i = 0; i < n; i++)
    {
        sum += avg[i];
        if (avg[i] < min) min = avg[i];
        if (avg[i] > max) max = avg[i];

    }

    //===================================
    //stats message 
    //==========================================

    cout << endl << "=========== Class Stats ===========" << endl;
    cout << "Mean: " << sum / n << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

// ======================================
// Convert to Lowercase
// =============================================

string toLowerCase(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') 
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

// ===========================================
//  Search 
// =========================================================================================================
void searchStudent(string names[], double avg[], char grades[], int n) 
{
    string search;

    cout << "Enter name to search: ";


    getline(cin, search);

    string searchLower = toLowerCase(search);

    for (int i = 0; i < n; i++) 
    {
        if (toLowerCase(names[i]) == searchLower)
        {

            cout << "Found: " << names[i] << " | Avg: " << avg[i] << " | Grade: " << grades[i] << endl;
            return;
        }

    }


    cout << "Student not found." << endl;

}


// ===========================
// Export CSV
// ============================================================================


void exportCSV(string names[], double avg[], char grades[], int n) 
{
    ofstream file("grades.csv");

    file << "Name,Average,Grade" << endl;

    for (int i = 0; i < n; i++) 
    {
        file << names[i] << "," << avg[i] << "," << grades[i] << endl;
    }

    file.close();
    cout << "Data exported to grades.csv" << endl;
}

int main() {

    // ===================================================================
    // Starting message and input
    // ===========================================================================
    cout << endl <<  "========= Student Gradebook ==========" << endl;

    int n;
    do {
       
        cout << endl << "Enter number of students (1-30): ";
        
        cin >> n;

        cout << "----------------------------------";
    }
    
    while (n < 1 || n > 30);

    cin.ignore();

    string names[30];
    double exam1[30], exam2[30], finalExam[30];
    double avg[30];
    char grades[30];

    for (int i = 0; i < n; i++)
    {
        cout << endl << endl << "Enter the students full name: ";


        getline(cin, names[i]);


        //===============================================
        // validate scores
        //===============================================================

        do
        {
            cout << endl;
            cout << "Test 1 score (0-100): ";
            cin >> exam1[i];
        } 
        while (exam1[i] < 0 || exam1[i] > 100);

        do 
        {
            cout << "Test 2 score (0-100): ";
            cin >> exam2[i];
        }
        while (exam2[i] < 0 || exam2[i] > 100);

        do
        {
            cout << "Final score (0-100): ";
            cin >> finalExam[i];
            cout << endl << endl; 
        } 
        while (finalExam[i] < 0 || finalExam[i] > 100);

        cin.ignore();

        avg[i] = 0.3 * exam1[i] + 0.3 * exam2[i] + 0.4 * finalExam[i];
        grades[i] = getGrade(avg[i]);

    }

    // ===================================================================
    // Menu section
    // =========================================================================
    int choice;

    do
    
    {
        cout << endl;
        cout << endl << "============== MENU ===============" << endl;
        cout << "1. Show all students" << endl;
        cout << "2. Show class stats" << endl;
        cout << "3. Search student" << endl;
        cout << "4. Export to CSV" << endl;
        cout << "0. Exit" << endl;
        cout << endl << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) showAll(names, avg, grades, n);
        else if (choice == 2) showStats(avg, n);
        else if (choice == 3) searchStudent(names, avg, grades, n);
        else if (choice == 4) exportCSV(names, avg, grades, n);

    } 
    
    while (choice != 0);

   
    cout << endl << "Have a great day, goodbye!" << endl;

   
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
