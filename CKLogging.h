#pragma once

#include <string>

#ifndef CK_LOGGING_H
#define CK_LOGGING_H

enum LogType {
    I, // Information
    W, // Warning
    A, // Announcement
    IM, // Important
    E // Error
};

class CKLogging {
public:
    CKLogging();
    ~CKLogging();

    void Log(const char* Message, LogType LogType = I, const char* FileName = __FILE__, int LineNumber = __LINE__);

private:
    std::string getDate();
    std::string getTime();
    std::string getLogType(LogType LogType);
    bool WriteToFile(const char* Message, LogType LogType, const char* Timestamp, const char* FileName, int LineNumber);
    std::string ExtractFileName(const std::string& filePath);
    std::string FormatDate(std::string Date);
    void LoadConfig(const std::string& ConfigFilePath);

    std::string LogPath;
    std::string LogFileName;
};

#endif // CK_LOGGING_H

