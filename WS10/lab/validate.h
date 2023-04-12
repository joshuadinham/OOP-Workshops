/*
Joshua Dinham
121572226
BTP200NAA
All work completed by me
*/
namespace sict
{

	template<typename T, typename U, typename V>
	bool validate(const T& min, const T* values, const V numOfElements,  U* boolValues) 
	{
		bool valid = true;
		for (int i = 0; i < numOfElements; i++)
		{
			boolValues[i] = values[i] >= min;
			if (boolValues[i] == false)
			{
				valid = false;
			}

		}
		return valid;
	}
}
