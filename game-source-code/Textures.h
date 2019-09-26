#ifndef TEXTURES_H_
#define TEXTURES_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include "MapKeys.h"
using texture_ptr = std::shared_ptr<sf::Texture>;
using map_of_texture_ptrs = std::map<MapKeys,texture_ptr>;

/** \class Textures
 * \brief This class is a data class composed within the SpriteFactory
 * class. It manages the textures that are applied to the Sprites. The
 * Texture objects are managed by the SFML library.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Textures
{
public:
	/** \brief Default Texture constructor. Initializes the texture map
	 */
	Textures();
	/** \brief This method returns a map containing pointers to the sf::Texture
	 * objects. The map uses values from the MapKeys enumeration as keys.
	 * \return std::map<MapKeys,std::shared_ptr<sf::Texture>>;
	 */
	map_of_texture_ptrs getTextureMap();
private:
	map_of_texture_ptrs textures_;
	/** \brief This method receives an enumeration of type MapKeys, as well as
	 * a string which describes the path to the texture that must be loaded. It uses
	 * these parameters as key value pairs to initialize a shared sf::Texture pointer
	 * which is stored in the map member variable.
	 * \param key of type MapKeys
	 * \param fileString of type std::string
	 */
	void initializeTexture(MapKeys key, std::string fileString);

};

#endif
