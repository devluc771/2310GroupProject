#ifndef DATAREADER_H
#define DATAREADER_H
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include "SensorData.h"

class DataReader
{
    public:
        DataReader(const string& filename);
        bool openFile();
        void closeFile(); 
        vector<SensorData> readData();

    private:
        string filename;
        ifstream file;
};
#endif
