#ifndef PROCESS_H
#define PROCESS_H

#include <string>

const int processCodeMaxChar = 3;

struct Process
    {char processCode[processCodeMaxChar] = {'0','0','0'};
    std::string processParam;};

#endif // PROCESS_H
