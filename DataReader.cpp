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

    // skips header row
    if (!getline(file, line)) {
        return dataList;
    }

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        SensorData data;

        try {
            data.parseRow(line);
            dataList.push_back(data);
        }
        catch (const exception& e) {
            cerr << "Skipping bad row:\n" << line << "\nError: " << e.what() << endl;
        }
    }

    closeFile();
    return dataList;
}
