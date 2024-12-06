#ifndef OBJMODELCOMPONENT_HPP
#define OBJMODELCOMPONENT_HPP

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

// Structure de données pour stocker un matériau
struct Material
{
    std::string name;
    sf::Vector3f ambient;    // Couleur ambiante
    sf::Vector3f diffuse;    // Couleur diffuse
    sf::Vector3f specular;   // Couleur spéculaire
    float shininess;         // Brillance
    std::string texturePath; // Chemin de la texture diffuse
    GLuint textureID;        // ID de texture OpenGL
};

class OBJModelComponent
{
private:
    std::vector<float> vertices;       // Sommets (x, y, z)
    std::vector<float> normals;        // Normales (nx, ny, nz)
    std::vector<float> texCoords;      // Coordonnées de texture (u, v)
    std::vector<unsigned int> indices; // Indices pour le rendu

    std::map<std::string, Material> materials; // Matériaux par nom
    std::string currentMaterial;               // Matériau actuel pour les faces

    GLuint vao, vbo, ebo, nbo, tbo; // Buffers OpenGL pour les sommets, normales, textures

    void setupBuffers();
    bool loadMTL(const std::string &mtlPath, const std::string &objDirectory);
    GLuint loadTexture(const std::string &texturePath);

public:
    OBJModelComponent();
    ~OBJModelComponent();

    bool loadFromFile(const std::string &filePath);
    void render() const;
};

#endif
