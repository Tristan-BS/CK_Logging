#include "CKLogging.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <direct.h>
#include <sys/stat.h>
#include <sys/types.h>

using std::cout;
using std::cerr;
using std::endl;

struct stat info;

std::string FileName;
std::ofstream File;

CKLogging::CKLogging() {
    FileName = "LogFile_" + getDate() + ".log";
    cout << FileName << endl;

    if (stat("Logs", &info) != 0) {
        cout << "Directory does not exist, creating directory" << endl;
        if (_mkdir("Logs") == 0) {
            cout << "Directory created successfully" << endl;
        }
        else {
            cerr << "Error creating directory" << endl;
        }
    }

    // Check if file exists
    std::string filePath = "Logs/" + FileName;
    if (stat(filePath.c_str(), &info) == 0) {
        // File exists, open in append mode
        File.open(filePath, std::ios::app);
        if (File.is_open()) {
            cout << "File opened successfully in append mode" << endl;
        }
        else {
            cerr << "Error opening file in append mode" << endl;
        }
    }
    else {
        // File does not exist, create new file
        File.open(filePath);
        if (File.is_open()) {
            cout << "File created successfully" << endl;
            File << "----------          CK Logging          ----------" << endl;
        }
        else {
            cerr << "Error creating file" << endl;
        }
    }
}

CKLogging::~CKLogging() {
    if (File.is_open()) {
        File.close();
    }
}

void CKLogging::Log(const char* Message, LogType LogType, const char* FileName, int LineNumber) {
    std::string Timestamp = FormatDate(getDate()) + " " + getTime();
    std::string ShortFileName = ExtractFileName(FileName);
    WriteToFile(Message, LogType, Timestamp.c_str(), ShortFileName.c_str(), LineNumber);
}

std::string CKLogging::getDate() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    std::string Year = std::to_string(1900 + ltm.tm_year);
    std::string Month = std::to_string(1 + ltm.tm_mon);
    std::string Day = std::to_string(ltm.tm_mday);

    if (Month.length() == 1) {
        Month = "0" + Month;
    }
    if (Day.length() == 1) {
        Day = "0" + Day;
    }

    return Year + "_" + Month + "_" + Day;
}

std::string CKLogging::getTime() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    std::string Hour = std::to_string(ltm.tm_hour);
    std::string Minute = std::to_string(ltm.tm_min);
    std::string Second = std::to_string(ltm.tm_sec);

    if (Hour.length() == 1) {
        Hour = "0" + Hour;
    }
    if (Minute.length() == 1) {
        Minute = "0" + Minute;
    }
    if (Second.length() == 1) {
        Second = "0" + Second;
    }

    return Hour + ":" + Minute + ":" + Second;
}

std::string CKLogging::getLogType(LogType LogType) {
    switch (LogType) {
    case I: return "INFORMATION";
    case W: return "WARNING";
    case A: return "ANNOUNCEMENT";
    case IM: return "IMPORTANT";
    case E: return "ERROR";
    }
    return std::string();
}

std::string CKLogging::FormatDate(std::string Date) {
    std::string Year = Date.substr(0, 4);
    std::string Month = Date.substr(5, 2);
    std::string Day = Date.substr(8, 2);
    return Day + "." + Month + "." + Year;
}

bool CKLogging::WriteToFile(const char* Message, LogType LogType, const char* Timestamp, const char* FileName, int LineNumber) {
    if (File.is_open()) {
        File << "[" << Timestamp << "] ";
        File << "[" << getLogType(LogType) << "] ";
        File << "[" << FileName << ":" << LineNumber << "] ";
        File << Message << endl;
        return true;
    }
    return false;
}

std::string CKLogging::ExtractFileName(const std::string& filePath) {
    size_t pos = filePath.find_last_of("/\\");
    if (pos != std::string::npos) {
        return filePath.substr(pos + 1);
    }
    return filePath;
}

