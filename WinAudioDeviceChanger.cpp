// WinAudioDeviceChanger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

void DisplayHelp() {
    std::cout << "AudioConsoleApp Help:" << std::endl;
    std::cout << "  --help                      - Displays this help message." << std::endl;
    std::cout << "  --version                   - Displays the version information." << std::endl;
    std::cout << "  --setoutput [device name]   - Sets the output device to the specified device name." << std::endl;
}

void SetOutputDevice(const std::string& deviceName) {
    if (deviceName.empty()) {
        std::cout << "Error: Invalid device name." << std::endl;
        return;
    }

    // Code to set the output device using the deviceName goes here.
    std::cout << "Setting output to: " << deviceName << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        DisplayHelp();
        return 0;
    }

    std::string command = argv[1];
    if (command == "--help" || command == "-h") {
        DisplayHelp();
    }
    else if (command == "--version" || command == "-v") {
        std::cout << "WinAudioDeviceChanger Version 0.1.0" << std::endl;
    }
    else if (command == "--setoutput") {
        if (argc > 2) {
            std::stringstream ss;
            for (int i = 2; i < argc; ++i) {
                if (i != 2) ss << " ";
                ss << argv[i];
            }
            SetOutputDevice(ss.str());
        }
        else {
            std::cout << "Error: No device name specified." << std::endl;
        }
    }
    else {
        std::cout << "Unknown command. Type '--help' for available commands." << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
