//
// Generated file, do not edit! Created by nedtool 5.4 from mysterio/omnet/uavs/DroneMessage.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __DRONEMESSAGE_M_H
#define __DRONEMESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif



class DroneMessage;
// cplusplus {{
#include "../../src/status/UAVStatus.h"
#include "../../src/mission/Task.h"
#include <string>
// }}

/**
 * Class generated from <tt>mysterio/omnet/uavs/DroneMessage.msg:15</tt> by nedtool.
 * <pre>
 * message DroneMessage extends cMessage
 * {
 *     int origem = -1;
 *     int destino = -1;
 *     DroneStatus status;
 *     Task task;
 *     string titulo;
 * }
 * </pre>
 */
class INET_API DroneMessage : public ::omnetpp::cMessage
{
  protected:
    int origem = -1;
    int destino = -1;
    UAVStatus status;
    Task task;
    omnetpp::opp_string titulo;

  private:
    void copy(const DroneMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DroneMessage&);

  public:
    DroneMessage(const char *name=nullptr, short kind=0);
    DroneMessage(const DroneMessage& other);
    virtual ~DroneMessage();
    DroneMessage& operator=(const DroneMessage& other);
    virtual DroneMessage *dup() const override {return new DroneMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getOrigem() const;
    virtual void setOrigem(int origem);
    virtual int getDestino() const;
    virtual void setDestino(int destino);
    virtual const UAVStatus& getStatus() const;
    virtual UAVStatus& getStatusForUpdate() { return const_cast<UAVStatus&>(const_cast<DroneMessage*>(this)->getStatus());}
    virtual void setStatus(const UAVStatus& status);
    virtual const Task& getTask() const;
    virtual Task& getTaskForUpdate() { return const_cast<Task&>(const_cast<DroneMessage*>(this)->getTask());}
    virtual void setTask(const Task& task);
    virtual const char * getTitulo() const;
    virtual void setTitulo(const char * titulo);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DroneMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DroneMessage& obj) {obj.parsimUnpack(b);}

#endif // ifndef __DRONEMESSAGE_M_H

