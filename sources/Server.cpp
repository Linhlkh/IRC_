/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le <le@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:15:06 by khle              #+#    #+#             */
/*   Updated: 2024/04/01 05:26:36 by le               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server() {}

Server::Server(Server const & copy) {
    *this = copy;
}

Server &Server::operator=(Server const & copy) {
    this->port = copy.port;
    this->password = copy.password;
    //

    
    return(*this);
}

Server::~Server() {
    //
}

Server::Server(std::string _port, std::string _pass) {
    setPort(_port);
    setPass(_pass);
    //execute
}

void	Server::setPort(std::string _port) {
    
    unsigned int len_port = _port.length();
    for (unsigned int i = 0; i < len_port; i++)
    {
        if (!isdigit(_port[i]))
            throw (std::invalid_argument(INVALID_PORT));
    }
    if (len_port != 4 && len_port != 5)
        throw (std::invalid_argument(INVALID_PORT));
    char *endptr;
    long port_nb = strtol(_port.c_str(), &endptr, 10);
    if ((*endptr) || port_nb < 1024 || port_nb > 65535)
        throw (std::invalid_argument(INVALID_PORT));
    this->port = static_cast<int>(port_nb);
}

void	Server::setPass(std::string _pass) {
    unsigned int len_pass = _pass.length();
    unsigned int x,y,z;
    x = 0;
    y = 0;
    z = 0;
    for (unsigned int i = 0; i < len_pass; i++)
    {
        if (std::isspace(_pass[i]))
            throw (std::invalid_argument("Password must not contain whitespace."));
        if (std::islower(_pass[i]))
            x++;
        if (std::isupper(_pass[i]))
            y++;
        if (std::isdigit(_pass[i]))
            z++;
    }
    if (len_pass < 8 || len_pass > 510)
        throw (std::invalid_argument("Invalid length password."));
    std::string msg("Password must contain at least ");
    if (!x)
        throw (std::invalid_argument(msg + "1 lowercase letter"));
    if (!y)
        throw (std::invalid_argument(msg + "1 uppercase letter"));
    if (!z)
        throw (std::invalid_argument(msg + "1 number"));
    this->password = _pass;
}

int		Server::getPort() const {
    return (this->port);
}

std::string		Server::getPass() const {
    return (this->password);
}

