#ifndef SENSOR_H
#define SENSOR_H
using namespace std;
#include <string>

class SensorData
{
    public:
        SensorData(); //SensorData Constructor
        void parseRow(string row);  //takes a line from the CSV and turns it into a SensorData object
        long long getTs() const;       //accessors
        string getDevice() const;
        double getHumidity() const;
        double getCo() const;
        double getLight() const;
        double getMotion() const;
        double getSmoke() const;
        double getTemp() const;
        void setTemp(double t);
        bool getLpg() const;

    private:
        long long ts; //timestamp
        string device; //device ID
        double co;
        double humidity;
        double light;
        bool lpg;
        double motion;
        double smoke;
        double temp;
};
#endif