#include <stdint.h>
#include "vertex.h"

const uint32_t cub_vcount = 4;  // vertices count
const uint32_t cub_cubunt = 12; // sides count

const vertex cub_vertices[cub_vcount] = {
	{ -0.50, -0.50, 0.50 },
	{ 0.50, -0.50, -0.50 },
	{ 0.50, 0.50, 0.50 },
	{ -0.50, 0.50, -0.50 }
};

const uint32_t cub_indices[cub_cubunt] = {
	2, 4, 3,
	4, 2, 1,
	3, 1, 2,
	1, 3, 4
};