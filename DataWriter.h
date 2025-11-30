#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <string>
#include <vector>
#include <fstream>
#include "SensorData.h"

using namespace std;

class DataWriter {
private:
    string filename;
    ofstream file;

public:
    DataWriter(const string& fname);
    bool openFile();
    void closeFile();
    void writeData(const SensorData& data);
    void writeByDevice(const string& deviceId, const vector<SensorData>& dataVec);
};

#endif