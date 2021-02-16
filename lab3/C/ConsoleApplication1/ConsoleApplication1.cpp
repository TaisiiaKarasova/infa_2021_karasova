void print_array(int* p)
{
	for (int j = 0; j < 6; j++)
	{
		std::cout << *(p + j) << ' ';
	}
}