#include "Hub.h"

double Hub::convertTempCToF(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

void Hub::receiveData(const SensorData& data) {
    sensorDataList.push_back(data);
}

void Hub::processData() {
    for (auto& d : sensorDataList) {
        double newTemp = convertTempCToF(d.getTemp());
        d.setTemp(newTemp);
    }
}

vector<SensorData> Hub::filterByDevice(const string& deviceId) const {
    vector<SensorData> vec;
    for (const auto& d : sensorDataList) {
        if (d.getDevice() == deviceId)
            vec.push_back(d);
    }
    return vec;
}
