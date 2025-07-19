#include <iostream>
#include <Windows.h>
#include <ShlObj.h> // For SHGetFolderPath
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to get the path to the AppData\Roaming folder
std::string GetRoamingFolderPath() {
    char path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path))) {
        return std::string(path);
    }
    return "";
}

// Function to generate a random 16-digit number as a string
std::string GenerateRandomNumber() {
    std::string result;
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < 16; ++i) {
        result.push_back('0' + rand() % 10); // Append a random digit
    }
    return result;
}

int main() {
    // Step 1: Get the AppData\Roaming folder path
    std::string roamingPath = GetRoamingFolderPath();
    if (roamingPath.empty()) {
        std::cerr << "Failed to get the AppData\\Roaming folder path." << std::endl;
        return 1;
    }

    // Step 3 & 4: Ensure the Goldberg SteamEmu Saves and settings folders exist
    std::string goldbergPath = roamingPath + "\\Goldberg SteamEmu Saves";
    std::string settingsPath = goldbergPath + "\\settings";
    if (SHCreateDirectoryEx(NULL, goldbergPath.c_str(), NULL) != ERROR_SUCCESS &&
        GetLastError() != ERROR_ALREADY_EXISTS) {
        std::cerr << "Failed to create the Goldberg SteamEmu Saves folder." << std::endl;
        return 1;
    }

    if (SHCreateDirectoryEx(NULL, settingsPath.c_str(), NULL) != ERROR_SUCCESS &&
        GetLastError() != ERROR_ALREADY_EXISTS) {
        std::cerr << "Failed to create the settings folder." << std::endl;
        return 1;
    }

    // Step 5: Write "schinese" to language.txt
    std::ofstream languageFile(settingsPath + "\\language.txt");
    if (!languageFile) {
        std::cerr << "Failed to open language.txt for writing." << std::endl;
        return 1;
    }
    languageFile << "schinese";
    languageFile.close();

    // Step 6: Write a random 16-digit number to user_steam_id.txt
    std::ofstream steamIdFile(settingsPath + "\\user_steam_id.txt");
    if (!steamIdFile) {
        std::cerr << "Failed to open user_steam_id.txt for writing." << std::endl;
        return 1;
    }
    steamIdFile << GenerateRandomNumber();
    steamIdFile.close();

    std::cout << "Operation completed successfully." << std::endl;
    return 0;
}
