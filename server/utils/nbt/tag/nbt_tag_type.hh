#pragma once

enum NbtTagType
{
	UNKNOWN_TAG = -1,

	END = 0,
	BYTE = 1,
	SHORT = 2,
	INT = 3,
	LONG = 4,
	FLOAT = 5,
	DOUBLE = 6,
	BYTE_ARRAY = 7,
	STRING = 8,
	LIST = 9,
	COMPOUND = 0x0a,
	INT_ARRAY = 0x0b,
	LONG_ARRAY = 0x0c
};
