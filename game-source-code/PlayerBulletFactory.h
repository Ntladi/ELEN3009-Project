#ifndef PLAYERBULLETFACTORY_H_
#define PLAYERBULLETFACTORY_H_
#include <Orientation.h>
#include <vector>
#include <memory>
#include <algorithm>
#include "Bullet.h"
#include "PiercerBullet.h"
#include "RightDiagonalBullet.h"
#include "LeftDiagonalBullet.h"
#include "StopWatch.h"
using bullet_ptr = std::shared_ptr<Bullet>;
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<bullet_ptr>;

/** \class PlayerBulletFactory
 * \brief This class is a data layer class that manages the shots
 * fired by objects from the Player class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class PlayerBulletFactory
{
public:
	/** \brief Default PlayerBulletFactory constructor. It initializes
	 * the stop-watch that counts the time needed before a power-up is achieved.
	 */
	PlayerBulletFactory();

	/** \brief This method receives a constant enumeration of type Orientation,
	 * which determines the movement direction of the bullet object that the method
	 * will generate. In addition, it also receives a constant tuple of floats, which describe
	 * the initial position of the bullet that will be generated.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>
	 */
	void shoot(const Orientation orientation,const two_floats position);

	/** \brief This method returns the member vector of Bullet shared pointers that have
	 * not been destroyed.
	 * \return std::vector<std::shared_ptr<Bullet>>
	 */
	vec_of_bullets getShotsFired();

	/** \brief This method resets the stop-watch that counts the time needed before a
	 * power-up is achieved.
	 */
	void resetFactory();
private:
	vec_of_bullets bulletsFired_;
	StopWatch stopwatch_;

	/** \brief This method removes destroyed bullet objects from the member vector of Bullet shared
	 * pointers.
	 */
	void removeWaste();

	/** \brief This method receives the constant enumeration and tuple of floats from the shoot() method and generates a
	 * standard bullet.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>
	 */
	void makeStandardBullet(const Orientation orientation, const two_floats position);

	/** \brief This method receives the constant enumeration and tuple of floats from the shoot() method and generates a
	 * several PiercerBullet objects. This method models the second power up.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>
	 */
	void makeMultiShotPiercer(const Orientation orientation, const two_floats position);

	/** \brief This method receives the constant enumeration and tuple of floats from the makeMultiShotPiercer() method
	 * and generates a PiercerBullet object.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>
	 */
	void makePiercerBullet(const Orientation orientation, const two_floats position);

	/** \brief This method receives the constant enumeration and tuple of floats from the shoot() method and generates a
	 * a LeftDiagonalBullet object, as well a RightDiagonalBullet object. This method models the first power up.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>
	 */
	void makeMultiShotBullets(const Orientation orientation, const two_floats position);
};

#endif
