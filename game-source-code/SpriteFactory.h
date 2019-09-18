#ifndef SPRITEFACTORY_H_
#define SPRITEFACTORY_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include "Textures.h"
using sprite_ptr = std::shared_ptr<sf::RectangleShape>;
using vec_of_sprite_ptrs = std::vector<sprite_ptr>;
using two_floats = std::tuple<float,float>;
using vec_of_two_floats = std::vector<two_floats>;

class SpriteFactory
{
public:
	void setInitialSizes(const vec_of_two_floats &sizes, vec_of_sprite_ptrs & sprites);
	void applyTextures(vec_of_sprite_ptrs & sprites);
private:
	Textures textures_;
};

#endif
