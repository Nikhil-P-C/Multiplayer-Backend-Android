#include <iostream>
#include <enet/enet.h>
#include "packets.h"


int main()
{
    if (enet_initialize() != 0)
    {
        std::cerr << "ENet init failed\n";
        return 1;
    }

    atexit(enet_deinitialize);

    ENetAddress address;
    address.host = ENET_HOST_ANY; // listen on all interfaces
    address.port = 7777;

    ENetHost* server = enet_host_create(
        &address,
        32,     // max clients
        2,      // channels
        0,      // incoming bandwidth
        0       // outgoing bandwidth
    );

    if (!server)
    {
        std::cerr << "Server creation failed\n";
        return 1;
    }

    std::cout << "Server started on port 7777\n";

    ENetEvent event;
    while (true)
    {   std::cout<<"waiting for events...\n"; 
        while (enet_host_service(server, &event, 1000) > 0)
        {    
            switch (event.type)
            {
                case ENET_EVENT_TYPE_CONNECT:
                    std::cout << "Client connected from "
                              << (event.peer->address.host & 0xFF) << "."
                              << ((event.peer->address.host >> 8) & 0xFF) << "."
                              << ((event.peer->address.host >> 16) & 0xFF) << "."
                              << ((event.peer->address.host >> 24) & 0xFF) << ":"
                              << event.peer->address.port << "\n";
                    break;

                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "Packet received on channel " << event.channelID
                              << " with data length " << event.packet->dataLength << "\n";
                    enet_packet_destroy(event.packet);
                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "Client disconnected\n";
                    break;

                default:
                    break;
            }
            
        }
    }
    std::cout<<sizeof(PlayerBuffer)<<"\n";
    std::cout<<sizeof(platformBuffer)<<"\n";
    enet_host_destroy(server);
}

