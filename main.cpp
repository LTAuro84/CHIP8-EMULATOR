#include "logger.h"

using namespace std;

int main (int argc, char** argv) {

    std::shared_ptr<TLogger> logger = TLogger::getInstance();

    logger->log("This is an ERROR message!!!", ELogLevel::ERROR);
    logger->log("This is a WARNING message!!!", ELogLevel::WARN);
    logger->log("This is an INFO message!!!", ELogLevel::INFO);
    logger->log("This is a DEBUG message!!!", ELogLevel::DEBUG);

    return 0;
    
}