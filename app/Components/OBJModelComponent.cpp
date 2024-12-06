#include "OBJModelComponent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <SFML/Graphics/Image.hpp>

OBJModelComponent::OBJModelComponent() : vao(0), vbo(0), ebo(0), nbo(0), tbo(0) {}

OBJModelComponent::~OBJModelComponent()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &nbo);
    glDeleteBuffers(1, &tbo);
}

void OBJModelComponent::setupBuffers()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glGenBuffers(1, &nbo);
    glGenBuffers(1, &tbo);

    glBindVertexArray(vao);

    // Buffers des sommets
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Buffers des normales
    glBindBuffer(GL_ARRAY_BUFFER, nbo);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);

    // Buffers des coordonnées de texture
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(float), texCoords.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(2);

    // Buffers des indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);
}

GLuint OBJModelComponent::loadTexture(const std::string &texturePath)
{
    sf::Image image;
    if (!image.loadFromFile(texturePath))
    {
        std::cerr << "Error: Failed to load texture: " << texturePath << std::endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}

bool OBJModelComponent::loadMTL(const std::string &mtlPath, const std::string &objDirectory)
{
    std::ifstream mtlFile(mtlPath);
    if (!mtlFile.is_open())
    {
        std::cerr << "Error: Could not open MTL file: " << mtlPath << std::endl;
        return false;
    }

    std::string line, currentMaterial;
    while (std::getline(mtlFile, line))
    {
        std::istringstream ss(line);
        std::string prefix;
        ss >> prefix;

        if (prefix == "newmtl")
        {
            ss >> currentMaterial;
            materials[currentMaterial] = Material();
            materials[currentMaterial].name = currentMaterial;
        }
        else if (prefix == "Kd")
        {
            ss >> materials[currentMaterial].diffuse.x >> materials[currentMaterial].diffuse.y >> materials[currentMaterial].diffuse.z;
        }
        else if (prefix == "map_Kd")
        {
            std::string textureFile;
            ss >> textureFile;
            std::string texturePath = objDirectory + "/" + textureFile;
            materials[currentMaterial].textureID = loadTexture(texturePath);
        }
    }

    return true;
}

bool OBJModelComponent::loadFromFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open OBJ file: " << filePath << std::endl;
        return false;
    }

    std::string line, objDirectory = filePath.substr(0, filePath.find_last_of("/\\"));
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string prefix;
        ss >> prefix;

        if (prefix == "v")
        {
            float x, y, z;
            ss >> x >> y >> z;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
        else if (prefix == "vn")
        {
            float nx, ny, nz;
            ss >> nx >> ny >> nz;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);
        }
        else if (prefix == "vt")
        {
            float u, v;
            ss >> u >> v;
            texCoords.push_back(u);
            texCoords.push_back(v);
        }
        else if (prefix == "f")
        {
            unsigned int v, t, n;
            char dummy;
            for (int i = 0; i < 3; ++i)
            {
                ss >> v >> dummy >> t >> dummy >> n;
                indices.push_back(v - 1);
            }
        }
        else if (prefix == "mtllib")
        {
            std::string mtlFile;
            ss >> mtlFile;
            loadMTL(objDirectory + "/" + mtlFile, objDirectory);
        }
    }

    setupBuffers();
    return true;
}

void OBJModelComponent::render() const
{
    glBindVertexArray(vao);
    if (materials.find(currentMaterial) != materials.end())
    {
        glBindTexture(GL_TEXTURE_2D, materials.at(currentMaterial).textureID);
    }
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
