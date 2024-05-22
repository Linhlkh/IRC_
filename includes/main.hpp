/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le <le@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 05:29:16 by khle              #+#    #+#             */
/*   Updated: 2024/04/01 05:23:35 by le               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define INVALID_PORT "Port number must be between 1024 and 65535"


// # include "Command.hpp"
// # include "Server.hpp"

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <map>
# include <algorithm>
# include <sys/socket.h>
# include <poll.h>
