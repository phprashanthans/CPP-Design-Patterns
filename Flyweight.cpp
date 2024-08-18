#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// #define CharacterExample
#define RobotExample

#ifdef CharacterExample
// Flyweight class
class Character {
    private:
        char m_intrinsicState;
    public:
        Character(char intrinsicState) : m_intrinsicState(intrinsicState) {}
        void draw(int extrinsicState) {
            std::cout << "Drawing character " << m_intrinsicState << 
            " at position:" << extrinsicState << std::endl;
        }
};

// Flyweight Factory class
class CharacterFactory {
    private:
        unordered_map<char, Character*> m_characters;
    public:
        Character* getCharacter(char key) {
            if(m_characters.find(key) == m_characters.end()) {
                m_characters[key] = new Character(key);
            }
            return m_characters[key];
        }
};

int main() {
    CharacterFactory characterFactory;
    int position = 0;
    characterFactory.getCharacter('A')->draw(position++);
    characterFactory.getCharacter('B')->draw(position++);
    return 0;
}
#endif

#ifdef RobotExample

class Sprites {

};

class IRobot {
    public:
        virtual void display(int x, int y) = 0;
};

// Flyweight class with intrinsic elements
class HumanoidRobot : public IRobot {
    private:
        string type;
        Sprites body;
    public:
        HumanoidRobot(string type, Sprites body) : type(type), body(body) {}
        string getType(){
            return type;
        }
        Sprites getBody(){
            return body;
        }
        void display(int x, int y) override {
            cout << "Rendering Humanoid Robot at position:" << x << ", " << y << std::endl; 
        }
};

class RoboticDog : public IRobot {
    private:
        string type;
        Sprites body;
    public:
        RoboticDog(string type, Sprites body) : type(type), body(body) {}
        string getType(){
            return type;
        }
        Sprites getBody(){
            return body;
        }
        void display(int x, int y) override {
            cout << "Rendering Robotic Dog at position:" << x << ", " << y << std::endl; 
        }
};

class RoboticFactory {
    private:
        unordered_map<string, IRobot*> roboticObjectCache;
    public:
        IRobot* createRobot(string robotType) {
            if(roboticObjectCache.find(robotType) != roboticObjectCache.end()) {
                return roboticObjectCache[robotType];
            } else {
                if(robotType == "Humanoid") {
                    Sprites humanoidSprites;
                    IRobot* humanoidRobot = new HumanoidRobot(robotType, humanoidSprites);
                    roboticObjectCache[robotType] = humanoidRobot;
                    return humanoidRobot;
                } else if (robotType == "RoboticDog") {
                    Sprites roboticDogSprites;
                    IRobot* roboticDog = new RoboticDog(robotType, roboticDogSprites);
                    roboticObjectCache[robotType] = roboticDog;
                    return roboticDog;
                }          
            }
            return NULL;
        }
};

int main() {
    RoboticFactory rb;

    IRobot* humanoidRobot = rb.createRobot("Humanoid");
    humanoidRobot->display(1, 3);
    IRobot* roboticDog = rb.createRobot("RoboticDog");
    roboticDog->display(10, 30);
}

#endif