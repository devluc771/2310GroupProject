#include "SensorData.h"
#include <sstream>

SensorData::SensorData() : ts(0), co(0), humidity(0), light(false), lpg(0), motion(false), smoke(0), temp(0) //default constructor where everything is blank
{
}

void SensorData::parseRow(string row)
{
    stringstream ss(row);
    string value;

    auto strip = [](string &s) {
        if (!s.empty() && s.front() == '"')  s.erase(0, 1);
        if (!s.empty() && s.back() == '"')   s.pop_back();
    };

    // timestamp
    getline(ss, value, ',');
    strip(value);
    ts = stod(value);

    // device
    getline(ss, value, ',');
    strip(value);
    device = value;

    // co
    getline(ss, value, ',');
    strip(value);
    co = stod(value);

    // humidity
    getline(ss, value, ',');
    strip(value);
    humidity = stod(value);

    // light
    getline(ss, value, ',');
    strip(value);
    light = (value == "true" || value == "TRUE" || value == "1");

    // lpg
    getline(ss, value, ',');
    strip(value);
    lpg = stod(value);

    // motion
    getline(ss, value, ',');
    strip(value);
    motion = (value == "true" || value == "TRUE" || value == "1");

    // smoke
    getline(ss, value, ',');
    strip(value);
    smoke = stod(value);

    // temp
    getline(ss, value, ',');
    strip(value);
    temp = stod(value);
}

double SensorData::getTs() const
{
    return ts;
}

string SensorData::getDevice() const
{
    return device;
}

double SensorData::getHumidity() const
{
    return humidity;
}

bool SensorData::getLight() const
{
    return light;
}

double SensorData::getLpg() const
{
    return lpg;
}

bool SensorData::getMotion() const
{
    return motion;
}

double SensorData::getSmoke() const
{
    return smoke;
}

double SensorData::getTemp() const
{
    return temp;
}
void SensorData::setTemp(double t)
{
    temp = t;
}
double SensorData::getCo() const
{
    return co;
}