#include <iostream>
#include <stdexcept>

using namespace std;

class Device {
public:
    Device();
    virtual ~Device();
    void enable();
    void activate();
    
private:
    bool m_bEnabled;
};

Device::Device() : m_bEnabled(false) { } // Default Constructor
Device::~Device() { }                    // Default Destructor

void Device::enable()
{
    m_bEnabled = true;
}

void Device::activate()
{
    
    // Simulate activing the device.
    // TODO: Replace this with a try catch block
    try {
        if (m_bEnabled == false)
    {
        throw std::runtime_error("Device must be enabled first!");
    }
        cout << "Device is activated!" << endl;

    } catch (runtime_error ex) {
        cout << ex.what() << endl;
    }

        
    return;
}

int main(int argc, const char * argv[]) {
    Device device;
    device.enable();
    device.activate();
    return 0;
}