#pragma once
#include<map>
#include<string>
#include<vector>
#include "auditor.hpp"

class ProxiedMap final {
public:
	ProxiedMap() = default;
	ProxiedMap(const std::map <std::string, size_t>& DataMap, std::vector<auditor*> Auditors);
	void edit(const std::string&, const std::string& key, size_t value);
	const size_t read(const std::string&, const std::string& key) const;
	void Add(const std::string&, const std::string& key, size_t value);
	void Delete(const std::string&, const std::string& key);
private:
	std::map<std::string, size_t> data_;
	std::vector<auditor*> objects;
};