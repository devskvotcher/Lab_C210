#pragma once
template <typename T>
void print_container_impl(const std::stack<T>& container)
{
	std::stack<T> temp_container = container;
	while (!temp_container.empty())
	{
		std::cout << temp_container.top() << ' ';
		temp_container.pop();
	}
	std::cout << '\n';
}

template <typename C>
void print_adapter(C temp_container)
{
	while (!temp_container.empty())
	{
		std::cout << temp_container.top() << ' ';
		temp_container.pop();
	}
	std::cout << '\n';
}

template <typename T,typename C>
void print_adapter(std::queue<T,C> temp_container)
{
	while (!temp_container.empty())
	{
		std::cout << temp_container.front() << ' ';
		temp_container.pop();
	}
	std::cout << '\n';
}


template <typename T>
void print_container_impl(const T& container)
{
	for (const auto& element : container)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

template <typename Container>
void print_container(const Container& container)
{
	if (std::is_same<typename std::decay<Container>::type, std::stack<typename Container::value_type>>::value)
	{
		print_container_impl(container);
	}
	else
	{
		print_container_impl(container);
	}
}