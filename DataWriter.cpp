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

void writeOutputFiles(const vector<SensorData>& data)
{
    ofstream f_co("out_co.csv");
    ofstream f_humidity("out_humidity.csv");
    ofstream f_light("out_light.csv");
    ofstream f_lpg("out_lpg.csv");
    ofstream f_motion("out_motion.csv");
    ofstream f_smoke("out_smoke.csv");
    ofstream f_temp("out_temp.csv");

    // write headers
    f_co       << "ts,device,co\n";
    f_humidity << "ts,device,humidity\n";
    f_light    << "ts,device,light\n";
    f_lpg      << "ts,device,lpg\n";
    f_motion   << "ts,device,motion\n";
    f_smoke    << "ts,device,smoke\n";
    f_temp     << "ts,device,temp\n";

    // write rows
    for (const auto& d : data) {
        f_co       << d.getTs() << "," << d.getDevice() << "," << d.getCo()       << "\n";
        f_humidity << d.getTs() << "," << d.getDevice() << "," << d.getHumidity() << "\n";
        f_light    << d.getTs() << "," << d.getDevice() << "," << d.getLight()    << "\n";
        f_lpg      << d.getTs() << "," << d.getDevice() << "," << d.getLpg()      << "\n";
        f_motion   << d.getTs() << "," << d.getDevice() << "," << d.getMotion()   << "\n";
        f_smoke    << d.getTs() << "," << d.getDevice() << "," << d.getSmoke()    << "\n";
        f_temp     << d.getTs() << "," << d.getDevice() << "," << d.getTemp()     << "\n";
    }

    // files close automatically when going out of scope
}