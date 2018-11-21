#include <AnimatedSprite.h>


AnimatedSprite::AnimatedSprite()
{
	m_current_frame_row = 0;
	m_current_frame_col = 0;
	setCurrentFrame();
}

AnimatedSprite::AnimatedSprite(const sf::Texture& t) : Sprite(t), m_time(seconds(0.5f)) {}

AnimatedSprite::AnimatedSprite(const sf::Texture& t, const sf::IntRect& rect) : Sprite(t), m_time(seconds(0.5f))
{
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}

void AnimatedSprite::addFrame(IntRect& frame)
{
	m_frames.push_back(frame);
}

const sf::IntRect AnimatedSprite::getCurrentFrame()
{
	return m_current_frame;
}

void AnimatedSprite::setFrameRow(int frameRow)
{
	m_current_frame_row = frameRow;
}

void AnimatedSprite::setFrameCol(int frameCol)
{
	m_current_frame_col = frameCol;
}

void AnimatedSprite::update()
{
	if (m_clock.getElapsedTime() > m_time)
	{
		if (m_current_frame_col > 4)
		{
			m_current_frame_col = 0;
		}
		else
		{
			m_current_frame_col++;
		}
		setCurrentFrame();
		m_clock.restart();
	}
}

void AnimatedSprite::setCurrentFrame()
{
	m_current_frame = sf::IntRect(3 + (85 * m_current_frame_col), 3 + (85 * m_current_frame_row), 84, 84);
}
