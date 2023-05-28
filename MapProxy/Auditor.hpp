#pragma once
#include <string>

class auditor {
public:
	const virtual bool isEdit(const std::string& key) const = 0;
	const virtual bool isRead(const std::string& key)const = 0;
	const virtual std::string GetName()const = 0;

protected:
	std::string name;
};

class AllRoots final : public auditor {
public:
	AllRoots() { name = "ALL"; }
	const bool isEdit(const std::string& key)const override;
	const bool isRead(const std::string& key)const override;
	const std::string GetName()const override { return name; };
};

class OnlyEditRoots final : public auditor {
public:
	OnlyEditRoots() { name = "EDIT"; }
	const bool isEdit(const std::string& key)const override;
	const bool isRead(const std::string& key)const override;
	const std::string GetName()const override { return name; };
};

class OnlyReadRoots final : public auditor {
public:
	OnlyReadRoots() { name = "READ"; }
	const bool isEdit(const std::string& key)const override;
	const bool isRead(const std::string& key)const override;
	const std::string GetName()const override { return name; };
};