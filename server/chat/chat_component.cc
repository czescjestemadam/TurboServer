#include "chat_component.hh"

std::string ChatComponent::toString() const
{
	return json().dump();
}

#define JB(var) if (var) j[#var] = var

nlohmann::json ChatComponent::baseJson() const
{
	nlohmann::json j;
	JB(bold);
	JB(italic);
	JB(underline);
	JB(strikethrough);
	JB(obfuscated);

	if (font)
		j["font"] = font->getIdentifier();

	if (color)
		j["color"] = color->getName();

	if (!insertion.empty())
		j["insertion"] = insertion;

	if (clickEvent.getAction())
		j["clickEvent"] = { clickEvent.getAction()->getName(), clickEvent.getValue() };

	if (hoverEvent)
		j["hoverEvent"] = { hoverEvent->getAction(), hoverEvent->getContents() };

	for (const std::unique_ptr<ChatComponent>& c : extra)
		j["extra"].push_back(c->json());

	return j;
}
