#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LogProcessor{
    protected:
        int INFO=1;
        int DEBUG=2;
        int ERROR=3;
        LogProcessor* nextLogProcessor;
    public:
        LogProcessor* setNextLogProcessor(LogProcessor* logProcessor){
            nextLogProcessor = logProcessor;
            return nextLogProcessor;
        }
        virtual void log(int logLevel, string msg) {
            if(nextLogProcessor!=NULL){
                nextLogProcessor->log(logLevel, msg);
            } else {
                cout << "Invalid Log request" << endl;
            }
        }
};

class InfoLogProcessor : public LogProcessor {
    public:
        void log(int logLevel, string msg) override {
            if(logLevel == INFO){
                std::cout << "INFO:" << msg << std::endl;
            } else {
                LogProcessor::log(logLevel, msg);
            }
        }
};
class DebugLogProcessor : public LogProcessor {
    public:
        void log(int logLevel, string msg) {
            if(logLevel == DEBUG){
                std::cout << "DEBUG:" << msg << std::endl;
            } else {
                LogProcessor::log(logLevel, msg);
            }
        }
};
class ErrorLogProcessor : public LogProcessor {
    public:
        void log(int logLevel, string msg) {
            if(logLevel == ERROR){
                std::cout << "ERROR:" << msg << std::endl;
            } else {
                LogProcessor::log(logLevel, msg);
            }
        }
};

int main(){
    LogProcessor *infolog = new InfoLogProcessor();
    LogProcessor *dbglog = new DebugLogProcessor();
    LogProcessor *errlog = new ErrorLogProcessor();
    infolog->setNextLogProcessor(dbglog);
    dbglog->setNextLogProcessor(errlog);
    infolog->log(1, "Halo Zetsu Here !!");
    return 0;
}