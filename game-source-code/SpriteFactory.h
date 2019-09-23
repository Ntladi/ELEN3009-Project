#ifndef SPRITEFACTORY_H_
#define SPRITEFACTORY_H_
#include <SFML/Graphics.hpp>
#include <map>
#include "ObjectType.h"
#include "Textures.h"
using sprite_ptr = std::shared_ptr<sf::RectangleShape>;
using two_floats = std::tuple<float,float>;
using map_of_sprite_ptrs = std::map<MapKeys, sprite_ptr>;
using map_of_two_floats = std::map<ObjectType,two_floats>;

class SpriteFactory
{
public:
	void setInitialSizes(const map_of_two_floats &sizes, map_of_sprite_ptrs & sprites);
	void applyTextures(map_of_sprite_ptrs & sprites);
private:
	Textures textures_;
	void setSize(const map_of_two_floats &sizes, map_of_sprite_ptrs &sprites,
			MapKeys up_object, MapKeys down_object, ObjectType size_key, bool flip_down);
};

#endif
