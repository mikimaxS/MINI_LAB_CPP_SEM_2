#pragma once


template<typename InputIt, typename UnaryFunction>
UnaryFunction my_for_each(InputIt first, InputIt last, UnaryFunction f);

template<typename InputIt, typename T, typename BinaryOperation>
T my_accumulate(InputIt first, InputIt last, T init, BinaryOperation op);

template<typename InputIt, typename OutputIt, typename UnaryOperation>
OutputIt my_transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation op);

template<typename InputIt, typename UnaryPredicate>
InputIt my_find_if(InputIt first, InputIt last, UnaryPredicate p);

//-----------------------------------------------------------------------------
//przyk³adowe mo¿liwe implementacje (w podobnym stylu, jak w STL - tutaj bez move)

template<typename InputIt, typename UnaryFunction>
UnaryFunction my_for_each(InputIt first, InputIt last, UnaryFunction f)
{
	for ( ; first != last; ++first) 
	{
		f(*first);
	}
	return f;
}


template<typename InputIt, typename T, typename BinaryOperation>
T my_accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
{
	for (; first != last; ++first)
	{
		init = op(init, *first);
	}
	return init;
}

template<typename InputIt, typename OutputIt, typename UnaryOperation>
OutputIt my_transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation op)
{
	while (first1 != last1) 
	{
		*d_first++ = op(*first1++);
	}
	return d_first;
}

template<typename InputIt, typename UnaryPredicate>
InputIt my_find_if(InputIt first, InputIt last, UnaryPredicate p)
{
	for (; first != last; ++first) {
		if (p(*first)) {
			return first;
		}
	}
	return last;
}

