#ifndef SCORE_H_
#define SCORE_H_
#include <ScreenState.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <memory>
#include "Constants.h"
using text_ptr = std::shared_ptr<sf::Text>;

/** \class Score
 * \brief This class is responsible for managing how the player's score
 * is displayed on the render window. It is encapsulated within the Presentation class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Score
{
public:
	Score();
	void setScore(const int & score);
	text_ptr getScore(ScreenState screen_state);
	text_ptr getHighScore(ScreenState screen_state);
private:
	int high_score_;
	int current_score_;
	text_ptr score_ptr_;
	text_ptr high_score_ptr_;
	sf::Font score_font_;
	void saveScore();
	void loadHighScore();
	void initializeText();
	void setSplashPosition();
	void setGamePosition();
	void setFinalHighScorePosition();
	void setFinalScorePosition();
	void setFont();
	void setColour();
	void setScore();
	void setHighScore();
};

#endif
