#pragma once

#include <future>
#include <algorithm>

namespace own {
	template<class It, class Foo, size_t size = 100>
	Foo for_each(It begin, It end, Foo f) 
	{
		auto curr_size = std::distance(begin, end);
		if (curr_size <= size) 
		{
			auto res = std::for_each(begin, end, f);
			return res;
		}

		auto mid = begin;
		std::advance(mid, curr_size / 2);
		
	    auto ft = std::async(own::for_each<It, Foo>, begin, mid, f);
		auto local = own::for_each(mid, end, f);

		return ft.get();
	}
}