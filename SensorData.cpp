#include "SensorData.h"
#include <sstream>

SensorData::SensorData() : ts(0), co(0), humidity(0), light(0), lpg(false), motion(0), smoke(0), temp(0) //default constructor where everything is blank
{
}

void SensorData::parseRow(string row) //Used ChatGPT to help create parseRow to read a row from the .csv and convert it into a SensorDate object
{
    stringstream ss(row);
    string value;

    // timestamp
    getline(ss, value, ',');  //reads everything until a comma and stores into value
    ts = stod(value); //converts value from a string to a double

    // device
    getline(ss, value, ',');
    device = value;

    // co
    getline(ss, value, ',');
    co = stod(value);

    // humidity
    getline(ss, value, ',');
    humidity = stod(value);

    // light
    getline(ss, value, ',');
    light = stod(value);

    // lpg (0 or 1)
    getline(ss, value, ',');
    lpg = (value == "1");

    // motion
    getline(ss, value, ',');
    motion = stod(value);

    // smoke
    getline(ss, value, ',');
    smoke = stod(value);

    // temp
    getline(ss, value, ',');
    temp = stod(value);
}

long long SensorData::getTs() const
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

double SensorData::getLight() const
{
    return light;
}

bool SensorData::getLpg() const
{
    return lpg;
}

double SensorData::getMotion() const
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