#include "GUI.h"

GUI::GUI(void)
{
	name = "GUI";
	width = 10;
	height = 10;

	sf::Font font;
	font.loadFromFile("font.ttf");
	text.setFont(font);
	text.setString("Hello");
	text.setCharacterSize(25);

	int blocks = 360 / (int)(height*2) * 4;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(blocks);

	float pos = 25;
	for(int i = 0; i < blocks-3; i += 4) {
		m_vertices[i] = sf::Vector2f(0, pos);
		m_vertices[i+1] = sf::Vector2f(width, pos);
		m_vertices[i+2] = sf::Vector2f(width, pos+height);
		m_vertices[i+3] = sf::Vector2f(0, pos+height);
		pos += height*2;
	}
}


void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	//target.draw(text, states);
	target.draw(m_vertices, states);
}

GUI::~GUI(void)
{
}
