#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

bool ImportData(const string& inputFilePath,
                size_t& n,
                double& S,
                double*& r,
                double*& w)
{
    //Apro il file Input
    ifstream file;
    file.open(inputFilePath);

    if(file.fail())
    {
        cerr << "Errore nell'apertura del file." << endl;
        return 3;
    }

    string line;

    //Riga 0: assegno il valore ad S
    getline(file, line);
    istringstream convertLineS(line);
    char a, b;
    convertLineS >> a >> b >> S;

    //Riga 1: assegno il valore ad n
    getline(file, line);
    istringstream convertLineN(line);
    convertLineN >> a >> b >> n;

    //Riga 2-3:
    w = new double[n];
    r = new double[n];

    for(unsigned int i=0; i<n; i++){

        while(!file.eof()){

            getline(file,line);
            //Salto la riga 'w;r'
            if(line[0] != 'w'){
                break;
            }

        }
        istringstream convertLineVec(line);
        char c;
        //Assegno i valori a w e a r:
        convertLineVec >> w[i] >> c >> r[i];
    }

    //Chiudo il file Input
    file.close();

    return true;
}


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  double& S,
                  const double* const& r,
                  const double* const& w,
                  double& rateOfReturn,
                  double& V)
 {
    // Apro il file Output
    ofstream fileO;
    fileO.open(outputFilePath);

    // Stampo i dati:
    if (fileO.fail())
    {
        cerr << "L'apertura del file è fallita."<< endl;
        return false;
    }

    fileO << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;

    fileO << "w = [ ";
    for (unsigned int i = 0; i < n; i++){
        fileO << w[i] << " ";
    }
    fileO << "]" << endl;


    fileO << "r = [ ";
    for (unsigned int i = 0; i < n; i++){
        fileO << r[i] << " ";
    }
    fileO << "]" << endl;

    //Calcolo V e rateOfReturn:
    for (unsigned int i = 0; i < n; i++){

        rateOfReturn += r[i]*w[i];
    }
    for (unsigned int i = 0; i < n; i++){

        V += (1+r[i])*(w[i]*S);
    }

    fileO << "Rate of return of the portfolio = " << fixed << setprecision(4) << rateOfReturn << endl;

    fileO << "V = " << fixed << setprecision(2) << V << endl;;

    // Chiudo il file Output
    fileO.close();

    return true;

}

