#pragma once

enum NetworkState
{
	UNKNOWN_STATE = -1,
	HANDSHAKING,
	STATUS,
	LOGIN,
	CONFIGURATION,
	PLAY
};
