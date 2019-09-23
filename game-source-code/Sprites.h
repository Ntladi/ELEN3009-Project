#ifndef SPRITES_H_
#define SPRITES_H_
#include <SFML/Graphics.hpp>
#include <tuple>
#include <memory>
#include <map>
#include "Textures.h"
#include "ObjectType.h"
#include "Orientation.h"
#include "SpriteFactory.h"
#include "MapKeys.h"
using two_floats = std::tuple<float,float>;
using sprite_ptr = std::shared_ptr<sf::RectangleShape>;
using map_of_sprite_ptrs = std::map<MapKeys, sprite_ptr>;
using map_of_two_floats = std::map<ObjectType,two_floats>;

class Sprites
{
public:
	Sprites();
	void displaySprite(const ObjectType &object, const Orientation &orientation,
			const two_floats &positions);
	void drawLatestObject(std::shared_ptr<sf::RenderWindow> &window);
	void setInitialSizes(const map_of_two_floats &sizes);

private:
	map_of_sprite_ptrs sprites_;
	sprite_ptr latestObject_;
	SpriteFactory sprite_factory_;
	void moveSpriteObject(MapKeys upKey, MapKeys downKey,
			const Orientation &orientation, const two_floats &position);
	void initializeSprite(MapKeys key);
};

#endif
