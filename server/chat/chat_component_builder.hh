#pragma once
#include "text_chat_component.hh"
#include "keybind_chat_component.hh"
#include "translation_chat_component.hh"
#include "score_chat_component.hh"

template<class T, class Arg>
class ChatComponentBuilder
{
	static_assert(std::is_base_of<ChatComponent, T>::value, "T is not derived from ChatComponent");

	std::unique_ptr<ChatComponent> cmp;
public:
	explicit ChatComponentBuilder(Arg arg) : cmp(std::make_unique<T>(arg))
	{
	}

	ChatComponentBuilder<T, Arg>& bold(bool b = true)
	{
		cmp->bold = b;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& italic(bool b = true)
	{
		cmp->italic = b;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& underline(bool b = true)
	{
		cmp->underline = b;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& strikethrough(bool b = true)
	{
		cmp->strikethrough = b;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& obfuscated(bool b = true)
	{
		cmp->obfuscated = b;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& font(ChatFont* font)
	{
		cmp->font = font;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& color(ChatFormat* color)
	{
		cmp->color = color;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& insertion(const std::string& insertion)
	{
		cmp->insertion = insertion;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& click(const ClickEvent& clickEvent)
	{
		cmp->clickEvent = clickEvent;
		return *this;
	}

	ChatComponentBuilder<T, Arg>& hover(std::unique_ptr<HoverEvent>&& hoverEvent)
	{
		cmp->hoverEvent = std::move(hoverEvent);
		return *this;
	}

	ChatComponentBuilder<T, Arg>& extra(std::unique_ptr<ChatComponent>&& extra)
	{
		cmp->extra.push_back(std::move(extra));
		return *this;
	}

	std::unique_ptr<ChatComponent> build()
	{
		return std::move(cmp);
	}
};
