#ifndef __COMPONENT_PATH_HPP__
#define __COMPONENT_PATH_HPP__

#include "Component.inl"


class PathComponent {

    public:

        PathComponent(Logger *logger);
        
        virtual ~PathComponent();

        void AddPath(uint key, std::string Path);

        std::string GetPath(uint key, uint pos = 0) const;

        uint GetSize(uint key) const;

    private:

        std::map<uint,std::vector<std::string>> path;
        
        Logger *logger;
};

#endif //!__COMPONENT_PATH_HPP__