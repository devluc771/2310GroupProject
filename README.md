# UML Diagram
<img width="741" height="964" alt="GroupProjectUML" src="https://github.com/user-attachments/assets/e59966c1-b77a-4c2b-9da3-b510690c74f2" />



# UML Explanation
DataReader Purpose: Responsible for reading the IoT sensor data from CSV files.  
DataWriter Purpose: Writes processed sensor data to output files, creating separate files for each device.   
SensorSimulator Purpose: Simulates multiple IoT sensors generating data, useful for testing the system without real hardware.  
Hub Purpose: Central processing unit that receives data from all sensors, performs temperature conversion, and routes data for output.  

***
## Key Classes and Attributes

### SensorData

- **Attributes:**  
  - `ts`: Unix timestamp (seconds since 1970)  
  - `device`: Unique device ID (MAC address of the IoT sensor)  
  - `co`, `humidity`, `light`, `lpg`, `motion`, `smoke`, `temp`: Sensor readings

- **Methods:**  
  - `parseRow(row: string)`: Converts a CSV row to a `SensorData` object  
  - Getter methods for each attribute

***

### Relationship Table

| From            | To          | Relationship Type      | Meaning / Role in System                              |
|-----------------|-------------|-----------------------|-------------------------------------------------------|
| DataReader      | SensorData  | Association (Creates) | Creates SensorData objects from CSV file rows         |
| SensorSimulator | SensorData  | Association (Creates) | Creates SensorData objects with simulated values      |
| Hub             | SensorData  | Aggregation           | Maintains a collection (vector) of SensorData objects |
| Hub             | DataWriter  | Association (Uses)    | Sends processed data to DataWriter for output         |
| DataWriter      | SensorData  | Association (Uses)    | Uses SensorData objects to generate output files      |
| Hub             | DataReader  | Association (Uses)    | Utilizes DataReader to obtain sensor data             |

***

## Relationship Details

- **Association (Creates/Uses):** Shows creation or direct usage of objects from another class.
- **Aggregation:** Indicates that the Hub maintains a group of SensorData objects, which exist independently of the Hub.
- **Direction:** Arrows point from the class that uses/aggregates/creates toward the class it interacts with.

***

<img width="745" height="442" alt="image" src="https://github.com/user-attachments/assets/490f161a-ec5b-4f3f-8dd0-1bc7201138ee" />
