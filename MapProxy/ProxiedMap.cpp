#include "ProxiedMap.hpp"
#include <stdexcept>
#include "auditor.hpp"
ProxiedMap::ProxiedMap(const std::map <std::string, size_t>& DataMap, std::vector<auditor*> Auditors){
	data_.insert(DataMap.begin(), DataMap.end());
	for (auto& item : Auditors)
		objects.push_back(item);
}

void ProxiedMap::edit(const std::string& name, const std::string& key, size_t value){
	for (auto& item : objects)
		if (item->GetName() == name)
			if (!item->isEdit(key))
				throw std::runtime_error("No roots");
	if (data_.find(key) == data_.end())
		throw std::runtime_error("No such key");
	data_.at(key) = value;
}

const size_t ProxiedMap::read(const std::string& name, const std::string& key) const{
	for (auto& item : objects)
		if (item->GetName() == name)
			if (!item->isRead(key))
				throw std::runtime_error("No roots");
	if (data_.find(key) == data_.end())
		throw std::runtime_error("No such key");
	size_t result = data_.at(key);
	return result;
}

void ProxiedMap::Add(const std::string& name, const std::string& key, size_t value){
	for (auto& item : objects)
		if (item->GetName() == name)
			if (!item->isEdit(key))
				throw std::runtime_error("No roots");
	data_.insert({ key, value });
}

void ProxiedMap::Delete(const std::string& name, const std::string& key){
	for (auto& item : objects)
		if (item->GetName() == name)
			if (!item->isEdit(key))
				throw std::runtime_error("No roots");
	data_.erase(key);
}