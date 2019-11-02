#include "ObjParser.h"



ObjParser::ObjParser(const char* filename)
{
	std::ifstream input_stream;
	input_stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		input_stream.open(filename);
		if (input_stream.is_open())
		{
			while (!input_stream.eof())
			{
				std::string line;
				std::getline(input_stream, line);

				if (line.substr(0, 2) == "v ")
				{
					std::stringstream ss(line.substr(3));
					int x, y, z;
					ss >> x >> y >> z;
					m_positions.push_back({ x, y, z });
				}
				else if() 
				{
				
				}
				else if() 
				{
				
				}
			}
		}

		input_stream.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


ObjParser::~ObjParser()
{
}
