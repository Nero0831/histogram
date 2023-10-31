#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <ctype.h>

using namespace std;

class Histogram
{
    private:

        double binLabel[100]; // histogram label
        double binFrequency[100]; // histogram frequency
        int N; // number of data in list

    public:

        void initializeList();
        void readHistFile(string fileName);
        void printHistData(string fileName);
        void plotHorizontalHist(string fileName);
        void plotVerticalHist(string fileName);
        void readTextFile(string fileName);

};
