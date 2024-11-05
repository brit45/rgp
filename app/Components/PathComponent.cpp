#include "PathComponent.hpp"

PathComponent::PathComponent(Logger *logger) {

    this->logger = logger;
}

PathComponent::~PathComponent() {

    this->path.clear();
    this->logger->Info("PATHS", "Delete all path of memory.");
}

void PathComponent::AddPath(uint key, std::string Path) {

    this->path[key].push_back(Path);

    this->logger->Info("PATHS", "Add path \""+Path+"\"");
}

std::string PathComponent::GetPath(uint key, uint pos) const {
    
    return this->path.at(key).at(pos);
}

uint PathComponent::GetSize(uint key) const
{
    return this->path.at(key).size();
}
