#include "pch.h"
#include "CppUnitTest.h"
#include <vector>

#include"../duplicate_zeros/duplicate_zero.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<std::vector<int>>(const std::vector<int> &v) { return L"vector"; }
		}
	}
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> v{ 8,4,5,0,0,0,0,7 };
			std::vector<int> v_result{ 8,4,5,0,0,0,0,0 };
			duplicateZeros(v);
			Assert::AreEqual(v, v_result);
		}
	};
}
