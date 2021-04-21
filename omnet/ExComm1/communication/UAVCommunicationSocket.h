#ifndef MYSTERIO_OMNET_EXCOMM1_COMMUNICATION_UAVCOMMUNICATIONSOCKET_H_
#define MYSTERIO_OMNET_EXCOMM1_COMMUNICATION_UAVCOMMUNICATIONSOCKET_H_

#include "../../../src/communication/UAVCommunication.h"
#include "../../../src/utils/Message.h"

namespace mysterio {

class UAVCommunicationSocket : public UAVCommunication {
public:
    UAVCommunicationSocket(); //Aqqui ele cria a conexão com o Communication
    virtual ~UAVCommunicationSocket();
    void dispatchMessage(Message msg);   //Aqui ele envia mensagem pro Communication
    int conexao();
    void connectBase();
    int getSocketCode();
    void disconnectBase();

//private:
    bool connected = false;
    int socketCode = -1;
};

}

#endif
