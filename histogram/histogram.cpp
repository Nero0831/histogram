#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include "histogram.h"

void Histogram::initializeList() // Initialize list to sane values
{
    for (int i=0; i< 100; i++)
    {
        binLabel[i]= 0.0; // Initialize binLabel and binFrequency
        binFrequency[i]= 0; // to sane startup values
    }
    N=0; // Nobody in the list at start
    cout << "List initialized!" << endl;
}

void Histogram::readHistFile(string fileName)
{
    ifstream fileReader(fileName);
    if(!fileReader.is_open())
    {
        cerr << "Error: File does not exist." << endl;
    }

    else if (fileReader.is_open())
    {
        int i=1; // Index to start array elements
        while (i<20 && fileReader >> binLabel[i] >> binFrequency[i])
        {
            i++; // move to next
        }
        N = i; // update number of data points
        cout << "\n Sucessfully read! \n" << endl;
        fileReader.close();
    }
}

void Histogram::printHistData(string fileName)
{
    cout << fixed << setprecision(1); // Set fixed precision for decimal places

    for (int i = 0; i < 20; i++)
    {
          cout << binLabel[i] << " " << binFrequency[i] << endl;
    }
}

void Histogram::plotHorizontalHist(string fileName)
{
    if (fileName == "input.hist" || fileName == "input.txt")
    {
        // Loop 1: Determine the maximum word length in the histogram
        int maxWordLength = 0;
        for (int i = 1  ; i < 8; i++) // Start from 1
        {
            if (binFrequency[i] > 0 && i > maxWordLength)
                maxWordLength = i;
        }

        // Loop 2: Plot the histogram up to the maximum word length
        cout << fixed << setprecision(1);
        for (int i = 1; i <= maxWordLength; i++) // Start from 1 and include maxWordLength
        {
            if (binFrequency[i] >= 0 && i < 100) // Check frequency and the word length range
            {
                cout << i << ".0 / " << binFrequency[i] << " ";
                int numAsterisks = static_cast<int>(binFrequency[i]);
                for (int j = 0; j < numAsterisks; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            else
            {
                // If frequency is 0 or word length is beyond the max range, break the loop
                break;
            }
        }

        cout << "\nSuccessfully plotted horizontal histogram!\n" << endl;
    }


    else if (fileName == "inputFile.txt")
    {
        // Determine the maximum word length in the histogram
        int maxWordLength = 0;
        for (int i = 1  ; i < 15; i++) // Start from 1
        {
            if (binFrequency[i] > 0 && i > maxWordLength)
                maxWordLength = i;
        }

        // Plot the histogram up to the maximum word length
        cout << fixed << setprecision(1);
        for (int i = 1; i <= maxWordLength; i++) // Start from 1 and include maxWordLength
        {
            if (binFrequency[i] >= 0 && i < 100) // Check frequency and the word length range
            {
                cout << i << ".0 / " << binFrequency[i] << " ";
                int numAsterisks = static_cast<int>(binFrequency[i]);
                for (int j = 0; j < numAsterisks; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            else
            {
                // If frequency is 0 or word length is beyond the max range, break the loop
                break;
            }
        }

        cout << "\nSuccessfully plotted horizontal histogram!\n" << endl;
    }
}

void Histogram::plotVerticalHist(string fileName)
{
    int maxFrequency = 0;

    if (fileName == "inputFile.txt")
    {
        int N=15;

        // Loop 1: Iterate through the bin frequencies, and find the maximum frequency among the bins.
        for (int i = 0; i < N; i++)
        {
            if (binFrequency[i] > maxFrequency)
                maxFrequency = static_cast<int>(binFrequency[i]);

        }
        // Loop 2: Loop from the maxFrequency down to 1, for each row, iterate through the bins
        //         and print asterisk if the bin frequency is >= current row. Else print space.
        for (int row = maxFrequency; row > 0; row--)
        {

            for (int i = 1; i <= N; i++)
            {
                if (binFrequency[i] >= row)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << endl;
        }

        // Loop 3: To create a separator line below the histogram.
        for (int i = 0; i < N; i++)
            cout << "--";
            cout << endl;

        // Loop 4: Prints the bin labels to label each column of the histogram.
        for (int i = 1; i <= N; i++)
        {

            cout << i << " ";

        }   cout << endl;

        cout << "\n Successfully plotted vertical histogram for Text File! \n" << endl;
    }

    else if (fileName == "input.txt" || fileName == "input.hist")
        {
            int N=7;
            // Loop 1: Iterate through the bin frequencies, and find the maximum frequency among the bins.
            for (int i = 0; i < N; i++)
            {
                if (binFrequency[i] > maxFrequency)
                    maxFrequency = static_cast<int>(binFrequency[i]);

            }
            // Loop 2: Loop from the maxFrequency down to 1, for each row, iterate through the bins
            //         and print asterisk if the bin frequency is >= current row. Else print space.
            for (int row = maxFrequency; row > 0; row--)
            {

                for (int i = 1; i <= N; i++)
                {
                    if (binFrequency[i] >= row)
                        cout << "* ";
                    else
                        cout << "  ";
                }
                cout << endl;
            }

            // Loop 3: To create a separator line below the histogram.
            for (int i = 0; i < N; i++)
                cout << "--";
                cout << endl;

            // Loop 4: Prints the bin labels to label each column of the histogram.
            for (int i = 1; i <= N; i++)
            {

                cout << i << " ";

            }   cout << endl;

            cout << "\n Successfully plotted vertical histogram! \n" << endl;
        }
}



void Histogram::readTextFile(string fileName)
{
    ifstream fileReader(fileName);

    if (!fileReader.is_open())
    {
        cerr << "Error: No such file." << endl;
        return;
    }

    string word;

    // Loop 1: Word processing while-loop
    while (fileReader >> word)
    {
        // Measure length of each word
        int wordLength = 0;

        for (char c : word) // For-loop to check condition for each characters in each word.
        {
            if (isalpha(c))
                wordLength++;
        }

        // Output the word and its length
        cout << word << " || length: " << wordLength << endl;

        // Update the frequency for the calculated word length
        if (wordLength < 100) // Assuming max word length can be 100
            binFrequency[wordLength]++;
    }

    fileReader.close();
    cout << "\nSuccessfully read and updated histogram from text file!\n" << endl;
}




