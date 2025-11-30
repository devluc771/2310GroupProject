#include "DataWriter.h"
#include <iostream>

DataWriter::DataWriter(const string& fname)
    : filename(fname) {}

bool DataWriter::openFile() {
    file.open(filename);
    return file.is_open();
}

void DataWriter::closeFile() {
    if (file.is_open())
        file.close();
}

void DataWriter::writeData(const SensorData& data) {
    if (!file.is_open())
        openFile();

    file << data.getTs() << ","
         << data.getDevice() << ","
         << data.getCo() << ","
         << data.getHumidity() << ","
         << data.getLight() << ","
         << data.getLpg() << ","
         << data.getMotion() << ","
         << data.getSmoke() << ","
         << data.getTemp() << "\n";
}

void DataWriter::writeByDevice(const string& deviceId,
                               const vector<SensorData>& dataVec) {
    if (!openFile()) return;

    for (const auto& d : dataVec) {
        if (d.getDevice() == deviceId)
            writeData(d);
    }

    closeFile();
}