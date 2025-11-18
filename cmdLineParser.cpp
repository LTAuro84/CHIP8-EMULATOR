#include <cctype>
#include "cmdLineParser.h"
using namespace std;

void TCmdLineParser::printHelpMessage() {
    cout << "Usage: lcc [options] file..." << endl;
    cout << "Options: " << endl;
    cout << "   -h, --help              Display this help information" << endl;
    cout << "   -r, --romFileName       Set the rom file path to be used" << endl;
    cout << "   -l, --logLevel          Set the desired log level [NONE = 0, ERROR = 1, WARN = 2, INFO = 3, DEBUG = 4]" << endl; 
}

void TCmdLineParser::setRomFileName(string new_name) {
    this->romFileName = new_name;
}

void TCmdLineParser::setLogLevel(int logLevel) {
    this -> logLevel = logLevel;
}

TCmdLineParser::TCmdLineParser()
    : romFileName(""), logLevel(-1) {
        logger = TLogger::getInstance();
    }

void TCmdLineParser::parseCmdLine(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        string auxStr(argv[i]);

        if(auxStr.at(0) == '-') {
            if (auxStr == "-h" || auxStr == "--help") {
                this -> printHelpMessage();
            }
        }
    }
}