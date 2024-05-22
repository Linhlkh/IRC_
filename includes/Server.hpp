/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 05:52:08 by khle              #+#    #+#             */
/*   Updated: 2024/03/21 06:14:51 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Server
{
	private:
		int				port;
		std::string		password;
		

	public:
		Server();
		Server(Server const & copy);
		Server & operator=(Server const & copy);
		~Server();

		Server(std::string _port, std::string _pass);
		
		void			setPort(std::string _port);
		void			setPass(std::string _pass);

		int				getPort() const;
		std::string		getPass() const;	
	
}