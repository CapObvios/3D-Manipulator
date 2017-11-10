#include <stdint.h>
#include "vertex.h"

const uint32_t cub_vcount = 8;  // vertices count
const uint32_t cub_icount = 36; // sides count

const vertex cub_vertices[cub_vcount] = {
	{-0.5, 0.5, - 0.5},
	{- 0.5, 0.5, 0.5},
	{0.5, 0.5, 0.5	},
	{0.5, 0.5, - 0.5},
	{- 0.5, - 0.5, - 0.5},
	{- 0.5, - 0.5, 0.5 },
	{0.5, - 0.5, 0.5},
	{0.5, - 0.5, - 0.5}
};

const uint32_t cub_indices[cub_icount] = {
	8, 7, 6,
	8, 6, 5,
	8, 4, 3,
	8, 3, 7,
	6, 2, 1,
	6, 1, 5,
	5, 1, 4,
	5, 4, 8,
	7, 3, 2,
	7, 2, 6,
	3, 4, 1,
	3, 1, 2
};






