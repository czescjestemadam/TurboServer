#include "text_hover_event.hh"

TextHoverEvent::TextHoverEvent(std::string text) : text(std::move(text))
{
}

std::string TextHoverEvent::getAction()
{
	return "show_text";
}

std::string TextHoverEvent::getContents()
{
	return text;
}
