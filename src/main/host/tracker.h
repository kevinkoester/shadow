/*
 * The Shadow Simulator
 * Copyright (c) 2010-2011, Rob Jansen
 * See LICENSE for licensing information
 */

#ifndef SHD_TRACKER_H_
#define SHD_TRACKER_H_

#include <glib.h>
#include <netinet/in.h>

#include "main/core/support/definitions.h"
#include "main/core/support/options.h"
#include "main/host/protocol.h"
#include "main/routing/packet.h"
#include "support/logger/log_level.h"

typedef struct _Tracker Tracker;

Tracker* tracker_new(SimulationTime interval, LogLevel loglevel, LogInfoFlags loginfo);
void tracker_free(Tracker* tracker);

void tracker_addProcessingTime(Tracker* tracker, SimulationTime processingTime);
void tracker_setProcessingTime(Tracker* tracker, SimulationTime processingTime);
void tracker_addVirtualProcessingDelay(Tracker* tracker, SimulationTime delay);
void tracker_addInputBytes(Tracker* tracker, Packet* packet, gint handle);
void tracker_addOutputBytes(Tracker* tracker, Packet* packet, gint handle);
void tracker_addAllocatedBytes(Tracker* tracker, gpointer location, gsize allocatedBytes);
void tracker_removeAllocatedBytes(Tracker* tracker, gpointer location);
void tracker_addSocket(Tracker* tracker, gint handle, ProtocolType type, gsize inputBufferSize, gsize outputBufferSize);
void tracker_updateSocketPeer(Tracker* tracker, gint handle, in_addr_t peerIP, in_port_t peerPort);
void tracker_updateSocketInputBuffer(Tracker* tracker, gint handle, gsize inputBufferLength, gsize inputBufferSize);
void tracker_updateSocketOutputBuffer(Tracker* tracker, gint handle, gsize outputBufferLength, gsize outputBufferSize);
void tracker_removeSocket(Tracker* tracker, gint handle);
void tracker_heartbeat(Tracker* tracker, gpointer userData);

#endif /* SHD_TRACKER_H_ */
