#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Device {
private:
    string name;
    bool status;
    string type;

public:
    Device(const string& n, const string& t) : name(n), type(t), status(false) {}

    string getName() const { return name; }
    string getType() const { return type; }
    bool getStatus() const { return status; }

    void setStatus(bool s) { status = s; }
};

void turnOn(Device& device) {
    device.setStatus(true);
    cout << device.getName() << " is now ON.\n";
}

void turnOff(Device& device) {
    device.setStatus(false);
    cout << device.getName() << " is now OFF.\n";
}

void checkStatus(const Device& device) {
    cout << device.getName() << " is currently " << (device.getStatus() ? "ON.\n" : "OFF.\n");
}

int main() {
    vector<Device> devices;

    // Adding some example devices
    devices.push_back(Device("Living Room Light", "Light"));
    devices.push_back(Device("Kitchen Oven", "Appliance"));
    devices.push_back(Device("Bedroom Thermostat", "Thermostat"));

    while (true) {
        system("CLS");  // Clear screen for Windows, use "clear" for Linux/Mac

        cout << "------------------------------------WELCOME HOME SMART HOME CONTROLER-----------------------------------------------\n\n";
        cout << "[1]----------TURN ON DEVICE----------\n";
        cout << "[2]----------TURN OFF DEVICE---------\n";
        cout << "[3]----------CHECK DEVICE STATUS----\n";
        cout << "[4]==========QUIT====================\n\n";

        cout << "ENTER YOUR CHOICE PLEASE: ";
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            // List devices and let user select one to turn on
            cout << "DEVICES:\n";
            for (int i = 0; i < devices.size(); ++i) {
                cout << "[" << i + 1 << "] " << devices[i].getName() << " (" << devices[i].getType() << ")\n";
            }

            cout << "Enter device number to turn ON: ";
            int deviceNum;
            cin >> deviceNum;
            cin.ignore();  // Clear newline from input buffer
            turnOn(devices[deviceNum - 1]);
        } else if (choice == "2") {
            // List devices and let user select one to turn off
            cout << "DEVICES:\n";
            for (int i = 0; i < devices.size(); ++i) {
                cout << "[" << i + 1 << "] " << devices[i].getName() << " (" << devices[i].getType() << ")\n";
            }

            cout << "Enter device number to turn OFF: ";
            int deviceNum;
            cin >> deviceNum;
            cin.ignore();  // Clear newline from input buffer
            turnOff(devices[deviceNum - 1]);
        } else if (choice == "3") {
            // List devices and let user select one to check status
            cout << "DEVICES:\n";
            for (int i = 0; i < devices.size(); ++i) {
                cout << "[" << i + 1 << "] " << devices[i].getName() << " (" << devices[i].getType() << ")\n";
            }

            cout << "Enter device number to check status: ";
            int deviceNum;
            cin >> deviceNum;
            cin.ignore();  // Clear newline from input buffer
            checkStatus(devices[deviceNum - 1]);
        } else if (choice == "4") {
            break;  // Exit the loop and end the program
        } else {
            continue;  // Restart loop if choice is invalid
        }

        cout << "Press enter to continue . . .";
        cin.ignore();  // Wait for user to press enter before continuing
    }

    return 0;
}


