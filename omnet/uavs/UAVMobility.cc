#include "../uavs/UAVMobility.h"
#include "../mysterio/Example1Communication.h"
#include <iostream>

using namespace omnetpp;
using namespace std;
using namespace inet;

Coord position[10];
double velocidade[10];
float bateria[10];
double tempoVoo[10];

int UAVLeader = -1;
int UAVDestino = -1;

using namespace mysterio;

using namespace power;

Define_Module(UAVMobility);

    //Para contar o tempo, talvez adicionar no subscribe ou aqui no próprio uav
    //clock_t t;
    //t = clock();
    //t = clock() - t;
    //cout << ((double)t)/((CLOCKS_PER_SEC/1000)) << endl;

UAVMobility::UAVMobility(){ nextMoveIsWait = false; }

void UAVMobility::initialize(int stage) {
    LineSegmentsMobilityBase::initialize(stage);
    selfID = getParentModule()->getIndex();

    if (stage == INITSTAGE_LOCAL) {
        waitTimeParameter = &par("waitTime");
        hasWaitTime = waitTimeParameter->isExpression() || waitTimeParameter->doubleValue() != 0;
        speedParameter = &par("speed");
        velocidade[selfID] = par("speed").operator double();
        //velocidade1[selfID] = speedParameter;
        stationary = !speedParameter->isExpression() && speedParameter->doubleValue() == 0;
    }
    this->setData();
}

void UAVMobility::setTargetPosition() {
    if (nextMoveIsWait) {
        simtime_t waitTime = waitTimeParameter->doubleValue();
        nextChange = simTime() + waitTime;
        nextMoveIsWait = false;
    } else {
        targetPosition = getRandomPosition();
        double speed = speedParameter->doubleValue();
        double distance = lastPosition.distance(targetPosition);
        simtime_t travelTime = distance / speed;
        nextChange = simTime() + travelTime;
        nextMoveIsWait = hasWaitTime;
    }
    this->setData();
}

void UAVMobility::move() {
    LineSegmentsMobilityBase::move();
    raiseErrorIfOutside();
    this->setData();
}

double UAVMobility::getMaxSpeed() const {
    return speedParameter->isExpression() ? NaN : speedParameter->doubleValue();
}

J UAVMobility::pegarBateria(int idUAV){ //Retirar daqui e passar para o Mobility
    cModule *a = getParentModule()->getParentModule()->getSubmodule("host", idUAV)->getSubmodule("energyStorage", 0);
    SimpleEpEnergyStorage *energySto = check_and_cast<SimpleEpEnergyStorage*>(a);
    return energySto->getNominalEnergyCapacity();
}

void UAVMobility::setData(){
    position[selfID] = lastPosition;
    velocidade[selfID] = speedParameter->doubleValue();
    bateria[selfID] = std::stof(pegarBateria(selfID).str());
    tempoVoo[selfID] = simTime().dbl();
}
