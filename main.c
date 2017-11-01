#include <stdio.h>
#include <unistd.h>
#include "config.h"
#define LOGFILE "/tmp/logile.log"

int main(void){
    //Define configuration struct 
    appConfig config;

    //Populate configuration
    if(!getConfig(&config)) //log to logger, but continue
        printf("Error in config, not loading changes"); 

    printf("serverName: %s\n", config.serverName);
    printf("Sentence1 (with whitespaces): %s\n", config.sentence1);

    return 0;
}
