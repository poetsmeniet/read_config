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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#define CONFIGFILE "config.txt"
#define MAXLEN 500 

//A quick write for a simple configuration file
extern int getConfig(appConfig *config){
    size_t lineNr = 0;
    FILE *fp;
    fp = fopen(CONFIGFILE, "r");

    if(fp != NULL){
        while(!feof(fp)){
            lineNr++;
            char sKey[MAXLEN];
            char sVal[MAXLEN];

            fscanf(fp, "%s %99[^\n]\n", &sKey[0], sVal);

            size_t keyLen = strlen(sKey) + 1;
            size_t valLen = strlen(sVal) + 1;
            if(keyLen > MAXLEN || valLen > MAXLEN){
               return 0;
            }
            
            if(bcmp(&sKey[0], &"sentence1", 9) == 0){
               memcpy(config->sentence1, &sVal, valLen);
            }
            
            if(bcmp(&sKey[0], &"serverName", 10) == 0){
               memcpy(config->serverName, &sVal, valLen);
            }
            if(bcmp(&sKey[0], &"serverPort", 10) == 0){
               config->serverPort =(int)strtol(sVal, (char **)NULL, 10);
            }
            if(bcmp(&sKey[0], &"sendIntervalSecs", 16) == 0){
               config->sendIntervalSecs =(int)strtol(sVal, (char **)NULL, 10);
            }
            if(bcmp(&sKey[0], &"gpsDeviceName", 13) == 0){
               memcpy(config->gpsDeviceName, &sVal, valLen);
            }
            if(bcmp(&sKey[0], &"gpsDeviceNmeaProtocol", 21) == 0){
               memcpy(config->gpsDeviceNmeaProtocol, &sVal, valLen);
            }
            if(bcmp(&sKey[0], &"imei", 4) == 0){
               config->imei = (long long int)strtoll(sVal, (char **)NULL, 10);
            }
            if(bcmp(&sKey[0], &"adminEmail", 10) == 0){
               memcpy(config->adminEmail, &sVal, valLen);
            }
        }
    }else{
        //Pocess error
        return 0;
    }
    return 1;
}
