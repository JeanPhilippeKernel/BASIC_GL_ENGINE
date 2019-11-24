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
			float x, y, z;
			
			while (!input_stream.eof())
			{
				std::string line;
				std::getline(input_stream, line);

				if (line.substr(0, 2) == "v ")
				{
					std::stringstream ss(line.substr(3));
					ss >> x >> y >> z;
					m_positions.push_back({ x, y, z });
				}
				else if(line.substr(0, 3) == "vt ")
				{
					std::stringstream ss(line.substr(3));
					ss >> x >> y >> z;
					m_textures.push_back({ x, y, z });
				}
				else if(line.substr(0, 3) == "vn ") 
				{
					std::stringstream ss(line.substr(3));
					ss >> x >> y >> z;
					m_normals.push_back({ x, y, z });
				}

				else if (line.substr(0, 2) == "f ")
				{
					int pos_one, tex_one, norm_one,
						pos_two, tex_two, norm_two,
						pos_three, tex_three, norm_three;

					std::stringstream ss(line.substr(2));
					sscanf_s(
						ss.rdbuf()->str().c_str(), 
						"%d/%d/%d %d/%d/%d %d/%d/%d", 
						&pos_one, &tex_one, &norm_one, &pos_two, 
						&tex_two, &norm_two, &pos_three, 
						&tex_three, &norm_three);

					m_vertices.push_back({
						m_positions.at(pos_one -1),
						Vector3f(1.0f, .0f, .0f),
						m_textures.at(tex_one - 1)
					});

					m_vertices.push_back({
						m_positions.at(pos_two - 1),
						Vector3f(0.0f, 1.0f, .0f),
						m_textures.at(tex_two - 1)
					});

					m_vertices.push_back({
						m_positions.at(pos_three - 1),
						Vector3f(0.0f, .0f, 1.0f),
						m_textures.at(tex_three - 1)
					});
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

const std::vector<Vertex>& ObjParser::ToVertices() const
{
	return m_vertices;
}
