#ifndef MYSTERIO_OCTOPUS_SCENARIOS_MYSTERIOCOMMANDER_H_
#define MYSTERIO_OCTOPUS_SCENARIOS_MYSTERIOCOMMANDER_H_
#include "../communication/MysCommunication.h"
#include "../status/MysStatusManager.h"

class MysterioCommander {
public:
    MysterioCommander(){}
    virtual ~MysterioCommander(){}
    MysCommunication conn;
    MysStatusManager* status;
};

#endif
