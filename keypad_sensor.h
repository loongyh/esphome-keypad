#include "esphome.h"
#include "Keypad.h"

class KeypadSensor : public Component, public Sensor {

    public:

    static const byte n_rows = 2;
    static const byte n_cols = 3;
    
    char keys[n_rows][n_cols] = {
    {'1','2','3'},
    {'4','5','6'}
    };
    
    byte colPins[n_cols] = {26, 13, 27};
    byte rowPins[n_rows] = {14, 12};
    
    Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 

    void setup() override {
    // This will be called by App.setup()
    }
    void loop() override {
    // This will be called by App.loop()
        char myKey = myKeypad.getKey();
        if (myKey != NO_KEY){
            int key = myKey - 48;
            publish_state(key);
        }
    }
};