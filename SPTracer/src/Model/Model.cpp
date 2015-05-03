#include "../Intersection.h"
#include "../Ray.h"
#include "Model.h"

namespace SPTracer
{
	Model::Model()
	{
	}

	Model::~Model()
	{
	}

	bool Model::Intersect(const Ray& ray, Intersection& intersection) const
	{
		bool found = false;
		Intersection current;
		for (const auto& o : objects_)
		{
			bool success = o->Intersect(ray, current);
			if (success && (!found || (current.distance < intersection.distance)))
			{
				found = true;
				intersection = current;
				intersection.object = o;
			}
		}

		return found;
	}

}
