/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le <le@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 05:29:19 by khle              #+#    #+#             */
/*   Updated: 2024/04/01 05:24:03 by le               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Syntax error: ./irc <port> <password>" << std::endl;
		return (0);
	}
	//signal handle
	try {
		Server irc(av[1], av[2]);
	}
	catch (const std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
}