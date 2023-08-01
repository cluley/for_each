#pragma once

#include <future>

namespace own {
	template<class It, class Foo, size_t size = 100>
	Foo for_each(It begin, It end, Foo f) 
	{
		auto curr_size = std::distance(begin, end);
		if (curr_size <= size) 
		{
			for (; begin != end; ++begin) {
				f(*begin);
			}
			return f;
		}

		auto mid = begin;
		std::advance(mid, curr_size / 2);
		
	    std::future<Foo> ft_L = std::async(own::for_each<It, Foo>, begin, mid, f);
		std::future<Foo> ft_R = std::async(own::for_each<It, Foo>, mid, end, f);

		return ft_L.get();
	}
}