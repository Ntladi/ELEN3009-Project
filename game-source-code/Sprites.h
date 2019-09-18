#ifndef SPRITES_H_
#define SPRITES_H_
#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
#include <memory>
#include "Textures.h"
#include "ObjectType.h"
#include "Orientation.h"
#include "SpriteFactory.h"
using two_floats = std::tuple<float,float>;
using vec_of_two_floats = std::vector<two_floats>;
using sprite_ptr = std::shared_ptr<sf::RectangleShape>;
using vec_of_sprite_ptrs = std::vector<sprite_ptr>;

class Sprites
{
public:
	Sprites();
	void moveSprite(const ObjectType &object, const Orientation &orientation,
			const two_floats &positions);
	void drawLatestObject(std::shared_ptr<sf::RenderWindow> &window);
	void setInitialSizes(const vec_of_two_floats &sizes);

private:
	sprite_ptr upPlayer_;
	sprite_ptr downPlayer_;
	sprite_ptr upAlien_;
	sprite_ptr downAlien_;
	sprite_ptr upPlayerBullet_;
	sprite_ptr downPlayerBullet_;
	sprite_ptr upAlienBullet_;
	sprite_ptr downAlienBullet_;
	sprite_ptr latestObject_;
	SpriteFactory sprite_factory_;
	vec_of_sprite_ptrs getSprites();
	void setLatestObject(const ObjectType &object, const Orientation &orientation);
	void setInitialPositions(const vec_of_two_floats &positions);
	void moveSpriteObject(sprite_ptr & upSprite, sprite_ptr & downSprite, const Orientation &orientation, const two_floats &position);
};

#endif
