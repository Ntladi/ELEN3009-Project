#ifndef SPRITES_H_
#define SPRITES_H_
#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
#include <memory>
#include "Textures.h"
#include "ObjectType.h"
#include "Orientation.h"
using two_floats = std::tuple<float,float>;
using vec_of_two_floats = std::vector<two_floats>;
using sprite_ptr = sf::RectangleShape*;
using vec_of_sprite_ptrs = std::vector<sprite_ptr>;

class Sprites
{
public:
	Sprites();
	void movePlayer(const Orientation &orientation, const two_floats &position);
	void moveAlien(const Orientation &orientation, const two_floats &position);
	void movePlayerBullet(const Orientation &orientation, const two_floats &position);
	void moveAlienBullet(const Orientation &orientation, const two_floats &position);
	void drawLatestObject(std::shared_ptr<sf::RenderWindow> &window);
	void setInitialSizes(const vec_of_two_floats &sizes);

private:
	sf::RectangleShape upPlayer_;
	sf::RectangleShape downPlayer_;
	sf::RectangleShape upAlien_;
	sf::RectangleShape downAlien_;
	sf::RectangleShape upPlayerBullet_;
	sf::RectangleShape downPlayerBullet_;
	sf::RectangleShape upAlienBullet_;
	sf::RectangleShape downAlienBullet_;
	sf::RectangleShape latestObject_;
	Textures textures_;
	void setLatestObject(const ObjectType &object, const Orientation &orientation);
	void setInitialPositions(const vec_of_two_floats &positions);
	void applyTextures();
};

#endif
