#ifndef __RESSOURCE_LOGGER_HPP__
#define __RESSOURCE_LOGGER_HPP__

#include <iostream>
#include <fstream>
#include <string>

class Logger {

    public:

        Logger();
        ~Logger();
        
        void setPath(std::string path);
        void Error(std::string key, std::string message);
        void Info(std::string key, std::string message);
        void Debug(std::string key, std::string message);

    private:

        void Save(std::string message);

        std::string path_log;
        std::ofstream ofs;

};

#endif //! __RESSOURCE_LOGGER_HPP__