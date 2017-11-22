#pragma once

#include <Windows.h>

#include "cube.h"
#include "dodecahedron.h"
#include "icosahedron.h"
#include "octahedron.h"
#include "tetrahedron.h"
#include "sphere.h"
#include "torus.hpp"

namespace Types {

	using namespace System::Collections::Generic;

	enum coordType
	{
		X = 0, Y = 1, Z = 2
	};

	enum permutationType
	{
		Move,
		Rotate,
		RotateGlobal,
		Resize
	};

	enum objectType
	{
		Tet,
		Cub,
		Dod,
		Ico,
		Oct,
		Sph,
		Tor
	};

	ref class Point3D
	{
	public:
		float X, Y, Z;

		Point3D() : X(0), Y(0), Z(0) { }
		Point3D(float x, float y, float z) : X(x), Y(y), Z(z) { }
		Point3D(array<float,1>^ p) : X(p[0]), Y(p[1]), Z(p[2]) { }
		Point3D(Point3D^ p) : X(p->X), Y(p->Y), Z(p->Z) { }
		Point3D(Point3D% p) : X(p.X), Y(p.Y), Z(p.Z) { }

		Point3D% operator= (Point3D^ right)
		{
			if (this == right)
				return *this;

			X = right->X;
			Y = right->Y;
			Z = right->Z;

			return *this;
		}

		Point3D% operator+(Point3D^ right)
		{
			return Point3D(right->X + this->X, right->Y + this->Y, right->Z + this->Z);
		}

		Point3D% operator/(float divisor)
		{
			return Point3D(this->X / divisor, this->Y / divisor, this->Z / divisor);
		}

		array<float>^ GetVector()
		{
			return gcnew array<float>(3) { X, Y, Z };
		}
	};

	ref class Polygon
	{
	public:
		Point3D K, L, M;

		Polygon() : K(), L(), M() { }
		Polygon(Point3D^ k, Point3D^ l, Point3D^ m)
		{
			K = k;
			L = l;
			M = m;
		}

		array<array<float>^>^ getMatrix()
		{
			auto res = gcnew array<array<float>^>(3);

			res[0] = K.GetVector();
			res[1] = L.GetVector();
			res[2] = M.GetVector();

			return res;
		}
	};

	ref class GeometryObj
	{
	public:
		List<Polygon^>^ Polygons;		

		List<array<array<float>^>^>^ getMatrices(objectType type)
		{
			const int SizeFactor = 100;
			const vertex* vertices = dod_vertices;
			const uint32_t* vertex_indices = dod_indices;

			int vertexCount = dod_vcount;
			int vertexICount = dod_icount;
			

			switch (type)
			{
			case Types::Tet:
				vertices = tet_vertices;
				vertex_indices = tet_indices;
				vertexCount = tet_vcount;
				vertexICount = tet_icount;
				break;
			case Types::Cub:
				vertices = cub_vertices;
				vertex_indices = cub_indices;
				vertexCount = cub_vcount;
				vertexICount = cub_icount;
				break;
			case Types::Dod:
				vertices = dod_vertices;
				vertex_indices = dod_indices;
				vertexCount = dod_vcount;
				vertexICount = dod_icount;
				break;
			case Types::Ico:
				vertices = ico_vertices;
				vertex_indices = ico_indices;
				vertexCount = ico_vcount;
				vertexICount = ico_icount;
				break;
			case Types::Oct:
				vertices = oct_vertices;
				vertex_indices = oct_indices;
				vertexCount = oct_vcount;
				vertexICount = oct_icount;
				break;
			case Types::Sph:
				vertices = sph_vertices;
				vertex_indices = sph_indices;
				vertexCount = sph_vcount;
				vertexICount = sph_icount;
				break;
			case Types::Tor:
				vertices = tor_vertices;
				vertex_indices = tor_indices;
				vertexCount = tor_vcount;
				vertexICount = tor_icount;
				break;
			default:
				break;
			}

			auto res = gcnew List<array<array<float>^>^>(vertexCount);

			for (size_t i = 0; i < vertexICount; i+=3)
			{
				array<array<float>^>^ poly = gcnew array<array<float>^>(3);
				for (size_t j = 0;  j < 3;  j++)
				{
					// numeration of sphere and torus vertex indices starts from 0, meanwhile all the other figures (decompiled from .obj type) start from 1
					// ideally later they have to be lead to the same type, but just for now I did this quickfix due to the lack of time.
					auto ver = vertices[vertex_indices[i + j] - (type == objectType::Sph || type == objectType::Tor ? 0 : 1) ].coords; 
					poly[j] = gcnew array<float>(3) { ver[0]*SizeFactor, ver[1]*SizeFactor, ver[2] * SizeFactor };
				}
				res->Add(poly);
			}			
			/*for each (auto pol in Polygons)
			{
				res->Add(pol->getMatrix());
			}*/
			return res;
		}
	};	

	ref class PlaneEquation
	{
	public:
		PlaneEquation(Point3D^ A, Point3D^ B, Point3D^ C)
		{
			X = (B->Y - A->Y)*(C->Z - A->Z) - (B->Z - A->Z)*(C->Y - A->Y);
			Y = -(B->X - A->X)*(C->Z - A->Z) + (B->Z - A->Z)*(C->X - A->X);
			Z = (B->X - A->X)*(C->Y - A->Y) - (B->Y - A->Y)*(C->X - A->X);
			D = -A->X*X - A->Y*Y - A->Z*Z;
			/*while ((int)X % 10 == 0 && (int)Y % 10 == 0 && (int)Z % 10 == 0 && (int)D % 10 == 0)
			{
				X /=10;
				Y /=10;
				Z /=10;
				D /=10;
			}*/
		};

		double X, Y, Z, D;

		float GetZCoord(System::Drawing::Point p)
		{
			return (-D - X*p.X - Y*p.Y) / Z;
		}
	};
}