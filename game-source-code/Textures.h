#ifndef TEXTURES_H_
#define TEXTURES_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include "MapKeys.h"
using texture_ptr = std::shared_ptr<sf::Texture>;
using map_of_texture_ptrs = std::map<MapKeys,texture_ptr>;


class Textures
{
public:
	Textures();
	map_of_texture_ptrs getTextureMap();
private:
	map_of_texture_ptrs textures_;
	void initializeTexture(MapKeys key, std::string fileString);

};

#endif
