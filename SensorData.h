#ifndef SENSOR_H
#define SENSOR_H
using namespace std;
#include <string>

class SensorData
{
    public:
        SensorData(); //SensorData Constructor
        void parseRow(string row);  //takes a line from the CSV and turns it into a SensorData object
        double getTs() const;       //accessors
        string getDevice() const;
        double getHumidity() const;
        double getCo() const;
        bool getLight() const;
        bool getMotion() const;
        double getSmoke() const;
        double getTemp() const;
        void setTemp(double t);
        double getLpg() const;

    private:
        double ts; //timestamp
        string device; //device ID
        double co;
        double humidity;
        bool light;
        double lpg;
        bool motion;
        double smoke;
        double temp;
};
#endif