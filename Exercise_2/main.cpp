#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"


using namespace std;


int main()
{
    size_t n = 0;
    double S = 0.0;
    double* r = nullptr;
    double* w = nullptr;
    double V = 0.0;
    double rateOfReturn = 0.0;

    string inputFileName = "data.csv";
    if (!ImportData(inputFileName, n, S, r, w))
    {
        cerr << "Errore nell'importazione dei dati."<< endl;
        return -1;
    }
    else
        cout << "L'importazione è andata a buon fine." << endl;


    string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, n, S, r, w, rateOfReturn, V))
    {
        cerr << "Errore nell'esportazione dei dati."<< endl;
        return -2;
    }
    else
        cout << "L'esportazione è andata a buon fine."<< endl;

    delete[] w;
    delete[] r;

    return 0;
}
