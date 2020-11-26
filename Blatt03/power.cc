namespace power
{
	//a
	/**
	* @brief: calculates q to the nth power iteratively
	*
	* @param: int q
	*       : int n
	*
	* @return: int
	*/
	int iterative(int q, int n)
	{
		int r{ 1 };
		for (int i = 0; i < n; ++i) {
			r *= q;
		}
		return r;
	}

	//b, c
	/**
	* @brief: calculates q to the nth power recursively
	*
	* @param: int q
	*       : int n
	*
	* @return: int
	*/
	double recursive(double q, int n)
	{
		if (n) {
			double tmp{ recursive(q, n / 2) };
			return (n % 2 ? q : 1) * tmp * tmp;
		}
		return 1;
	}
} //end namespace power

