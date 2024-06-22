#include "../includes/Command.hpp"

//-----------default constructor

Command::Command() {}

Command::Command(Command const & copy) {
    *this = copy;
}

Command &Command::operator=(Command const & copy) {
    this->clients = copy.clients;
    this->users = copy.users;
    //...
    return (*this);
}

Command::~Command() {}

//-------------main func

void    Command::execute(std::vector<std::string> cmd, int i) {
    if (cmd[0] == "nick")
        nick(cmd, clients[i].fd);
    else if (cmd[0] == "join")
        join(cmd, clients[i].fd);
    else if (cmd[0] == "kick")
        kick(cmd, clients[i].fd);
    else if (cmd[0] == "invite")
        invite(cmd, clients[i].fd);
    else if (cmd[0] == "join")
        join(cmd, clients[i].fd);
    else if (cmd[0] == "privmsg")
        privmsg(cmd, clients[i].fd);
    //else if () .........

}

void    Command::nick(std::vector<std::string> cmd, int fd) {
	for (std::map<int, t_user>::iterator it = users.begin(); it != users.end(); it++)
	{
		if (it->second.nick == cmd[1])
		{
			//func send error for ERR_NICKNAMEINUSE 
			return ;
		}
	}
	std::string	msg = ":" + users[fd].nick + "!" + users[fd].user + "@localhost NICK " + cmd[1] + "\r\n";
	if (send(fd, msg.c_str(), msg.length(), 0) == ERROR)
		std::cerr << "Client  : Failed to send message\n";
	users[fd].nick = cmd[1];
}

void    Command::join(std::vector<std::string> cmd, int fd) {
    
}

