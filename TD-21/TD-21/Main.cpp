#include "Vector.h"
#include "Exception.h"

int main()
{	
	Vector2<float> test_vector(100, 100);

	//Try to divide a vector2 by 0.f.
	try
	{
		test_vector / 0.f;
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	Exception::Create_error(1, "Random Error");

	//Now you can create your own error with a number affiliate to it 
	try
	{
		throw Exception(1);
	}
	catch (const Exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}