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

        vector<SensorData> allData = reader.readData();
    if (allData.empty()) {
        cerr << "No data loaded from test.csv\n";
        return 1;
    }

    cout << "Loaded " << allData.size()
              << " sensor records from test.csv\n";

    // 2. Push data into Hub
    Hub hub;
    for (const auto &sd : allData) {
        hub.receiveData(sd);
    }

    // 3. Run your processing logic
    hub.processData();

    // 4. Pick a concrete device id to test with
    string deviceId = allData.front().getDevice();
    vector<SensorData> filtered = hub.filterByDevice(deviceId);

    cout << "Records for device " << deviceId
              << ": " << filtered.size() << std::endl;

    // 5. Write filtered data to an output CSV
    string outFile = "output.csv";
    DataWriter writer(outFile);

    if (!writer.openFile()) {
        cerr << "Failed to open " << outFile << " for writing\n";
        return 1;
    }

    for (const auto &sd : filtered) {
        writer.writeData(sd);
    }

    writer.closeFile();

    cout << "Wrote filtered data to " << outFile << std::endl;
    return 0;
}
