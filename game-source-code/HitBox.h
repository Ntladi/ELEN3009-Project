
#ifndef HITBOX_H_
#define HITBOX_H_
#include <tuple>
#include <vector>
using two_floats = std::tuple<float, float>;

/** \class HitBox
 * \brief This class is a data layer class that models
 * the space that of all objects inherited from the IEntity class occupies.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class HitBox {
public:
	/** \brief Parameterized Movement constructor. Initializes member variables
	 * to those that are passed in. The constutor's parameters have default values
	 * to avoid the need for a default constructor.
	 * \param position of type std::tuple<float, float>
	 * \param size of type std::tuple<float, float>
	 */
	HitBox(two_floats position = {}, two_floats size = {});

	/** \brief This method receives two constant floats and uses them to calculate
	 * the positions of all relevant positions contained within the Hitbox.
	 * \param position of type std::tuple<float, float>
	 * \param size of type std::tuple<float, float>
	 */
	void setNewPositions(const two_floats position,const two_floats size);


	std::vector<two_floats> getVertecies() const;

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. The tuple details the position of the top left corner of the object
	 * inherited from the IEntity class.
	 * No modifications are made to member variables.
	 * \return std::tuple<float,float>
	 */
	const two_floats getTopLeft() const;

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. The tuple details the position of the top right corner of the object
	 * inherited from the IEntity class.
	 * No modifications are made to member variables.
	 * \return std::tuple<float,float>
	 */
	const two_floats getTopRight() const;

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. The tuple details the position of the bottom left corner of the object
	 * inherited from the IEntity class.
	 * No modifications are made to member variables.
	 * \return std::tuple<float,float>
	 */
	const two_floats getBottomLeft() const;

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. The tuple details the position of the bottom right corner of the object
	 * inherited from the IEntity class.
	 * No modifications are made to member variables.
	 * \return std::tuple<float,float>
	 */
	const two_floats getBottomRight() const;

private:
	double x_centre_;
	double y_centre_;
	double x_length_from_centre_;
	double y_length_from_centre_;
	two_floats top_left_;
	two_floats top_right_;
	two_floats bottom_left_;
	two_floats bottom_right_;
	void calculateVertecies();


};

#endif
