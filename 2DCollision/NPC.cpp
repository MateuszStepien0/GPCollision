#include <iostream>
#include <NPC.h>
#include <Idle.h>
#include <Debug.h>

NPC::NPC() : GameObject()
{
	m_player_fsm.setCurrent(new Idle());
	m_player_fsm.setPrevious(new Idle());
}

NPC::NPC(const AnimatedSprite& s) : GameObject(s)
{
	m_player_fsm.setCurrent(new Idle());
	m_player_fsm.setPrevious(new Idle());
}

NPC::~NPC()
{
}

AnimatedSprite& NPC::getAnimatedSprite()
{
	m_animated_sprite.setTextureRect(m_animated_sprite.getCurrentFrame());
	return m_animated_sprite;
}

void NPC::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::SQUARE:
		m_animated_sprite.setFrameRow(0);
		break;
	case Input::Action::CIRCLE:
		m_animated_sprite.setFrameRow(1);
		break;
	case Input::Action::POLY:
		m_animated_sprite.setFrameRow(2);
		break;
	case Input::Action::CAPSULE:
		m_animated_sprite.setFrameRow(3);
		break;
	default:
		break;
	}
}

void NPC::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}