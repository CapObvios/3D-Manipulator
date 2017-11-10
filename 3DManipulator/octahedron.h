#include <stdint.h>
#include "vertex.h"

const uint32_t oct_vcount = 6;  // vertices count
const uint32_t oct_icount = 24; // sides count

const vertex oct_vertices[oct_vcount] = {
	{1,  0 , 0 },
	{0, - 1,  0},
	{1,  0 , 0 },
	{0,  1 , 0 },
	{0,  0 , 1 },
	{0,  0 ,- 1}
};

const uint32_t oct_indices[oct_icount] = {
	2,  1,  5,
	3,  2,  5,
	4,  3,  5,
	1,  4,  5,
	1,  2,  6,
	2,  3,  6,
	3,  4,  6,
	4,  1,  6,
};