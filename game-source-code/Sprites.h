
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

/** \class Sprites
 * \brief This class is a data layer class composed within the Presentation class.
 * it stores all the sprite objects that the Presentation class draws on the screen.
 * This class also encapsulates the SpriteFactory class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Sprites
{
public:
	/** \brief Default Sprites constructor. Initializes sprite map.
	 */
	Sprites();

	/** \brief This method receives two constant enumerations of type ObjectType and
	 * Orientation respectively. These act as keys in order to determine which
	 * object must be selected from the sprite map. In addition, this method also
	 * receives a tuple, whereby each element is of type float. The tuple contains
	 * coordinates of where a sprite object must be drawn.
	 * \param object of type Object
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float,float>;
	 */
	void displaySprite(const ObjectType &object, const Orientation &orientation,
			const two_floats &position);

	/** \brief This method receives a render window and draws the latest object
	 * that is mapped by the displaySprite() method.
	 * \param window of type std::shared_ptr<sf::RenderWindow>
	 */
	void drawLatestObject(std::shared_ptr<sf::RenderWindow> &window);

	/** \brief This method receives a constant map of the sizes that each
	 * sprite object must be initialized to and initializes each sprite
	 * object accordingly. This is done through the SpriteFactory class.
	 * \param sizes of type std::map<ObjectType, std::tuple<float,float> >;
	 */
	void setInitialSizes(const map_of_two_floats &sizes);

private:
	map_of_sprite_ptrs sprites_;
	sprite_ptr latestObject_;
	SpriteFactory sprite_factory_;

	/** \brief This method receives three constant enumerations. The first
	 * two are of type MapKeys, they represent the key values of the
	 * objects in the sprite map that are of the same object type but have
	 * different orientations. The third enumeration is of type orientation
	 * and it describes the orientation of the object that this method will
	 * move. In addition, the method also receives a tuple which describes
	 * the coordinates that the object will move to.
	 * \param upKey of type MapKeys
	 * \param downKey of type MapKeys
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float,float>
	 */
	void moveSpriteObject(const MapKeys upKey, const MapKeys downKey,
			const Orientation &orientation, const two_floats &position);

	/** \brief This method receives a constant enumeration of type MapKeys
	 * in order to add the appropriate object to the sprite map.
	 * \param key of type MapKeys
	 */
	void initializeSprite(const MapKeys key);
};

#endif
