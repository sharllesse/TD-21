#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TD20UnitTest
{
	TEST_CLASS(TD20UnitTest)
	{
	public:
		
		TEST_METHOD(VectorNormalizeTest)
		{
			Vector2<float> tested_vector(100.f, 100.f); //The value that we want to test.
			Vector2<float> expected_vector(0.71f, 0.71f); //And the value that the tested value will be at the end. (if its work.)
			float delta(0.01f); //Delta is the margin that we got.

			tested_vector.normalize();

			Assert::AreEqual(expected_vector.x, tested_vector.x, delta, L"the value is not the same.");
			Assert::AreEqual(expected_vector.y, tested_vector.y, delta, L"the value is not the same.");
		}
		TEST_METHOD(VectorDotProductTest)
		{
			Vector2<float> first_tested_vector(100.f, 100.f); //The value that we want to test.
			Vector2<float> second_tested_vector(200.f, 200.f); //The value that we want to test.
			float expected_dot_product(40000.f); //And the value that the tested value will be at the end. (if its work.)
			float delta(0.01f); //Delta is the margin that we got.

			Assert::AreEqual(expected_dot_product, first_tested_vector.dotProduct(second_tested_vector), delta, L"the value is not the same.");
		}
		TEST_METHOD(VectorGetNormeTest)
		{
			Vector2<float> tested_vector(100.f, 100.f); //The value that we want to test.
			float expected_norme(141.42f); //And the value that the tested value will be at the end. (if its work.)
			float delta(0.01f); //Delta is the margin that we got.

			Assert::AreEqual(expected_norme, tested_vector.getNorme(), delta, L"the value is not the same.");
		}
		TEST_METHOD(VectorGetAngleTest)
		{
			Vector2<float> first_tested_vector(100.f, 100.f); //The value that we want to test.
			Vector2<float> second_tested_vector(100.f, 200.f); //The value that we want to test.
			float expected_angle(18.435f); //And the value that the tested value will be at the end. (if its work.)
			float delta(0.01f); //Delta is the margin that we got.

			Assert::AreEqual(expected_angle, first_tested_vector.getAngle(second_tested_vector), delta, L"the value is not the same.");
		}
		TEST_METHOD(VectorGetDistanceTest)
		{
			Vector2<float> first_tested_vector(100.f, 100.f); //The value that we want to test.
			Vector2<float> second_tested_vector(200.f, 200.f); //The value that we want to test.
			float expected_distance(141.421f); //And the value that the tested value will be at the end. (if its work.)
			float delta(0.01f); //Delta is the margin that we got.

			Assert::AreEqual(expected_distance, first_tested_vector.getDistance(second_tested_vector), delta, L"the value is not the same.");
		}
	};
}
