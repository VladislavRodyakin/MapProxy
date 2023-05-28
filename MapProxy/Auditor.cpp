#include "auditor.hpp"

const bool AllRoots::isEdit(const std::string& key)const{
	return true;
}

const bool AllRoots::isRead(const std::string& key)const{
	return true;
}

const bool OnlyEditRoots::isEdit(const std::string& key)const{
	return true;
}

const bool OnlyEditRoots::isRead(const std::string& key)const{
	return false;
}

const bool OnlyReadRoots::isEdit(const std::string& key)const{
	return false;
}

const bool OnlyReadRoots::isRead(const std::string& key)const{
	return true;
}