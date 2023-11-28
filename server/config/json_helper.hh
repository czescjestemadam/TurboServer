#pragma once
#define JSON_HELPER_READ(var) if (j.contains(#var)) var = j[#var];
#define JSON_HELPER_WRITE(var) j[#var] = var;
