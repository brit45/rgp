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

std::string Logger::GetPath() const {
    return this->path_log;
}

void Logger::Save(std::string message) {

    char buffer[256];
    time_t timestamp = time(NULL);

    strftime(buffer, sizeof(buffer), "%d/%m/%Y - %H:%M:%S", localtime(&timestamp));

    this->ofs.open(this->path_log, std::ios::app);
    this->ofs << buffer << "\t\t" << message << std::endl;
    this->ofs.close();
}