#include <stdint.h>
#include "vertex.h"

const uint32_t tet_vcount = 4;  // vertices count
const uint32_t tet_icount = 12; // sides count

const vertex tet_vertices[tet_vcount] = {
	{ -0.50, -0.50, 0.50 },
	{ 0.50, -0.50, -0.50 },
	{ 0.50, 0.50, 0.50 },
	{ -0.50, 0.50, -0.50 }
};

const uint32_t tet_indices[tet_icount] = {
	1, 3, 2,
	1, 4, 3,
	3, 4, 2,
	4, 1, 2
};