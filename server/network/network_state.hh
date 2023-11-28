#pragma once

enum NetworkState
{
	UNKNOWN = -1,
	HANDSHAKING,
	STATUS,
	LOGIN,
	CONFIGURATION,
	PLAY
};
