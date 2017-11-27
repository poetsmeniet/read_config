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
#define MAXLEN 500 

//A quick write for a simple configuration file
extern int getConfig(appConfig *config, char *filename){
    size_t lineNr = 0;
    FILE *fp;
    fp = fopen(filename, "r");

    if(fp != NULL){
        while(!feof(fp)){
            lineNr++;
            char sKey[MAXLEN];
            char sVal[MAXLEN];

            int rc = fscanf(fp, "%s %99[^\n]\n", &sKey[0], sVal);
            if(rc == 0){
                printf("\tError in '%s', line number %zu\n", filename, lineNr);
                return -1;
            }

            size_t keyLen = strlen(sKey) + 1;
            size_t valLen = strlen(sVal) + 1;
            if(keyLen > MAXLEN || valLen > MAXLEN){
               printf("\nSorry, maximum length of key value exceeded (%d)\n", MAXLEN);
               return 1;
            }
            
            if(bcmp(&sKey[0], &"serverName", 10) == 0){
               memcpy(config->serverName, &sVal, valLen);
            }
            if(bcmp(&sKey[0], &"serverPort", 10) == 0){
               config->serverPort =(int)strtol(sVal, (char **)NULL, 10);
            }
            if(bcmp(&sKey[0], &"nick", 4) == 0){
               memcpy(config->nick, &sVal, valLen);
               config->nick[valLen] = '\0';
            }
            if(bcmp(&sKey[0], &"userName", 8) == 0){
               memcpy(config->userName, &sVal, valLen);
               config->userName[valLen] = '\0';
            }
        }
    }else{
        //Pocess error
        return 1;
    }
    fclose(fp);
    return 0;
}
