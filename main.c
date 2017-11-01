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

    return 0;
}
