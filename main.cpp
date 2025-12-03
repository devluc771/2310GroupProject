#include <iostream>
#include "Hub.h"
#include "DataReader.h"
#include "DataWriter.h"
#include "SensorData.h"

using namespace std;

int main()
{
    const string file = "test.csv";
    DataReader reader(file);

    // Load data
    vector<SensorData> allData = reader.readData();
    if (allData.empty()) {
        cerr << "No data loaded from test.csv\n";
        return 1;
    }

    cout << "Loaded " << allData.size()
              << " sensor records from test.csv\n";

    // Process with Hub (if needed)
    Hub hub;
    for (const auto &sd : allData)
        hub.receiveData(sd);

    hub.processData();

    writeOutputFiles(allData);

    cout << "Wrote 7 output CSV files." << endl;
    return 0;
}