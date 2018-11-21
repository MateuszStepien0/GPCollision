#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Clock.hpp>
#include <vector>
#include <Debug.h>

using namespace std;
using namespace sf;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(const Texture&);
	AnimatedSprite(const Texture&, const IntRect&);
	~AnimatedSprite();

	void addFrame(IntRect&);
	const sf::IntRect getCurrentFrame();
	void setFrameRow(int frameRow);
	void setFrameCol(int frameCol);
	void update();
	void setCurrentFrame();

private:
	Clock m_clock;
	Time m_time;
	vector<IntRect> m_frames;
	sf::IntRect m_current_frame;
	int m_current_frame_row;
	int m_current_frame_col;
};

#endif // !ANIMATED_SPRITE_H
