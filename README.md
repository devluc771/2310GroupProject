# UML Diagram
<img width="741" height="964" alt="GroupProjectUML" src="https://github.com/user-attachments/assets/e59966c1-b77a-4c2b-9da3-b510690c74f2" />



# UML Explanation
DataReader Purpose: Responsible for reading the IoT sensor data from CSV files.  
DataWriter Purpose: Writes processed sensor data to output files, creating separate files for each device.   
SensorSimulator Purpose: Simulates multiple IoT sensors generating data, useful for testing the system without real hardware.  
Hub Purpose: Central processing unit that receives data from all sensors, performs temperature conversion, and routes data for output.  

***

## Main Data Object: SensorData

- **Has:**  
  - `ts`: When the reading happened (timestamp)  
  - `device`: Which sensor sent it (like a MAC address)  
  - Readings: `co`, `humidity`, `light`, `lpg`, `motion`, `smoke`, `temp`

- **Can Do:**  
  - `parseRow(row)`: Takes a line from a CSV and turns it into a SensorData object  
  - Getters: Lets you access each value

***

## How The Parts Connect

| From   | To         | Type            | What It Means                                      |
|--------|------------|-----------------|----------------------------------------------------|
| DataReader | SensorData | Makes          | Reads file and makes SensorData objects             |
| SensorSimulator | SensorData | Makes       | Makes fake SensorData objects for testing           |
| Hub    | SensorData | Groups Together | Hub keeps a bunch of SensorData objects             |
| Hub    | DataWriter | Sends To        | Hub gives processed data to DataWriter for saving   |
| DataWriter | SensorData | Uses           | DataWriter uses SensorData to make files            |
| Hub    | DataReader | Reads From      | Hub uses DataReader to get sensor data from files   |

***

## More Detail on Connections

- **Makes / Uses**: Means a part either creates something or works with it directly.
- **Groups Together**: Means the Hub keeps a bunch of data objects, kind of like a collection or list.
- **Direction**: Just shows which part starts things (like, DataReader makes SensorData).

***

<img width="745" height="442" alt="image" src="https://github.com/user-attachments/assets/490f161a-ec5b-4f3f-8dd0-1bc7201138ee" />
