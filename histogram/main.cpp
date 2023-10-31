#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include "histogram.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Correct usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // Please remove comments to use below set of functions


    /* Task 1: Read histogram and print out histogram data
    Histogram hs;
    hs.initializeList();
    hs.readHistFile(argv[1]);
    hs.printHistData(argv[1]); */

    /* Task 2: Read hist file and plot horizontal histogram
    Histogram hs;
    hs.initializeList();
    hs.readHistFile(argv[1]);
    hs.plotHorizontalHist(argv[1]); */

    /* Task 3: Read hist file and plot vertical histogram
    Histogram hs;
    hs.initializeList();
    hs.readHistFile(argv[1]);
    hs.plotVerticalHist(argv[1]); */

    /* Task 4: Read text file and plot horizontal histogram
    Histogram hs;
    hs.initializeList();
    hs.readTextFile(argv[1]);
    hs.plotHorizontalHist(argv[1]); */

    /* Task 4: Read text file and plot vertical histogram
    Histogram hs;
    hs.initializeList();
    hs.readTextFile(argv[1]);
    hs.plotVerticalHist(argv[1]); */

}
