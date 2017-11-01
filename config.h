/*
read_config, confguration parser

Copyright (c) 2017 Thomas Wink <thomas@geenbs.nl>

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#ifndef config_H_
#define config_H_

// This struct details the currently supported data types 
typedef struct applicationConfguration{
    char serverName[200];
    int serverPort;
    size_t sendIntervalSecs;
    char gpsDeviceName[100];
    char gpsDeviceNmeaProtocol[100];
    long long int imei;
    char adminEmail[50];
    char sentence1[500];
}appConfig;

extern int getConfig(appConfig *config, char *filename);

#endif
