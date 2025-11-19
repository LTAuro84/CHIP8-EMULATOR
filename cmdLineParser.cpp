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
        string cmdOption(argv[i]);

        if(cmdOption.at(0) == '-') {
            if (cmdOption == "-h" || cmdOption == "--help") {
                this -> printHelpMessage();
            }
            else if (cmdOption == "-r" || cmdOption == "--romFileName") {
                i++;
                string  auxName(argv[i]);
                this -> setRomFileName(auxName);
            }
            else if (cmdOption == "-l" || cmdOption == "--logLevel") { 
                i++;
                string logLevel(argv[i]);
                if (!isdigit(logLevel.at(0))) {
                    logger -> log("Parameter must be a number 0 - 4", ELogLevel::ERROR);
                    exit(1);
                }
                this -> setLogLevel(stoi(logLevel));
            }
            else {
                string param(argv[i]);
                logger -> log("Unknown parameter: " + param, ELogLevel::ERROR);
                exit(1);
            }

        }
        else {
            string param(argv[i]);
            logger -> log("Unknown parameter: " + param, ELogLevel::ERROR);
            exit(1);
        }
    }
}

bool TCmdLineParser::isRomeFileNameSet() {
    return !(romFileName == "");
}