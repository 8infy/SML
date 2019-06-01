#pragma once

#include "vec4.h"

namespace sml {

	class mat4
	{
	public:
		union
		{
			float elements[16];

			struct
			{
				vec4 rows[4];
			};
		};
	public:
		
		mat4() = default;

		vec4& operator[](int row)
		{
			return rows[row];
		}

		float* data()
		{
			return &elements[0];
		}
	};
}