/****************************************************************************/
/// @file    TL_AdaptiveQueue.h
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
/// @date    August 2013
///
/****************************************************************************/
// VENTOS, Vehicular Network Open Simulator; see http:?
// Copyright (C) 2013-2015
/****************************************************************************/
//
// This file is part of VENTOS.
// VENTOS is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef TRAFFICLIGHTADAPTIVEQUEUE_H
#define TRAFFICLIGHTADAPTIVEQUEUE_H

#include <04_TL_Adaptive_RingAndBarrier.h>
#include <boost/graph/adjacency_list.hpp>


namespace VENTOS {

class TrafficLightAdaptiveQueue : public TrafficLightAdaptive
{
public:
    virtual ~TrafficLightAdaptiveQueue();
    virtual void finish();
    virtual void initialize(int);
    virtual void handleMessage(cMessage *);

protected:
    void virtual executeFirstTimeStep();
    void virtual executeEachTimeStep(bool);

private:
    void chooseNextInterval();
    void chooseNextGreenInterval();
    void getMovements();
    void generateAllAllowedMovements();

protected:
    int LINKSIZE;
    std::vector< std::vector<int> > allMovements;
    boost::filesystem::path movementsFilePath;
};

}

#endif
