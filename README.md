# CKLogging Library

CKLogging is a `C++ library` for simple and efficient Logging of messages to a file. This library provides an easy way to log messages with various log types and timestamps into a log file.

## ⚙️ - Still in Development!
Be aware that this Library is not ready to use and still in active development!

## 🔧 - Features

- **Automatic Directory and File Creation**: The library automatically creates a `Logs` directory and a log file with the current date if they do not already exist.
- **Log Types**: Supports various log types such as following ones:
   * Information
   * Warning
   * Announcement
   * Important
   * Error
- **Timestamps**: Each log message is timestamped with the date and time.
- **Filename and Line Number**: Automatically captures the filename and line number from which the log message originates.
- **Easy Usage**: A macro `LOG` simplifies logging messages without requiring the user to manually input `__FILE__` and `__LINE__`.

## 🛠️ - Installation

Coming Soon!

### 💻 - Usage - Example Code
```
#include "CKLogging.h"

#define LOG(logger, message, logType) \
    logger.Log(message, logType, __FILE__, __LINE__);

CKLogging Logger;

int main() {
    LOG(Logger, "This is a test log message", I);
    return 0;
}
```

### 📝 - Log Types

The following log types are available:
- `I`: Information
- `W`: Warning
- `A`: Announcement
- `IM`: Important
- `E`: Error

### 📄 - Log File

The log file is created in the `Logs` directory and has the format `LogFile_YYYY_MM_DD.log`. Each log message is prefixed with a timestamp, log type, filename, and line number.

### 📧 - Contact
Coming Soon!


-> Added some Changes here, because of my test Project SubTracker.
