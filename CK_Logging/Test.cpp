#include "CKLogging.h"

#define LOG(logger, message, logType) \
    logger.Log(message, logType, __FILE__, __LINE__);

CKLogging Logger;

int main() {
    LOG(Logger, "This is a test log message", I);
    return 0;
}