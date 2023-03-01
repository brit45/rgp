#include "Logger.hpp"

Logger::Logger() {}

Logger::~Logger() {}

void Logger::setPath(std::string path) {

    this->path_log = path;
}

void Logger::Error(std::string key, std::string message) {

    std::string msg = "[ ERROR | " + key + " ]\t " + message;

    this->Save(msg);
}

void Logger::Info(std::string key, std::string message) {

    std::string msg = "[ INFO | " + key + " ]\t " + message;

    this->Save(msg);
}

void Logger::Debug(std::string key, std::string message) {

    std::string msg = "[ DEBUG | " + key + " ]\t " + message;

    this->Save(msg);
    
}

void Logger::Save(std::string message) {

    this->ofs.open(this->path_log, std::ios::app);
    this->ofs << message << std::endl;
    this->ofs.close();
}