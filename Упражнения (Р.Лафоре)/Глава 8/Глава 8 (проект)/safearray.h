#pragma once

class safearray
{
	private:
		static const int LIMIT = 100;
		unsigned int min_index, max_index;
		int arr[LIMIT];
	public:
		// обратите внимание, что функция возвращает ссылку!
		safearray();
		safearray(unsigned int, unsigned int);
		int& operator[](unsigned int);
		void array_init();
};

