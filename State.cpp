#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Forward Declaration
class TrafficLight;

// State Interface
class TrafficLightState {
    public:
        virtual void changeState(TrafficLight* trafficLight) = 0;
        virtual ~TrafficLightState() = default;
};

class RedState : public TrafficLightState {
    public:
        void changeState(TrafficLight* trafficLight) override;
};
class YellowState : public TrafficLightState {
    public:
        void changeState(TrafficLight* trafficLight) override;
};
class GreenState : public TrafficLightState {
    public:
        void changeState( TrafficLight* trafficLight) override;
};

class TrafficLight {
    private:
        std::shared_ptr<TrafficLightState> state;
        // RedState redState;
        // YellowState yellowState;
        // GreenState greenState;
    public:
        TrafficLight(std::shared_ptr<TrafficLightState> initState) {
            state = initState;
        }
        void setState(std::shared_ptr<TrafficLightState> newState) {
            state = newState;
        }
        void change() {
            state->changeState(this);
        }
        // TrafficLightState* getRedState() {
        //     return &redState;
        // }
        // TrafficLightState* getYellowState() {
        //     return &yellowState;
        // }
        // TrafficLightState* getGreenState() {
        //     return &greenState;
        // }
};

void RedState::changeState(TrafficLight* trafficLight) {
    cout << "Traffic Light is Red,  Switching to Green" << endl;
    trafficLight->setState(std::make_shared<GreenState>());
}

void YellowState::changeState(TrafficLight* trafficLight) {
    cout << "Traffic Light is Yellow,  Switching to Red" << endl;
    trafficLight->setState(std::make_shared<RedState>());
}

void GreenState::changeState( TrafficLight* trafficLight) {
    cout << "Traffic Light is Green, Switching to Yellow" << endl;
    trafficLight->setState(std::make_shared<YellowState>());
    // trafficLight->setState(trafficLight->getYellowState());
}

int main() {
    auto redState = make_shared<RedState>();
    TrafficLight trafficLight(redState);
    for (int i=0; i<6; i++) {
        trafficLight.change();
    }
    return 0;
}