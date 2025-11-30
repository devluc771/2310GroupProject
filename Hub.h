#ifndef HUB_H
#define HUB_H
#include <vector>
#include <string>
#include "SensorData.h"
using namespace std;

class Hub {
private:
    vector<SensorData> sensorDataList;

public:
    double convertTempCToF(double c);
    void receiveData(const SensorData& data);
    void processData();
    vector<SensorData> filterByDevice(const string& deviceId) const;
};

#endif