#ifndef config_H_
#define config_H_

typedef struct applicationConfguration{
    char serverName[200];
    int serverPort;
    size_t sendIntervalSecs;
    char gpsDeviceName[100];
    char gpsDeviceNmeaProtocol[100];
    long long int imei;
    char adminEmail[50];
}appConfig;

int getConfig(appConfig *config);

#endif
