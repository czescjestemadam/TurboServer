#include "png.hh"

#include <fstream>
#include <iterator>

void Png::load(const std::filesystem::path& file)
{
	std::ifstream ifs(file);
	if (!ifs.good())
		return;

	ifs.seekg(0, std::ios::end);
	const long len = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	byte_t bs[len];
	ifs.read((char*)bs, len);
	bytes = { bs, bs + len };

	if (!isValid())
		return;

	int idx = 16;
	width = bytes[idx++] << 24 | bytes[idx++] << 16 | bytes[idx++] << 8 | bytes[idx++];
	height = bytes[idx++] << 24 | bytes[idx++] << 16 | bytes[idx++] << 8 | bytes[idx++];
}

bool Png::isValid() const
{
	if (bytes.size() <= 12)
		return false;

	// starting signature
	return bytes[0] == 137 && bytes[1] == 80 && bytes[2] == 78 && bytes[3] == 71 &&
	       bytes[4] == 13 && bytes[5] == 10 && bytes[6] == 26 && bytes[7] == 10;
}
