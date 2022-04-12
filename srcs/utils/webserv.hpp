//
// Created by Kester kas De rooij on 4/6/22.
//

#ifndef WEBSERV_WEBSERV_HPP
#define WEBSERV_WEBSERV_HPP

#include "dataStructs.hpp"
#include "../server/server.hpp"
#include "../http/HTTPResponseMessage.hpp"

namespace webserv{
    void disconnected( int fd, int &nbr_conn );
    void kqueueFailure( int fd );
    int findRequestedLocation( webserv::httpData *config, std::vector<std::string> path );
    void takeRequest( webserv::serverData &serverData, int current_fd, int bytesread );
    void processEvent( webserv::serverData &serverData, struct kevent &event );
    void registerResponse( webserv::serverData &serverData, int current_fd, HTTPResponseMessage response );

}

#endif //WEBSERV_WEBSERV_HPP
