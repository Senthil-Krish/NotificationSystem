#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
using namespace std;
class Logger
{
    static Logger *logger_instance;
    static ofstream log_file;
public:
static Logger* GetInstance();
void AddLog(string module, string message);
~Logger();
};

//ostream Logger::log_file = 0;

#endif // LOGGER_H
