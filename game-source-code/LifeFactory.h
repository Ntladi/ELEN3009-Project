#ifndef LIFEFACTORY_H_
#define LIFEFACTORY_H_
#include <PlayerLife.h>
#include <vector>
#include <memory>
using glyph_ptr = std::shared_ptr<PlayerLife>;
using vec_of_glyph_ptrs = std::vector<std::shared_ptr<PlayerLife>>;

/** \class LifeFactory
 * \brief This class manages the behavior of all player lives that appear
 * in the game. All PlayerLife objects are encapsulated within this class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class LifeFactory
{
public:
	/** \brief Parameterized LifeFactory constructor. It initializes all PlayerLife
	 * objects that appear on the screen.
	 * \param orientation of type Orientation
	 * \param lives of type int
	 */
	LifeFactory(Orientation orientation = Orientation::FACE_UP, const int &lives = 0);

	/** \brief This method returns a vector of PlayerLife shared_pointers that represent the number of lives
	 * that a currently player has.
	 * \return std::vector<std::shared_ptr<PlayerLife>>
	 */
	vec_of_glyph_ptrs getGlyphs() const;

	/** \brief This method determines the number of PlayerLife objects that appear on the screen based on the
	 * value passed in.
	 * \param i of type lives
	 */
	void manageLives(const int& i);
private:
	Orientation orientation_;
	vec_of_glyph_ptrs glyphs_;
	float lives_;

	/** This method generates a row of player life objects. The number of objects generated depends on how many lives
	 * are passed into the constructor
	 */
	void generateGlyphs();
};

#endif
