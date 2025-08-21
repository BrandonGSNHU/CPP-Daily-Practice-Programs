#pragma once
#include <cstddef>
#include <algorithm>
#include <iostream>

class Resource
{
public:
	explicit Resource(std::size_t n)
		: size_(n), data_(n ? new int[n] : nullptr)
	{
		std::fill_n(data_, size_, 0);
		std::cout << "ctor(" << size_ << ")\n";
	}

	~Resource()
	{
		delete[] data_;
		std::cout << "dtor(" << size_ << ")\n";
	}

	// Copy ctor
	Resource(const Resource& other)
		: size_(other.size_), data_(other.size_ ? new int[other.size_] : nullptr)
	{
		std::copy(other.data_, other.data_ + size_, data_);
		std::cout << "copy-ctor(" << size_ << ")\n";
	}

	// Copy assign
	Resource& operator=(const Resource& other)
	{
		if (this == &other) return *this;
		Resource tmp(other);
		swap(tmp);
		std::cout << "copy-assign(" << size_ << ")\n";
		return *this;
	}

	// Move ctor
	Resource(Resource&& other) noexcept
		: size_(other.size_), data_(other.data_)
	{
		other.size_ = 0;
		other.data_ = nullptr;
		std::cout << "move-ctor(" << size_ << ")\n";
	}

	// Move assign
	Resource& operator=(Resource&& other) noexcept
	{
		if (this == &other) return *this;
		delete[] data_;
		size_ = other.size_;
		data_ = other.data_;
		other.size_ = 0;
		other.data_ = nullptr;
		std::cout << "move-assign(" << size_ << ")\n";
		return *this;
	}

	void Fill(int v)
	{
		std::fill_n(data_, size_, v);
	}

	std::size_t Size() const noexcept { return size_; }

private:
	void swap(Resource& rhs) noexcept
	{
		std::swap(size_, rhs.size_);
		std::swap(data_, rhs.data_);
	}

	std::size_t size_{ 0 };
	int* data_{ nullptr };
};