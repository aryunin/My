#pragma once

class safearray
{
	private:
		static const int LIMIT = 100;
		unsigned int min_index, max_index;
		int arr[LIMIT];
	public:
		// �������� ��������, ��� ������� ���������� ������!
		safearray();
		safearray(unsigned int, unsigned int);
		int& operator[](unsigned int);
		void array_init();
};

