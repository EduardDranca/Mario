#pragma once

template <typename T>
void clamp(T lowerValue, T higherValue, T & toClamp)
{
	if (toClamp < lowerValue)
	{
		toClamp = lowerValue;
	}
	else if (toClamp > higherValue)
	{
		toClamp = higherValue;
	}
}