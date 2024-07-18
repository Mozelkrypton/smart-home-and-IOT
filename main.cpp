#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

/* Base class Device */
class Device {
protected:
    string name;
    bool status;
    string type;

public:
    Device() : name("Unknown"), type("Unknown"), status(false) {}
    Device(const string& n, const string& t) : name(n), type(t), status(false) {}
    Device(const Device& other) : name(other.name), type(other.type), status(other.status) {}
    virtual ~Device() {}

    string getName() const { return name; }
    string getType() const { return type; }
    bool getStatus() const { return status; }

    void setStatus(bool s) { status = s; }

    virtual void display() const {
        cout << "Device Name: " << name << ", Type: " << type << ", Status: " << (status ? "ON" : "OFF") << endl;
    }
};

/* Derived class Light */
class Light : public Device {
public:
    Light(const string& n) : Device(n, "Light") {}

    void display() const override {
        cout << "Light Name: " << name << ", Status: " << (status ? "ON" : "OFF") << endl;
    }
};

/* Derived class Appliance */
class Appliance : public Device {
public:
    Appliance(const string& n) : Device(n, "Appliance") {}

    void display() const override {
        cout << "Appliance Name: " << name << ", Status: " << (status ? "ON" : "OFF") << endl;
    }
};

/* Derived class Thermostat */
class Thermostat : public Device {
public:
    Thermostat(const string& n) : Device(n, "Thermostat") {}

    void display() const override {
        cout << "Thermostat Name: " << name << ", Status: " << (status ? "ON" : "OFF") << endl;
    }
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
    vector<Device*> devices;

    /* Adding some example devices */
    devices.push_back(new Light("Living Room Light"));
    devices.push_back(new Appliance("Kitchen Oven"));
    devices.push_back(new Thermostat("Bedroom Thermostat"));

    while (true) {
        system("CLS");  /* Clear screen for Windows, use "clear" for Linux/Mac */

        cout << "------------------------------------WELCOME HOME SMART HOME CONTROLLER-----------------------------------------------\n\n";
        cout << "[1]----------TURN ON DEVICE----------\n";
        cout << "[2]----------TURN OFF DEVICE---------\n";
        cout << "[3]----------CHECK DEVICE STATUS----\n";
        cout << "[4]==========QUIT====================\n\n";

        cout << "ENTER YOUR CHOICE PLEASE: ";
        string choice;
        getline(cin, choice);

        try {
            if (choice == "1") {
                /* List devices and let user select one to turn on */
                cout << "DEVICES:\n";
                for (size_t i = 0; i < devices.size(); ++i) {
                    cout << "[" << i + 1 << "] " << devices[i]->getName() << " (" << devices[i]->getType() << ")\n";
                }

                cout << "Enter device number to turn ON: ";
                int deviceNum;
                cin >> deviceNum;
                if (deviceNum < 1 || deviceNum > static_cast<int>(devices.size())) {
                    throw out_of_range("Invalid device number.");
                }
                cin.ignore();  /* Clear newline from input buffer */
                turnOn(*devices[deviceNum - 1]);
            } else if (choice == "2") {
                /* List devices and let user select one to turn off */
                cout << "DEVICES:\n";
                for (size_t i = 0; i < devices.size(); ++i) {
                    cout << "[" << i + 1 << "] " << devices[i]->getName() << " (" << devices[i]->getType() << ")\n";
                }

                cout << "Enter device number to turn OFF: ";
                int deviceNum;
                cin >> deviceNum;
                if (deviceNum < 1 || deviceNum > static_cast<int>(devices.size())) {
                    throw out_of_range("Invalid device number.");
                }
                cin.ignore();  /* Clear newline from input buffer */
                turnOff(*devices[deviceNum - 1]);
            } else if (choice == "3") {
                /* List devices and let user select one to check status */
                cout << "DEVICES:\n";
                for (size_t i = 0; i < devices.size(); ++i) {
                    cout << "[" << i + 1 << "] " << devices[i]->getName() << " (" << devices[i]->getType() << ")\n";
                }

                cout << "Enter device number to check status: ";
                int deviceNum;
                cin >> deviceNum;
                if (deviceNum < 1 || deviceNum > static_cast<int>(devices.size())) {
                    throw out_of_range("Invalid device number.");
                }
                cin.ignore();  /* Clear newline from input buffer */
                checkStatus(*devices[deviceNum - 1]);
            } else if (choice == "4") {
                break;  /* Exit the loop and end the program */
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.ignore();
        }

        cout << "Press enter to continue . . .";
        cin.ignore();  /* Wait for user to press enter before continuing */
    }

   /*  //Cleanup dynamically allocated memory 
    for (Device* device : devices) {
        delete device;
    }*/
    return 0;
}
