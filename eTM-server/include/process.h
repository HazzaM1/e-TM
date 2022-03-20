#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>
// KEEP IT STD::STRING, QSTRING CAUSES ERROR

const int processCodeMaxChar = 3;

struct Process
    {int appID;
     int clientID;
     char processCode[processCodeMaxChar] = {'0','0','0'};
     std::vector<std::string> processParam  = {};};

struct clientDetails
    {int appID = 0;
     int clientID = 0;
     std::string channelID;};

#endif // PROCESS_H
