#ifndef MYSTERIO_SRC_UTILS_CODES_H_
#define MYSTERIO_SRC_UTILS_CODES_H_

enum CodeMessage {
    //STATUS
    SOLICITAR_LOCALIZACAO = 10,
    SOLICITAR_VELOCIDADE,

    //UAV STATUS
    RESPONDER_LOCALIZACAO = 30,
    RESPONDER_VELOCIDADE
};

#endif
