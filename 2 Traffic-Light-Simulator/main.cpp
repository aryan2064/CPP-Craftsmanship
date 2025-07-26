#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// FSM States for the traffic light
enum State { RED, GREEN, YELLOW };

// Pedestrian signal states
enum PedSignal { WALK, DONT_WALK };

struct Config {
    int redDuration;
    int greenDuration;
    int yellowDuration;
    bool pedestrianMode;
};

// Default durations (seconds)
const int DEFAULT_RED    = 5;
const int DEFAULT_GREEN  = 5;
const int DEFAULT_YELLOW = 2;

// Current FSM state and countdown timer
State currentState = RED;
int  timeRemaining  = DEFAULT_RED;

Config config;

PedSignal getPedSignal(State s) {
    if (config.pedestrianMode && s == RED) return WALK;
    return DONT_WALK;
}

string pedToString(PedSignal p) {
    return (p == WALK) ? "WALK" : "DON'T WALK";
}

string stateToString(State s) {
    switch (s) {
        case RED:    return "RED";
        case GREEN:  return "GREEN";
        case YELLOW: return "YELLOW";
        default:     return "UNKNOWN";
    }
}

void displayState() {
    system("cls");

    cout << "========================================\n";
    cout << "       TRAFFIC LIGHT SIMULATOR\n";
    cout << "========================================\n\n";

    // ASCII traffic light housing
    cout << "        +-------+\n";
    cout << "        |  " << (currentState == RED    ? " * " : "   ") << "  |\n";
    cout << "        |  " << (currentState == YELLOW ? " * " : "   ") << "  |\n";
    cout << "        |  " << (currentState == GREEN  ? " * " : "   ") << "  |\n";
    cout << "        +-------+\n\n";

    cout << "  Light:  " << stateToString(currentState) << "\n";
    cout << "  Timer:  " << timeRemaining << "s remaining\n";

    if (config.pedestrianMode) {
        PedSignal ped = getPedSignal(currentState);
        cout << "  Ped:    " << pedToString(ped) << "\n";
    }

    // Visual progress bar
    int total;
    switch (currentState) {
        case RED:    total = config.redDuration;    break;
        case GREEN:  total = config.greenDuration;  break;
        case YELLOW: total = config.yellowDuration;  break;
        default:     total = 1;
    }

    int filled = timeRemaining;
    int empty  = total - filled;
    cout << "\n  [";
    for (int i = 0; i < filled; i++) cout << "=";
    for (int i = 0; i < empty;  i++) cout << " ";
    cout << "]\n";

    cout << "\n  Press Ctrl+C to stop\n";
    cout << "========================================\n";
}

// FSM transition logic:
// Each second, decrement the timer. When it hits zero,
// advance to the next state in the cycle:
//   RED -> GREEN -> YELLOW -> RED -> ...
void updateState() {
    timeRemaining--;

    if (timeRemaining <= 0) {
        switch (currentState) {
            case RED:
                currentState = GREEN;
                timeRemaining = config.greenDuration;
                break;
            case GREEN:
                currentState = YELLOW;
                timeRemaining = config.yellowDuration;
                break;
            case YELLOW:
                currentState = RED;
                timeRemaining = config.redDuration;
                break;
        }
    }
}

void runSimulation() {
    currentState = RED;
    timeRemaining = config.redDuration;

    while (true) {
        displayState();
        Sleep(1000);
        updateState();
    }
}

void showConfig() {
    cout << "\n  Current Configuration:\n";
    cout << "  RED    = " << config.redDuration    << "s\n";
    cout << "  GREEN  = " << config.greenDuration   << "s\n";
    cout << "  YELLOW = " << config.yellowDuration  << "s\n";
    cout << "  Pedestrian signal = " << (config.pedestrianMode ? "ON" : "OFF") << "\n\n";
}

int main() {
    config.redDuration    = DEFAULT_RED;
    config.greenDuration  = DEFAULT_GREEN;
    config.yellowDuration = DEFAULT_YELLOW;
    config.pedestrianMode = false;

    cout << "========================================\n";
    cout << "       TRAFFIC LIGHT SIMULATOR\n";
    cout << "========================================\n\n";
    cout << "  Default durations:\n";
    cout << "    RED    = " << DEFAULT_RED    << "s\n";
    cout << "    GREEN  = " << DEFAULT_GREEN  << "s\n";
    cout << "    YELLOW = " << DEFAULT_YELLOW << "s\n\n";
    cout << "  Customize durations? (y/n): ";

    string input;
    cin >> input;

    if (input == "y" || input == "Y") {
        cout << "  RED duration (seconds): ";
        cin >> config.redDuration;
        if (config.redDuration < 1) config.redDuration = DEFAULT_RED;

        cout << "  GREEN duration (seconds): ";
        cin >> config.greenDuration;
        if (config.greenDuration < 1) config.greenDuration = DEFAULT_GREEN;

        cout << "  YELLOW duration (seconds): ";
        cin >> config.yellowDuration;
        if (config.yellowDuration < 1) config.yellowDuration = DEFAULT_YELLOW;
    }

    cout << "  Enable pedestrian signal? (y/n): ";
    cin >> input;
    if (input == "y" || input == "Y") config.pedestrianMode = true;

    showConfig();
    cout << "  Starting simulation...\n";
    Sleep(1500);

    runSimulation();

    return 0;
}