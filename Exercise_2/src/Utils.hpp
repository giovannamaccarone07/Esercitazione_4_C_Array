#pragma once
#include <iostream>

using namespace std;

bool ImportData(const string& inputFilePath,
                size_t& n,
                double& S,
                double*& r,
                double*& w);


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  double& S,
                  const double* const& r,
                  const double* const& w,
                  double& rateOfReturn,
                  double& V);

