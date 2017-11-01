#include <stdio.h>
#include <unistd.h>
#include "config.h"
#define LOGFILE "/tmp/logile.log"
#define CONFIG_FILENAME "config.txt"

int main(void){
    //Define configuration struct 
    appConfig config;

    //Populate configuration
    if(getConfig(&config, CONFIG_FILENAME)){
        printf("Error in config\n"); 
        return 1;
    }

    printf("serverName: %s\n", config.serverName);
    printf("Sentence1 (with whitespaces): %s\n", config.sentence1);

    return 0;
}
