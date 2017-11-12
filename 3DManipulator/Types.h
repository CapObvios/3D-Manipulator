#pragma once

#include <Windows.h>

#include "cube.h"
#include "dodecahedron.h"
#include "icosahedron.h"
#include "octahedron.h"
#include "tetrahedron.h"
#include "sphere.h" // sphere

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

	ref class Point3D
	{
	public:
		float X, Y, Z;

		Point3D() : X(0), Y(0), Z(0) { }
		Point3D(float x, float y, float z) : X(x), Y(y), Z(z) { }

		Point3D% operator= (Point3D^ right)
		{
			if (this == right)
				return *this;

			X = right->X;
			Y = right->Y;
			Z = right->Z;

			return *this;
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

	ref class Tetrahedron
	{
	public:
		List<Polygon^>^ Polygons;
		Tetrahedron()
		{
			Polygons = gcnew List<Polygon^>();

			Point3D^ P1 = gcnew Point3D(-50, -50, 50);
			Point3D^ P2 = gcnew Point3D(50, -50, -50);
			Point3D^ P3 = gcnew Point3D(50, 50, 50  );
			Point3D^ P4 = gcnew Point3D(-50, 50, -50);

			Polygons->Add(gcnew Polygon(P1, P3, P2));
			Polygons->Add(gcnew Polygon(P1, P4, P3));
			Polygons->Add(gcnew Polygon(P3, P4, P2));
			Polygons->Add(gcnew Polygon(P4, P1, P2));
		}

		List<array<array<float>^>^>^ getMatrices()
		{
			auto res = gcnew List<array<array<float>^>^>();
			for each (auto pol in Polygons)
			{
				res->Add(pol->getMatrix());
			}
			return res;
		}
	};

	interface class IGeometryObject
	{

	};
}