#ifndef TEXTURES_H_
#define TEXTURES_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
using texture_ptr = std::shared_ptr<sf::Texture>;
using vec_of_texture_ptrs = std::vector<texture_ptr>;


class Textures
{
public:
	Textures();
	vec_of_texture_ptrs getTextures();
private:
	texture_ptr upPlayer_texture_;
	texture_ptr downPlayer_texture_;
	texture_ptr upAlien_texture_;
	texture_ptr downAlien_texture_;
	texture_ptr upPlayer_bullet_texture_;
	texture_ptr downPlayer_bullet_texture_;
	texture_ptr upAlien_bullet_texture_;
	texture_ptr downAlien_bullet_texture_;

};

#endif
