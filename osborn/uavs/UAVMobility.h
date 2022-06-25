//
// Copyright (C) 2005 Georg Lutz, Institut fuer Telematik, University of Karlsruhe
// Copyright (C) 2005 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __MYSTERIO_UAVMOBILITY_H
#define __MYSTERIO_UAVMOBILITY_H

#include "inet/common/INETDefs.h"
#include "inet/mobility/base/LineSegmentsMobilityBase.h"
#include "inet/power/base/EpEnergyStorageBase.h"
#include "inet/power/storage/SimpleEpEnergyStorage.h"
#include "../../src/utils/Coordinate.h"
#include "../../src/utils/UAV.h"

namespace inet {

/**
 * Random Waypoint mobility model. See NED file for more info.
 *
 * @author Georg Lutz (georglutz AT gmx DOT de), Institut fuer Telematik,
 *  Universitaet Karlsruhe, http://www.tm.uka.de, 2004-2005
 * @author Andras Varga (generalized, ported to LineSegmentsMobilityBase)
 */
class INET_API UAVMobility : public LineSegmentsMobilityBase
{
  protected:
    bool nextMoveIsWait;
    cPar *speedParameter = nullptr;
    cPar *waitTimeParameter = nullptr;
    bool hasWaitTime;
    int myStage = 0;

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    /** @brief Initializes mobility model parameters.*/
    virtual void initialize(int stage) override;

    /** @brief Overridden from LineSegmentsMobilityBase.*/
    virtual void setTargetPosition() override;

    Coord castCoordinateToCoord(Coordinate co){
        Coord coor(co.getX(), co.getY(), co.getZ());
        return coor;
    }

    Coordinate castCoordToCoordinate(Coord co){
        Coordinate coor(co.getX(), co.getY(), co.getZ());
        return coor;
    }

    /** @brief Overridden from LineSegmentsMobilityBase.*/
    virtual void move() override;

    void rescueDataAndStoreVariables();

    void executeTask(int j);
    Coord splittedGoTo(int j);
    void ativarUAV(int idUAV);
    void inativarUAV(int idUAV);
    void stop();

    J pegarBateria(int idUAV);

    UAV uav;
    bool continuoustask = false;
    int UAVRole = ROLE_DISABLED;

    //0 para uav desativado
    //1 para uav sem funcao
    //2 para uav subordinado
    //3 para uav leader

    //campo
    int height = 20;
    int radius = 50;
  public:
    const int MODULE_ID = 2;
    UAVMobility();
    virtual double getMaxSpeed() const override;

    enum ROLES{
        ROLE_DISABLED = 0,
        ROLE_SLAVE = 2,
        ROLE_LEADER = 3
    };

private:
    void initStoppedUAVs();
    void initAuxiliarTasksVariables();
};

}

#endif
