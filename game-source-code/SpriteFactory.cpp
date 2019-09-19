#include <SpriteFactory.h>

void SpriteFactory::setInitialSizes(const vec_of_two_floats &sizes, vec_of_sprite_ptrs & sprites)
{
	float x_size;
	float y_size;

	std::tie(x_size, y_size) = sizes.at(0);
	sprites.at(0)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(0)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	sprites.at(1)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(1)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	sprites.at(1)->setRotation(180.0f);

	std::tie(x_size, y_size) = sizes.at(1);
	sprites.at(2)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(2)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	sprites.at(3)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(3)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	sprites.at(3)->setRotation(180.0f);

	std::tie(x_size, y_size) = sizes.at(2);
	sprites.at(4)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(4)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	sprites.at(5)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(5)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	sprites.at(5)->setRotation(180.0f);

	sprites.at(6)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(6)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	sprites.at(7)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(7)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	sprites.at(7)->setRotation(180.0f);

	std::tie(x_size, y_size) = sizes.at(3);
	sprites.at(8)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(8)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	sprites.at(9)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(9)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
}
void SpriteFactory::applyTextures(vec_of_sprite_ptrs & sprites)
{
	for(auto i=0u; i<sprites.size(); i++)
		sprites.at(i)->setTexture(&(*(textures_.getTextures().at(i))));
}
