/* Brandon Gallagher
*  08/20/2025
* 
*  This program was created to help practice std::move and lock it into memory.
* 
*/

#include "Resource.h"
#include <vector>
#include <utility>

int main()
{
	Resource a(10);
	a.Fill(7);

	// Copy (expensive)
	Resource b = a;

	// Move (cheap)
	Resource c = std::move(a); // a is now "moved-from"; don't rely on its contents

	std::vector<Resource> v;
	v.reserve(3);
	v.push_back(Resource(100));
	Resource big(1000);
	v.push_back(std::move(big));
	v.emplace_back(200);

	return 0;
}