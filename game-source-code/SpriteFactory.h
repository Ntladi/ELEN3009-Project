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

/** \class SpriteFactory
 * \brief This class is a presentation class that facilitates communication
 * between the Sprites class and the Textures class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class SpriteFactory
{
public:
	/** \brief This method receives a constant map containing game object sizes, as well as a map
	 * containing sf::RectangleShape shared pointers. It then applies the appropriate size to the
	 * appropriate sf::RectangleShape object.
	 * \param sizes of std::map<ObjectType, std::tuple<float,float> >
	 * \param sprites of type std::map<MapKeys, std::shared_ptr<sf::RectangleShape> >
	 */
	void setInitialSizes(const map_of_two_floats &sizes, map_of_sprite_ptrs & sprites);

	/** \brief This method receives a constant map containing sf::RectangleShape pointers. It then applies
	 * the appropriate texture to the appropriate object.
	 * \param sprites of type std::map<MapKeys, std::shared_ptr<sf::RectangleShape> >
	 */
	void applyTextures(map_of_sprite_ptrs & sprites);
private:
	Textures textures_;

	/** \brief This method receives a constant map containing game object sizes, as well as a map
	 * containing sf::RectangleShape shared pointers. In addition, it also receives three
	 * constant enumerations, two of which are of type MapKeys that describe the two objects onto which sizes will be applied.
	 * The third enumeration is of type ObjectType, which is the key of the size to be applied.
	 * Moreover it also receives a constant boolean, which is set to true if a rotation must take place.
	 * This method is called by the setInitialSizes() method in order to set the size of each individual
	 * sf::RectangleShape object while also taking orientation into account. It rotates the sprite by 180
	 * degrees if the constant boolean allows it.
	 * \param sizes of std::map<ObjectType, std::tuple<float,float> >
	 * \param sprites of type std::map<MapKeys, std::shared_ptr<sf::RectangleShape> >
	 * \param up_object of type MapKeys
	 * \param down_object of type MapKeys
	 * \param size_key of type ObjectType
	 * \param flip_down of type bool
	 *
	 */
	void setSize(const map_of_two_floats &sizes, map_of_sprite_ptrs &sprites,
			const MapKeys up_object, const MapKeys down_object, const ObjectType size_key,const bool flip_down);
};

#endif
