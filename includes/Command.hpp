
#pragma once

typedef struct s_user
{
    int             fd;
    std::string     user;
    std::string     nick;
    std::string     host;
}   t_user;

class Command
{
    protected:
        std::vector<pollfd>     clients; //pollfd after check password
        std::map<int, t_user>   users; //int = fd, t_user = infos user
        //channels waiting for set up

    public:
		Command();
		Command(Command const & copy);
		Command & operator=(Command const & copy);
		~Command();

        void    execute(std::vector<std::string> cmd, int i); //main func

        //func send common error
        void    nick(std::vector<std::string> cmd, int fd);
        void    join(std::vector<std::string> cmd, int fd);
        void    privmsg(std::vector<std::string> cmd, int fd);
        void    kick(std::vector<std::string> cmd, int fd);
        void    invite(std::vector<std::string> cmd, int fd);
        //mode
        //oper
        //topic
        //......


}
