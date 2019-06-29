#pragma once

class non_copyable {
	void operator = (const non_copyable&) = delete;
	non_copyable(const non_copyable&) = delete;
public:
	non_copyable() = default;
	~non_copyable() = default;
};