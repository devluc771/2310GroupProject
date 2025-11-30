#include "DataReader.h"
#include <iostream>

DataReader::DataReader(const string& filename)
{
    this->filename = filename;
}

bool DataReader::openFile()
{
    file.open(filename);
    return file.is_open();
}

void DataReader::closeFile()
{
    if (file.is_open())
        file.close();
}

vector<SensorData> DataReader::readData()
{
    vector<SensorData> dataList;

    if (!openFile()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return dataList;
    }

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;

        SensorData data;
        data.parseRow(line);     // convert CSV line into SensorData object
        dataList.push_back(data);
    }

    closeFile();
    return dataList;
}
