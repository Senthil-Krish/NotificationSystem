#include "Logger.h"
#include <fstream>
#include <time.h>
#include <sstream>
Logger *Logger::logger_instance = 0;
ofstream Logger::log_file("/home/senthil/Desktop/LogFile.txt");
Logger *Logger::GetInstance()
{
    if(!logger_instance)
    {
        logger_instance = new Logger;
    }
    return logger_instance;
}

void Logger::AddLog(string module, string message)
{
    time_t  timev;
    time_t seconds = time(&timev);
    stringstream ss;
    ss << seconds;
    string ts = ss.str();
    
    log_file << ts << "|" << module << "|" << message <<endl;
}
Logger::~Logger()
{
log_file << "Closing file" <<endl;
log_file.close();
}